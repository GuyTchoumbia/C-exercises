#include <stdio.h>
#include <math.h>

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
        bit = (x >> i) & 1;
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
    // closing character
    // binary[i] = '\0';
    // printf(" --> %s\n", binary); 
}
