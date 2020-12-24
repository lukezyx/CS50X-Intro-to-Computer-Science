#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //this asks for name
    string name = get_string("What is your name?\n");
    //this returns name
    printf("hello, %s\n", name);
}