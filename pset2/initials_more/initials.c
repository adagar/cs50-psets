//takes user's name and returns their initials
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// prc-matt - i'm not sure if you meant to come back to this one, since i think it is the same code you used for initials(less)
// which obviously would not work for this one. the basic code is the same for more it just needs some modifications
// if you have time, definitely try to come back and finish it!

int main (void)
{
    string name = get_string("");
    char nameArr[200];
    strcpy(nameArr, name);

    //creating an array to store initials, and starting its first position (0)
    char initials[4];
    int initialCounter = 0;
    //store the first char from user's name as their first initial
    initials[initialCounter] = toupper(name[0]);
    initialCounter ++;

    //loop through name, starting with second character since first is already appended
    for (int i = 1; i < strlen(name); i++)
    {
        //if the previous character to this one was a space (space = 32) append to initials in uppercase form
        if (nameArr[i-1] == 32)
        {
            initials[initialCounter] = toupper(nameArr[i]);
            initialCounter ++;
        }
        //printf("%s\n", initials);
    }
    initials[initialCounter] = '\n';
    printf("%s", initials);
}