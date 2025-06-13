// Write getfloat, the floating-point analog of geting.
// What type does getfloat returns as its function value?
// Answer: still an int, we still need to check for EOF

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
    int n, getfloat(double *);
    double array[SIZE];

    for (n = 0; n < SIZE && getfloat(&array[n]) != 0; n++)
    {
        printf("%f\n", array[n]);
    }
}
/* getint: get next integer from input into *pn */
int getfloat(double *pn)
{
    int ch, sign, next;
    double decimal;

    while (isspace(ch = getch())); /* skip white space */

    if (!isdigit(ch) && ch != EOF && ch != '+' && ch != '-')
    {
        ungetch(ch); /* it is not a number */
        return 0;
    }
    // sign
    sign = (ch == '-') ? -1 : 1;
    if (ch == '+' || ch == '-')
    {
        ch = getch();
    }
    // integer part
    // TODO
    for (*pn = 0; isdigit(ch); ch = getch())
    {
        *pn = 10 * *pn + (ch - '0');
    }
    // decimal part
    if (ch == '.')
    {
        for (decimal = 0.1; isdigit(ch = getch()); decimal /= 10)
        {
            *pn += decimal * (ch - '0'); 
        }
        // or use pow() from math.h
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