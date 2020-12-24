#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float average;


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++ )
        {
            average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;

        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    float sepiaRed, sepiaGreen, sepiaBlue;
    int sepiaRedInt, sepiaGreenInt, sepiaBlueInt;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++ )
        {

            sepiaRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
            sepiaGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen  + .168 * image[i][j].rgbtBlue;
            sepiaBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen  + .131 * image[i][j].rgbtBlue;

            sepiaRedInt = round(sepiaRed);
            sepiaGreenInt = round(sepiaGreen);
            sepiaBlueInt = round(sepiaBlue);

            if (sepiaRedInt > 255)
            {
                sepiaRedInt = 255;
            }

            if (sepiaBlueInt > 255)
            {
                sepiaBlueInt = 255;
            }

            if (sepiaGreenInt > 255)
            {
                sepiaGreenInt = 255;
            }

            image[i][j].rgbtRed = sepiaRedInt;
            image[i][j].rgbtGreen = sepiaGreenInt;
            image[i][j].rgbtBlue = sepiaBlueInt;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{


    for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width / 2; j++)
            {
                //printf("initial: r - %i. g - % i. b - %i. j - %i.\n", image[i][j].rgbtRed, image[i][j].rgbtGreen, image[i][j].rgbtBlue, j);
                //printf("final: r - %i. g - % i. b - %i. j - %i.\n", image[i][width-j].rgbtRed, image[i][width-j].rgbtGreen, image[i][width-j].rgbtBlue, width-j);

                //printf("%i\n", j);

                int storeRed, storeGreen, storeBlue = 0;

                storeRed = image[i][j].rgbtRed;
                storeGreen = image[i][j].rgbtGreen;
                storeBlue = image[i][j].rgbtBlue;

                image[i][j].rgbtRed = image[i][width-j-1].rgbtRed;
                image[i][j].rgbtGreen = image[i][width-j-1].rgbtGreen;
                image[i][j].rgbtBlue = image[i][width-j-1].rgbtBlue;

                image[i][width-j-1].rgbtRed = storeRed;
                image[i][width-j-1].rgbtGreen = storeGreen;
                image[i][width-j-1].rgbtBlue = storeBlue;

            }
        }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE temp[height][width]; //create a copy picture

    int sumblue, sumgreen, sumred;

    for (int i = 0; i < height; i++)
    {
        for (int j =0 ; j < width; j++)
        {

            float counter = 0.0;
            sumred = 0;
            sumgreen = 0;
            sumblue = 0;

            //Matrix of 3x3
            //[-1,-1] [-1, 0] [-1, 1]
            //[0, -1] [ 0, 0] [ 0, 1]
            //[1, -1] [ 1, 0] [ 1, 1]

            for (int row = i-1; row < (i+2); row++) //iterate along row
            {
                for (int column = j-1; column < (j+2); column++) // iterate along column
                {
                    if (row < 0 || row >= height) // i+row < 0 eliminates top row -1. i+row > height - 1 eliminates bottom row +1
                    {
                        continue;
                    }
                    if (column < 0 || column >= width)
                    {
                        continue;
                    }

                    sumblue+=image[row][column].rgbtBlue; // sum of blue values of all pixels in 3x3 for that particular pixel looped into m,n and then i,j
                    sumgreen+=image[row][column].rgbtGreen;
                    sumred+=image[row][column].rgbtRed;
                    counter++;
                    
                    temp[i][j].rgbtBlue=round(sumblue/counter);
                    temp[i][j].rgbtGreen=round(sumgreen/counter);
                    temp[i][j].rgbtRed=round(sumred/counter);
                }
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
         image[i][j].rgbtBlue=temp[i][j].rgbtBlue;
         image[i][j].rgbtGreen=temp[i][j].rgbtGreen;
         image[i][j].rgbtRed=temp[i][j].rgbtRed;
        }
    }



    return;
}