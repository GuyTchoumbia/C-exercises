#include <stdio.h>
#include <math.h>
#include "utils.h"

int getbits(int x, int p, int n);
int setbits(int x, int p, int n, int y);
void intToBinary(int x);
void getInput(char input[]);

int main()
{
    int x, y;
    scanf("%d", &x);
    intToBinary(x);

    scanf("%d", &y);
    intToBinary(y);    

    intToBinary(setbits(x, 2, 3, y));
    return 0;
}

/* returns the n rightmost bits of x of positon p */
int getbits(int x, int p, int n)
{
    return (x >> (p - n + 1)) & ~(~0 << n);
}

int setbits(int x, int p, int n, int y)
{
    // shift y left by n bits (add n zero at the end)
    y = y << n;
    printf("shifting y by 3 == multiply by 8\n");
    intToBinary(y);

    printf("3 last bits of x : ");
    intToBinary(getbits(x,p,n));

    // now y | getbits(x) should be enough
    return y | getbits(x, p, n); 
}

