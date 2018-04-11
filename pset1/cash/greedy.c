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


// ****** 0VERALL ******
//it works!!

// ****** SUGGESTIONS ******

//COMMENTS:
//could add a comment explaining what you are assigning to changeInt why you used round()

//JUST FOR FUN:
//excellect use of round() on line 16. (I couldn't figure this out in my code I kept getting errors)
//line 14 is succinct, I never would have thought of this