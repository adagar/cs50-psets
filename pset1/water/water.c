//how many 16 ounce bottles of water will your shower use up? 1 minute of shower = 12 bottles of water
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int min = get_int("Minutes: ");
    printf("Bottles: %i\n", min * 12);
}