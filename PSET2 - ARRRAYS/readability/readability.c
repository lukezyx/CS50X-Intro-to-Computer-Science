//Link to problem PSET: https://cs50.harvard.edu/x/2020/psets/2/readability/#:~:text=In%20my%20younger%20and%20more%20vulnerable%20years%20my%20father%20gave%20me%20some%20advice%20that%20I've%20been%20turning%20over%20in%20my%20mind%20ever%20since.
//Pseudocode
//create string, ask for input
//need to count letters, words and sentences.
//need to initiate counter for letters, words and sentences.
//letters = for loop, skip spaces
//words = in between spaces
//sentences = count full stops

//final step to the equation if coleman-liau formula is >16, should just print 16+
//this will be covered by an if statement


#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

float ColemanLiau(float L, float S, float W);

int main(void)
{

    //get user input
    string input = get_string("Text: ");

    //declare float counters for letters, words and sentences
    float mainLetterCounter = 0;
    float mainSpaceCounter = 1; //starts from 1 because in between every word is a space. there will always be one word not accounted for.
    float mainSentenceCounter = 0;

    for (int x = 0; x<strlen(input); x++)
    {
        if (isalpha(input[x])) //checking individual characters of the user input if it is an alphabet
        {
            mainLetterCounter++;
        }
        else if (isspace(input[x])) //checking individual characters of the user input to see if it is a space.
        {
            mainSpaceCounter++;
        }
        else if (input[x] == '.' || input[x] == '!' || input[x] == '?') // checking to see if there are any '.', '?' or '!' which can demarcate a stop of a sentence'
        {
            mainSentenceCounter++;
        }


    }


    ColemanLiau(mainLetterCounter, mainSentenceCounter, mainSpaceCounter); //invokes Coleman-Liau function

}

float ColemanLiau(float L, float S, float W)
{
    //declaring l and s variables in Coleman-Liau equation
    float l = L / W * 100;
    float s = S / W * 100;

    //Coleman-Liau equation
    int index = round(0.0588 * l - 0.296 * s - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }



    return index;

}


