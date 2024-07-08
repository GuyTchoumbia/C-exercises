#include <stdio.h>
#include "utils.h"

int invert(int x, int p, int n);

int main() 
{
    int x, inverted;
    scanf("%d", &x);
    printf("x : ");
    intToBinary(x);

    inverted = invert(x, 4, 3);
    printf("inverted : ");
    intToBinary(inverted);
    return 0;
}

int invert(int x, int p, int n)
{
    int mask; 
    // use XOR and a mask at the positions we want to invert. 
    // 0 ^ 1 = 1, 1 ^ 1 = 0, so it inverts the bits
    mask = (1 << n) - 1; // that's n times 1, bitwise magic. 
    printf("mask of %d 1's : ", n);
    intToBinary(mask);
    // shift left by p - n + 1, as in the previous exercise, to put the 1's in the same position as the bits we want to invert
    mask <<= (p - n + 1);
    printf("shift the mask in position %d: ", p - n + 1);
    intToBinary(mask);

    // and then just XOR with x
    return x ^ mask;
}

