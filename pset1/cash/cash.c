#include <stdio.h>
#include <cs50.h>
#include <math.h> //this is required for the round function used in totalCash

int main(void)
{
    //define working variables. numCoins
    int numCoins = 0; // numCoin = number of coins needed to complete task
    float cash; // cash = initial input of cash. Greater than $0.00
    int totalCash; // totalCash = transformation into whole numbers (int) by multiplication of 100.

    //define coin types
    int pennies = 1;
    int nickels = 5;
    int dime = 10;
    int quarters = 25;

    // EXECUTION OF CODE STARTS HERE
    //ask how much change required. If value less than 0, repeat again.
    do
    {
    cash = get_float("How much change owed?\n");
    }

    while (cash <=0 );
    {
    totalCash = round(cash *100);
    printf("%i\n", totalCash);
    }

    //pseudocode: when you have 30. you want to first minus 25. the mechanism by which you can check if there is a remainder
    //or if there desired remainder is larger than any of the coins
    //i.e. 30 is greater than 25. So 30-25, remainder is 5. 5 is less than 10, but equals to 5. So 5-5 = 0.
    while (totalCash >= quarters)
    {
        totalCash -= quarters;
        numCoins++;
    }

    while (totalCash >= dime)
    {
        totalCash -= dime;
        numCoins++;
    }

    while (totalCash >= nickels)
    {
        totalCash -= nickels;
        numCoins++;
    }

    while (totalCash >= pennies)
    {
        totalCash -= pennies;
        numCoins++;
    }

    //prints out the final value of coins needed for a given change.
    printf("%i coins", numCoins);


    }



