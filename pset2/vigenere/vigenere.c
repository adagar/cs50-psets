//take user's key at runtime, and then requests a plain-text message. Uses that key and vignere algorithm to encode message.
//Returns cipher text
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int checkKey(string key)
{
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isalpha(key[i]))
        {
            return 1;
        }
    }
    return 0;
}

int main(int argc, string argv[])
{
    string key;
    int keyCounter = 0; //this variable will loop through the key, reencoding appropriatlely for dthe current char its set to
    if (argc == 2 && checkKey(argv[argc - 1]) == 0)
    {
        //using argc-1 to avoid a 'unused variable' error and segmentation fault
        key = argv[argc - 1];
    }
    else
    {
        //if no key was provided, print error, and break out of program
        printf("Usage: ./vigenere k\n");
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
            int alphaVal = toupper(key[keyCounter]) - 'A';

            //printf("%i\n", alphaVal);
            //apply formula to character (cypher = ((plain + key) % 26)) + alphabetical-indices
            //cypherText[i] = (plainText[i] + key) % 26;
            //preserve case
            if (isupper(plainText[i]))
            {
                //printf("%c\n", (cypherText[i] % 'A') + 'A');
                cypherText[i] = (((cypherText[i] - 'A') + alphaVal) % 26) + 'A';
            }
            else
            {
                cypherText[i] = (((cypherText[i] - 'a') + alphaVal) % 26) + 'a';
            }
            //printf("%c is the coded character\n", cypherText[i]);

            if (keyCounter < strlen(key) - 1)
            {
                keyCounter++;
            }
            else
            {
                keyCounter = 0;
            }

        }
    }

    printf("ciphertext: %s\n", cypherText);
    return 0;
}