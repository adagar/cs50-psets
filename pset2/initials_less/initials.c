//takes user's name and returns their initials
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// prc-matt - looks good, nice styling, style50 just picks up a couple of spacing errors but nothing major
// prc-matt - your comments are very helpful, especially when it comes to the if statement, as someone might not know
// off the top of their head what the 32 would mean



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