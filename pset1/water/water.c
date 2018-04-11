//how many 16 ounce bottles of water will your shower use up? 1 minute of shower = 12 bottles of water
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int min = get_int("Minutes: ");
    printf("Bottles: %i\n", min * 12);
}


// ****** 0VERALL ******
//this is short and to the point

// ****** SUGGESTIONS ******

//COMMENTS:
//could make use of comments by explaining that line 8 is multiplying number of minutes by the 12oz of water

//CLARITY:
//could include ounces in the printf() just for clarity

//FUNCTIONS:
//could add a do while loop that asks specifically for a positive interger
//right now the formula accepts negative intergers (ie -12 equates to -144 bottles)

//JUST FOR FUN:
//send a message for anyone taking more than a 5 minute shower that Captain Planet would be really disappointed if he found out