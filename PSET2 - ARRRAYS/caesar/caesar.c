//Link to problem: https://cs50.harvard.edu/x/2020/psets/2/caesar/#:~:text=wherein%20%%2026%20here%20means%20“remainder%20when%20dividing%20by%2026.”%20This%20formula%20perhaps%20makes%20the%20cipher%20seem%20more%20complicated%20than%20it%20is,%20but%20it’s%20really%20just%20a%20concise%20way%20of%20expressing%20the%20algorithm%20precisely.%20Indeed,%20for%20the%20sake%20of%20discussion,%20think%20of%20A%20(or%20a)%20as%200,%20B%20(or%20b)%20as%201,%20…,%20H%20(or%20h)%20as%207,%20I%20(or%20i)%20as%208,%20…,%20and%20Z%20(or%20z)%20as%2025.%20Suppose%20that%20Caesar%20just%20wants%20to%20say%20Hi%20to%20someone%20confidentially%20using,%20this%20time,%20a%20key,%20k,%20of%203.%20And%20so%20his%20plaintext,%20p,%20is%20Hi,%20in%20which%20case%20his%20plaintext’s%20first%20character,%20p0,%20is%20H%20(aka%207),%20and%20his%20plaintext’s%20second%20character,%20p1,%20is%20i%20(aka%208).%20His%20ciphertext’s%20first%20character,%20c0,%20is%20thus%20K,%20and%20his%20ciphertext’s%20second%20character,%20c1,%20is%20thus%20L.%20Can%20you%20see%20why?


#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h> //this is to initiate strlen
#include <stdlib.h> //this is to initialise atoi

int main(int argc, string argv[])
{

    //The following checks the total number of arguments in the array argv[].
    //This code can only have 2 arguments. Any more or less it will be rejected.
    //int arg = atoi(argv[1]);
    //printf("arg is %i\n", arg);
    //printf("argc is %i\n", argc);

    if (argc == 2)
    {
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (isdigit(argv[1][i]))
            {
            }
            else
            {
                return printf("Usage: ./caesar key\n");
            }
        }

        int arg = atoi(argv[1]);

        string getText = get_string("plaintext: ");
        printf("ciphertext: ");

        for (int k = 0; k < strlen(getText); k++)
        {

            if (isalnum(getText[k]))
            {
                if (isupper(getText[k]) && ((getText[k] + arg) > 90))
                {
                    //printf("this is upper\n");
                    int overflowUpper = 65 + ((getText[k] + arg - 65) % 26);
                    printf("%c", overflowUpper);
                }
                else if (islower(getText[k]) && ((getText[k] + arg) > 122))
                {
                    int overflowLower = 97 + ((getText[k] + arg - 97) % 26);
                    printf("%c", overflowLower);
                }
                else
                {
                    printf("%c", getText[k] + arg);
                }
            }
            else
            {
                printf("%c", getText[k]);
            }
        }
    }

    else
    {
        return printf("Usage: ./caesar key\n");
    }

    printf("\n");

}