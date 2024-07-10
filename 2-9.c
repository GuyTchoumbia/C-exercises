#include <stdio.h>
#include "utils.h"

int bitcount(unsigned x);

int main()
{
    int x;
    printf("x ? : ");
    scanf("%d", &x);
    printf("x in binary : ", x);
    intToBinary(x);

    printf("x has %d 1-bit", bitcount(x));
    return 0;
}

/* counts 1 bits in x
by deleting rightmost 1-bits until x = 0
*/
int bitcount(unsigned x)
{
    int b;

    b = 0;
    while (x)
    {
        x &= x - 1;
        b++;
    }
    
    return b;
}