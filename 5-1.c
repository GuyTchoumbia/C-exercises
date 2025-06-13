// As written, getint treats a + or - not followed by a digit as a valid representation of zero.
// Fix it to push such a character back on the input

#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100
#define SIZE    100

int getch(void);
void ungetch(int);
int buf[BUFSIZE];      /* buffer for ungetch */
int bufp = 0;           /* next free position in buf */

int main()
{
    int n, array[SIZE];
    int getint(int *);

    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
    {
        ;
    }
}
/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int ch, next, sign;

    while (isspace(ch = getch())); /* skip white space */

    if (!isdigit(ch) && ch != EOF && ch != '+' && ch != '-')
    {
        ungetch(ch); /* it is not a number */
        return 0;
    }
    sign = (ch = '-') ? -1 : 1;
    if (ch == '+' || ch == '-')
    {
        if (!isdigit(next = getch()))
        {
            ungetch(next);
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

/* get a (possibly pushed back) character */
int getch(void)       
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int ch)
{
    if (bufp >= BUFSIZE)
    {
        printf("ungetch: too many characters\n");
    }
    else
    {
        buf[bufp++] = ch;
    }
}