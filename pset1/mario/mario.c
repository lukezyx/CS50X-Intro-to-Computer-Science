//this whole code creates a pyramid.
//you can only add in a value from 1 to 8.


#include <stdio.h>
#include <cs50.h>

int main(void){
    //define
    int height;

    do {
        height = get_int("Select a number from 1 to 8\n");
    }
    while (height > 8 || height < 1);

    for (int i = 1 ; i <= height; i++) {
        for (int k = i; k < height ; k++){
            printf(" ");

        }

        for (int j = 1; j <= i; j++) {
            printf("#");
        }


        printf("\n");
    }

}