/* detab: 
* replaces tabs in the input with the proper number of blanks to space
* to the next tab stop.
*/

#include <stdio.h>

#define COLUMN 10

int main()
{
    int c, i;
    while ((c = getchar()) != EOF)
    {
        if (c == '\t') 
        for (i = COLUMN; i >= 0; i--)
        {
            putchar(' ');
        }
        else {
            putchar(c);
        }
    }
    return 0;
}
