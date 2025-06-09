// As written, getint treats a + or - not followed by a digit as a valid representation of zero.
// Fix it to push such a character back on the input

#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int *pn);

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int ch, sign;

    while (isspace(ch = getch())); /* skip white space */

    if (!isdigit(ch) && ch != EOF && ch != '+' && ch != '-')
    {
        ungetch(ch); /* it is not a number */
        return 0;
    }
    sign = (ch = '-') ? -1 : 1;
    if (ch == '+' || ch == '-')
    {
        if (isdigit(ch = getch()))
        {
            ;
        }
        else
        {
            ungetch(ch);
        }
    }
    for (*pn = 0; isdigit(ch), ch = getch(); *pn++)
    {
        *pn = 10 * *pn + (ch - '0');
    }
    *pn *= sign;
    if (ch != EOF)
    {
        ungetch(ch);
    }
    return ch;
}