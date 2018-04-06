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
            //adding additional loop to do mirroring
            for (int m = 0; m < 2; m++)
            {
                if (m == 0)
                {
                    for (int j = 0; j < height - (i+1); j++)
                    {
                        printf(" ");
                    }
                    for (int k = 0; k <= i; k++)
                    {
                        printf("#");
                    }
                    //gap between two pyramids
                    printf("  ");
                }
                else
                {
                    for (int k = 0; k <= i; k++)
                    {
                        printf("#");
                    }
                    //commenting out since hte blank spaces seem to be affecting submission
                    /*
                    for (int j = 0; j < height - (i+1); j++)
                    {
                        printf(" ");
                    }
                    */
                    printf("\n");
                }
            }
        }
    }
    else
    {
        main();
    }
}//make a mario-style pyramid according to user's desired heigh
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height = get_int("Height: ");
    if (height >= 0 && height < 24)
    {
        for (int i = 0; i < height; i++)
        {
            //adding additional loop to do mirroring
            for (int m = 0; m < 2; m++)
            {
                if (m == 0)
                {
                    for (int j = 0; j < height - (i+1); j++)
                    {
                        printf(" ");
                    }
                    for (int k = 0; k <= i; k++)
                    {
                        printf("#");
                    }
                    //gap between two pyramids
                    printf("  ");
                }
                else
                {
                    for (int k = 0; k <= i; k++)
                    {
                        printf("#");
                    }
                    //commenting out since hte blank spaces seem to be affecting submission
                    /*
                    for (int j = 0; j < height - (i+1); j++)
                    {
                        printf(" ");
                    }
                    */
                    printf("\n");
                }
            }
        }
    }
    else
    {
        main();
    }
}