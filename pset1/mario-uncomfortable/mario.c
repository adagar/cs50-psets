//make a mario-style pyramid according to user's desired heigh
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height = get_int("Height: ");
    if (height >= 0 && height < 24)
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j <= height - (2 + i); j++)
            {
                printf(" ");
            }
            for (int k = 0; k < 2 + i; k++)
            {
                printf("#");
            }
            printf("\n");
        }
    }
    else
    {
        main();
    }
}

// ****** 0VERALL ******
//This works great!

// ****** SUGGESTIONS ******

//COMMENTS:
//could make use of comments, maybe just clarify which loop is creating a row and which is printing characters in the line

//FUNCTIONS:
//I appreciate the if/else function
//I used a do/while loop but this actually looks cleaner and probably takes fewer lines of code
//line 25 is very creative and I never would have thought of it

//JUST FOR FUN:
//send a message for anyone taking more than a 5 minute shower that Captain Planet would be really disappointed if he found out