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
    printf("x : ");
    intToBinary(x);

    scanf("%d", &y);
    printf("y : ");
    intToBinary(y);    


    intToBinary(setbits(x, 4, 3, y));
    return 0;
}

/* returns the n rightmost bits of x of positon p */
int getbits(int x, int p, int n)
{
    return (x >> (p - n + 1)) & ~(~0 << n);
}

int setbits(int x, int p, int n, int y)
{
    y &= (1 << n) - 1; // mask n bits large
    printf("mask for y for %d rightmost bits : ", n);
    intToBinary(y);
    y <<= (p - n + 1); // shift y by the same position and number than the bits extracted from x 
    printf("shift y %d times : ", p - n + 1);
    intToBinary(y);

    //poke a hole in x => mask everything but the bits targeted
    x &= ~(((1 << n) - 1) << (p - n + 1));
    printf("poke a hole in x : ");
    intToBinary(x);

    printf("x | y : ");

    return y | x;
}

