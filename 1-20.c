/* detab: 
* replaces tabs in the input with the proper number of blanks to space
* to the next tab stop.
*/
#include <stdio.h>

#define COLUMN 10

int main()
{
    int c, i, j;
    for (i = 0; ((c = getchar()) != EOF); i++)
    {
        if (c == '\n')
        {
            i = 0;
        }
        if (c == '\t')  
        {
            for (j = 0; ((i + j) % COLUMN) != 0; j++)
            {
                putchar(' ');
            }    
        }
        putchar(c);       
    }
    return 0;
}
