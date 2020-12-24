#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//1. open memory card
//2. look for JPEG file
//3. open for new JPEG file
//4. write 512 bytes until new JPEG is found

typedef uint8_t BYTE;


int main(int argc, char *argv[])
{
    //to check for correct arguments
    if (argc !=2)
    {
        printf("Usage: ./recover image");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    int jpg_found = 0;
    int file_count = 0;

    //The next step is to check if the file is opened/exist.
    //The check is to use NULL because if you de-reference a NULL pointer, you'll get segmentation fault
    if (file == NULL)
    {
        printf("Not a file");
    }

    //set buffer with 512 bytes
    BYTE buffer[512];

    // output file. Set to NULL because it's currently empty.
    FILE *output = NULL;
    // set file name
    char file_name[8];


    // Read through entire card until last 512 byte BLOCK - Repeat until end of the card.
    // fread returns number of items of size 512 (sizeof buffer) that were read (end of file may not have 512 bytes so fread won't return 1)
    while(fread(buffer,512,1,file)==1) // data,size,qty,file
    {
        //find 0xff, 0xd8 and 0xff for the first 3 bytes.
        //for buffer[3] condition watch walkthrough video explanation
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (jpg_found==1) // if already opened a prior jpg byte then close it
            {
                fclose(output);
            }
            else //if found new jpg
            {
                jpg_found = 1;
            }

            sprintf(file_name,"%03i.jpg",file_count); // print filename 000.jpg and increasing each time
            output =fopen(file_name,"w"); // open file for images to append/write
            file_count++; // after each file is opened increment file count counter
        }

        if (jpg_found==1)
        {
            fwrite(&buffer, 512, 1, output); //read from address of buffer into the output
        }

    }

    fclose(file); // close file(memory card to buffer) and img(buffer to img file)
    fclose(output);

    // done
    return 0;

}
