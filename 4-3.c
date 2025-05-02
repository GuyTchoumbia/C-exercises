#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>
#include <math.h>  // for exp and pow

#define MAXOP   10 /* max size of operand or operator */
#define BUFSIZE 100
#define MAXVAL  100     /* maximum depth of val stack */
#define NUMBER   '0' /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

/* external variables for pop and push*/
int sp = 0;             /* next free stack position*/
double val[MAXVAL];     /* value stack*/
/* external variables for getch/ungetch */
char buf[BUFSIZE];      /* buffer for ungetch */
int bufp = 0;           /* next free position in buf */

/* reverse polish calculator */
int main()
{
    int type;
    double operand1, operand2;
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
                operand2 = pop();
                push(pop() - operand2);
                break;
            case '/':
                operand2 = pop();
                if (operand2 != 0.0)
                {
                    push(pop() / operand2);
                }
                else
                {
                    printf("error: zero divisor\n");
                }
                break;
            // 4-4: command to print the top element of the stack without popping
            case '#':
                if (sp > 0)
                {
                   printf("top stack value: %f\n", val[sp-1]);
                }
                break;
            // 4-4: command to duplicate top stack value
            case '!':
                {
                    push(val[sp-1]);
                }
                break;
            // 4-4: command to swap the top two elements
            case '|':
                if (sp > 1)
                {
                   operand2 = pop();
                   operand1 = pop();
                   push(operand2);
                   push(operand1);
                }
                break;
            // clear the stack
            case ':':
                // we can't "empty" the array, just reinitialize it.
                sp = 0; // can't pop, only push
            // 4-3 add % operator
            case '%':
                operand2 = pop();
                if (operand2 != 0.0)
                {
                    push((int) pop() % (int) operand2);
                }
                else
                {
                    printf("error: zero divisor\n");
                }
                break;
            // 4-5 add ext and pow
            case '^':
                push(pow(pop(), pop()));
            case 'e':
                push(exp(pop()));
            // could add sin/cos with another symbol, but that's not satisfying
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

/* push : push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
    {
        val[sp++] = f;
    }
    else
    {
        printf("error: stack full, can' push %g\n", f);
    }
}

/* pop : pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
    {
        return val[--sp];
    }
    else{
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, ch, string, sign, next;

    while (isblank(s[0] = ch = getch())); // skip whitespace

    // operator
    if (!isdigit(ch) && ch != '.' && ch != '-')
    {
        return ch;   
    }
    i = 0;
    // 4-3: negative
    // use s[i] as a buffer
    if (ch == '-')
    {
        // if space after, its an minus operator
        if ((next = getch()) == ' ' || next == '\t')
        {
            return ch;
        }
        // if digit or decimal sign behind, its a negative sign
        else if (isdigit(next) || next == '.')
        {
            ch = next;
            ungetch(next);
        }
    }
    if (isdigit(ch))  /* collect integer part */
    {
        while (isdigit(s[++i] = ch = getch()))
        {
            ;
        }
    }
    if (ch == '.')
    {
        while (isdigit(s[++i] = ch = getch()))
        {
            ;
        }
    }
    s[i] = '\0';
    if (ch != EOF)
    {
        ungetch(ch);
    }
    return NUMBER;
}

/* get a (possibly pushed back) character */
int getch(void)       
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
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