#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string ccNum = get_string("Number: ");
    int oddDigs = 0;

    for(int i = strlen(ccNum) - 2; i >= 0; i-=2)
    {
        int tempDig = ccNum[i] - '0';
        tempDig *= 2;

        for(int j = 0; j < strlen(sprintf("%s", tempDig)); j++)
        {
            int tempSubDig = tempDig[j] - '0';
            oddDigs += tempSubDig;
        }
        //oddDigs += tempDig * 2;
        //printf("%i\n",oddDigs);
    }
    printf("%i", oddDigs);
}