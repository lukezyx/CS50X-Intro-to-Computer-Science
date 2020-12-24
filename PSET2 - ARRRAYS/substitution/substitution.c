//Task: to create a substitution type of cipher.
//1st part of this assignment is to check for:
//1. if the key has 26 inputs (1 input for each alphabet)
//2. if the key has any non-alphabetical inputs (./?123 65)
//3. if the key has any duplicates (multiple of the same characters)
//
//2nd part of the assignment is to accomplish:
//1. map the cipher key to the alphabet positions A-Z, a-z
//2. print out the cipher text with given user input.


#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h> //this is to initiate strlen

int main(int argc, string argv[])
{

    string input = argv[1];
    int i = 0; //counter from 0 to 26.
    int total = 26; //this is defined for the number of alphabets there are.

    if (argc == 2) //if more than 2 arguments in input, to reject.
    {

        if (strlen(input) == total) //check that the first argument/input is equal to 26 alphabets.
        {
            while (i < total)
            {
                //the following is to reject anything that's not an alphabet.
                if ((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z'))
                {

                    //the following is to check if there are any duplicated alphabets. i.e. 2 A's, etc.
                    for (int k = 0; k < total ; k++)
                    {
                        char inputUpper = toupper(input[i]); //convert all the input to caps

                        if (inputUpper == toupper(input[k]) \n
                            && i != k) //if i = k, that means there will be a duplicate because input[k] and input[i] is equal the same thing if k=i.
                        {
                            printf("Keys must not contain repeated characters.\n");
                            return 1;
                        }
                    }

                    i++;
                }
                else
                {
                    printf("Usage: ./substitution key\n");
                    return 0;
                }
            }

            //get string input once all the checks above are done correctly.
            string input2 = get_string("plaintext: ");

            //the following is to map the cipher key to the alphabets.
            for (int k = 0, m = strlen(input2); k < m; k++)
            {
                if (islower(input2[k]))
                {
                    input2[k] = tolower(argv[1][input2[k] - 'a']);
                }
                else if (isupper(input2[k]))
                {
                    input2[k] = toupper(argv[1][input2[k] - 'A']);
                }

            }

            printf("ciphertext: %s\n", input2);


        }
        else
        {
            printf("Key must contain 26 characters.\n");
        }

    }
    else
    {
        printf("Usage: ./substitution key\n");
    }





}
