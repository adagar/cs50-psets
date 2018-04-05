#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    float change;
    int coins = 0;

    do
    {
        change = get_float("Change owed: ");
    }
    while (!(change >= 0));

    int changeInt = round(change * 100);
    //printf("%i\n", changeInt);

    while (changeInt >= 25)
    {
        coins++;
        changeInt -= 25;
    }
    while (changeInt >= 10)
    {
        coins++;
        changeInt -= 10;
    }
    while (changeInt >= 5)
    {
        coins++;
        changeInt -= 5;
    }
    while (changeInt >= 1)
    {
        coins++;
        changeInt -= 1;
    }

    printf("%i\n", coins);
}