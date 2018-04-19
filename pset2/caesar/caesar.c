//takes a cypher value at run-time, asks user for a string, and then uses that cypher to decode
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    int key;
    if (argc > 1)
    {
        //using argc-1 to avoid a 'unused variable' error and segmentation fault
        //use atoi to convert the string to an integer
        key = atoi(argv[argc - 1]) % 26;
    }
    else
    {
        //if no key was provided, print error, and break out of program
        printf("No key provided\n");
        return 1;
    }

    //prompt user for cyphertext
    string plainText = get_string("plaintext: ");

    //declare plaintext to be cypher text. can skip special characters, and assure same length
    string cypherText = plainText;

    //loop through characters in cyphertext
    for (int i = 0, n = strlen(plainText); i < n; i++)
    {
        //eprintf("%i\t%i", i, n);
        //check if each character is letter
        if (isalpha(plainText[i]))
        {
            //printf("%c is a plaintext character\n", plainText[i]);
            //apply formula to character (cypher = ((plain + key) % 26)) + alphabetical-indices
            //cypherText[i] = (plainText[i] + key) % 26;
            //preserve case
            if (isupper(plainText[i]))
            {
                //printf("%c\n", (cypherText[i] % 'A') + 'A');
                cypherText[i] = (((cypherText[i] - 'A') + key) % 26) + 'A';
            }
            else
            {
                cypherText[i] = (((cypherText[i] - 'a') + key) % 26) + 'a';
            }
            //printf("%c is the coded character\n", cypherText[i]);
        }

    }

    printf("ciphertext: %s\n", cypherText);
    return 0;
}