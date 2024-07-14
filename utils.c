#include <stdio.h>
#include <math.h>
#include <string.h>

void intToBinary(int x)
{   
    // just use bitwise operations to find where there are 1's and 0's
    // sizeof(int) returns memory size of an int IN BYTES (so actual size is times 8 that)
    int i;
    int leadingzero; // bool for removing empty leading bits
    int bit;
    leadingzero = 1;
    i = (sizeof(x) * 8) - 1; // -1 cause it's an array too, so last index is at 31
    
    while (i >= 0)
    {
        bit = (x >> i) & 1;  // checks if bit is 1, starting from the most significant
        if (leadingzero)  
            if (!bit)
            {
                --i;
                continue;
            }
            else
            {
                leadingzero = 0;
            }   

        if (!leadingzero)
        {
            printf("%d", bit); // we do all the 32 bits, so a lot of leading zeros
            --i;
        }     
    }
    printf("\n");
}

/* reverse: reverse string in place */
void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
