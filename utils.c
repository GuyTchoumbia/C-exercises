#include <stdio.h>
#include <math.h>
#include <string.h>

// interchanges two arguements of type t.
#define swap(t, x, y){ t _; _ = x; x = y; y = _;}

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

/* expands shorthand notations like 0-9 or a-z to the equivalent complete list */
void expand(char s1[], char s2[])
{
    int i, j, k;
    i = j = 0;

    while (s1[i] != '\0')
    {
        // pattern digit dash digit
        if
        (
            (s1[i] >= '0' && s1[i] <= '9') // some char is a digit
            && s1[i + 1] == '-' // next char is a dash
            && (s1[i + 2] >= '0' && s1[i + 2] <= '9') // next char after dash is also a digit
        )
        {
            k = 0;
            while (s1[i] + k <= s1[i + 2])
            {   
                s2[j++] = s1[i] + k++;    
            }
        }
        // pattern lowercase dash lowercase
        else if 
        (
            (s1[i] >= 'a' && s1[i] <= 'z') // some char is a digit
            && s1[i + 1] == '-' // next char is a dash
            && (s1[i + 2] >= 'a' && s1[i + 2] <= 'z') // next char after dash is also a digit
        )
        {
            k = 0;
            while (s1[i] + k <= s1[i + 2])
            {
                s2[j++] = s1[i] + k++;    
            }
        }
        // pattern uppercase dash uppercase
        else if 
        (
            (s1[i] >= 'A' && s1[i] <= 'Z') // some char is a digit
            && s1[i + 1] == '-' // next char is a dash
            && (s1[i + 2] >= 'A' && s1[i + 2] <= 'A') // next char after dash is also a digit
        )
        {
            k = 0;
            while (s1[i] + k <= s1[i + 2])
            {
                s2[j++] = s1[i] + k++;    
            }
        }
        ++i;
    }
    s2[j] = '\0';
}