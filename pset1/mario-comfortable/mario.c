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