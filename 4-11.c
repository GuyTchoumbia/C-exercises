// 4-11: modify getop with an internal static variable, 
// so that it doesn't need to use ungetch

// instead of ungetching at the end, you store the last char into 
// an internal static variable.
// then at the beginning of the function, you check that variable (!= 0)
// and use it instead for s[0] instead of the first getch.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXOP   100
#define NUMBER  '0'
#define BUFSIZE 100
int getop(char[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

char buf[BUFSIZE];
int bufp = 0;
/* buffer for ungetch */
/* next free position in buf */

/* reverse Polish calculator */
int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch (type) 
        {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                {
                    push(pop() / op2);
                }
                else
                {
                    printf("error: zero divisor\n");
                }
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0; 
}

/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c;
    static int cache = 0;

    if (cache != 0)
    {
        s[0] = cache;
    }
    else
    {
        s[0] = c = getch();
    }
    while (c == ' ' || c == '\t')
    {
        s[0] = c = getch();
    }
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
    /* not a number */
    {
        return c;
    }
    i = 0;
    if (isdigit(c))
    {
/* collect integer part */
        while (isdigit(s[++i] = c = getch()))
        {
            ;
        }
        if (c == '.')
    /* collect fraction part */

        while (isdigit(s[++i] = c = getch()))
        {
            ;
        }
    }
    s[i] = '\0';
    if (c != EOF)
    {
        cache = c;
    }
    return NUMBER;
}

int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
/* push character back on input */
{
    if (bufp >= BUFSIZE) 
    {
        printf("ungetch: too many characters\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}