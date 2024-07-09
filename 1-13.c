
#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
    int c, i, j, count, state, len, previous;
    int wordlen[1000];
    count = len = i = state = previous = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            if (state == IN)
            {
                wordlen[count] = len;                
                count += 1;
                len = 0;
            }
            state = OUT;    
        }
        else
        { 
            state = IN;
            len += 1;
        }        
    }
    // vertical orientation histogram
    // we need the max from the array
    int max;
    max = 0;

    while (i < count) 
    {
        if (wordlen[i] > max) 
            max = wordlen[i];
        i++;
    }
    printf("max = %d\n", max);

    for (max; max >= 0; max--)
    {
        for (j = 0; j < count; j++)
        {
            if (max >= wordlen[j])
                putchar(' ');
            else 
                putchar('|');
        }
        putchar('\n');
    }
    return 0;
}