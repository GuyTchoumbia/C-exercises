// Adapt the ideas of printd to write a recursive version of itoa;
// that is, convert an integer into a string by calling a recursive routine.
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE     100

int itoa(int, char[]);

int main()
{
    char string[MAXSIZE];
    int number = -125;
    itoa(number, string);
    printf("%d in string is %s\n", number, string);

    return 0;
}


int itoa(int number, char string[])
{
    static int i;

    if (number / 10)
    {
        itoa(number / 10, string);
    }
    else 
    {
        i = 0;
        if (number < 0)
        {
            string[i++] = '-';
        }
    }
    string[i++] = abs(number) % 10 + '0';
    string[i] = '\0'; // gets overwritten by the next level of itoa, except for the last one
}