#include <stdio.h>

#define MAXSIZE 1000

int main()
{
    char c;
    int i, lim;

    lim = MAXSIZE;
    
    for (i = 0; i < lim - 1; ++i)
    {
        c = getchar();
        if (c == '\n')
        {
            break;
        }
        if (c == EOF)
        {
            break;
        }        
    }
    return 0;
}