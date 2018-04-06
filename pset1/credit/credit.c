#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    long long ccNum = get_long_long("Number: ");

    int oddCount = 1;
    int checkSum = 0;
    int numLen = 0;
    int firstTwo;

    while (ccNum > 0)
    {
        //printf("%lld\n", ccNum
        //numLen is going to track the length of the string. At end len of string will be determined
        numLen++;

        //at end, store FIRST TWO digits so that, if valid, we can check against different CC rules
        if (ccNum < 100 && ccNum >= 10)
        {
            firstTwo = ccNum;
        }

        int tempVar = ccNum % 10;
        ccNum = ccNum / 10;

        if (oddCount % 2 == 0)
        {
            tempVar *= 2;
            if (tempVar >= 10)
            {
                while (tempVar > 0)
                {
                    checkSum += tempVar % 10;
                    tempVar = tempVar / 10;
                }
            }
            else
            {
                checkSum += tempVar;
            }
        }
        else
        {
            checkSum += tempVar;
        }
        oddCount++;
    }
    /*
    If the CC is valid, we're going to go through a series of case staments to check
    1) if the first two digits is one of the valid options for a CC
    2) If the length is then correct for that card
    */
    if (checkSum % 10 == 0)
    {
        switch (firstTwo)
        {
            case 34:
            case 37:
                if (numLen == 15)
                {
                    printf("AMEX\n");
                }
                else
                {
                    printf("INVALID\n");
                }
                break;
            case 51:
            case 52:
            case 53:
            case 54:
            case 55:
                if (numLen == 16)
                {
                    printf("MASTERCARD\n");
                }
                else
                {
                    printf("INVALID\n");
                }
                break;
            case 40:
            case 41:
            case 42:
            case 43:
            case 44:
            case 45:
            case 46:
            case 47:
            case 48:
            case 49:
                if (numLen == 16 || numLen == 13)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
                break;
            default:
                printf("INVALID\n");
        }
        /*
        Use digit info to determine which company it is
        Amex
            15 digs
            Starts with 34, 37
        Mastercard
            16 digs
            starts with 51, 52, 53, 54, 55
        Visa
            13 & 16 digs
            start with 4
        */
    }
    else
    {
        printf("INVALID\n");
    }
    //printf("%i %i %i\n", firstTwo, numLen, checkSum);
}