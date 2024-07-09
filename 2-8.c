#include <stdio.h>
#include "utils.h"

int rightrot(int x, int n);

int main()
{
    int x, n;
    printf("x ? : ");
    scanf("%d", &x);
    printf("x in binary : ", x);
    intToBinary(x);

    printf("n ? : ");
    scanf("%d", &n);
    
    printf("rotating right by %d : \n", n);
    intToBinary(rightrot(x, n));
}

int rightrot(int x, int n)
{
    // extract and save the last n bits
    int tail, pos;
    tail = x & ((1 << n) - 1);

    printf("tail of size %d : ", n);
    intToBinary(tail);
    
    // cut the tail, shift the bits of x right by n
    x >>= n; 
    printf("tail of %d cut : ", n);
    intToBinary(x);

    /* reattach the tail to the head

    2 ways to understand the assignment:    
        1. bits are rotated to the most significant bit        
        2. bits are rotated to the leftmost bit    
    

        1. bits are rotated to the most significant bit
    position of the head is position of the first significant bit + n (starting from the right)
    position of the first significant bit p can be found by testing every bit from the left until we find a 1
    for that we need the size of the variable
   
    int size = sizeof(x) * 8 - 1;
    pos = 0;
    while (!(x >> size-- & 1))
    {
        ++pos;
    }
    printf("position of the most significant bit (from the left) : %d\n", pos);
    then its totalsize - p
    totalsize = 32, so 32 - p
    */
        
    // that works but there's also this
    // shift right by 1 until there's only 0's (so value = 0) and count how many shifts it took
    // it gives us the position of the first leading zero from the right, so the size of the "body"
    pos = 1;
    while (x >> pos)
    {
        pos++;
    }    
    printf("size of the body : %d\n", pos);

    // now we shift the tail leftside until it's at the position of the body
    tail <<= pos;    

    /* 2. bits are rotated to the leftmost bit, much simpler
    In which case we only need the total bit size of the variable,
    and we just shift the tail accordingly (totalsize - n)
    */
    // tail <<= sizeof(x) * 8 - n

    printf("tail shifted to the position of the head : ");
    intToBinary(tail);

    // and fuse both
    return x | tail;
}

