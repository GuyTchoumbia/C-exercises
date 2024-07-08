#include <stdio.h>
#include <math.h>

void intToBinary(int x)
{
    // printf("%d", x);
    
    // int exponant, i, cache;
    // // find highest exponant
    // exponant = 0;
    // while (x - pow(2, exponant) >= 0)
    // {
    //     exponant++;
    // }

    // actual exponent is exponent -1 since the loop increases once more than necessary
    //  but is the neecessary size of the array (exponent +1 because room for the closing char '\0' )
    // char binary[exponant];

    // i = 0;
    //decrement exponent properly now
    // exponant--;
    // while (exponant >= 0)
    // {
    //     if ((x - (cache = pow(2, exponant--))) >= 0) // saving that to not have to do it twice
    //     {
    //         binary[i++] = '1';
    //         x -= cache;
    //     }
    //     else 
    //     {   
    //         binary[i++] = '0';   
    //     }
    // }

    
    // or just use bitwise operations to find where there are 1's and 0's
    // sizeof(int) returns memory size of an int IN BYTES (so actual size is times 8 that)
    int i;
    i = (sizeof(x) * 8) - 1; // -1 cause it's an array too, so last index is at 31
    while (i >= 0)
    {
        printf("%d", (x >> i) & 1); // we do all the 32 bits, so a lot of leading zeros
        --i;
    }
    // closing character
    // binary[i] = '\0';
    // printf(" --> %s\n", binary); 
}
