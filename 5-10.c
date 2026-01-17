/*
Write the program expr, which evaluates a reverse Polish expression from the
command line, where each operator or operand is a separate argument. For example,
expr 2 3 4 + *
evaluates 2 *(3+4).
*/
#include <stdio.h>
#include <stdlib.h> /* for atoi() */
#include <string.h>
#include <math.h>

#define MAXOP   10 /* max size of operand or operator */
#define BUFSIZE 100
#define MAXVAL  100     /* maximum depth of val stack */
#define NUMBER   '0' /* signal that a number was found */

char getop(char *);
void push(double);
double pop(void);

/* external variables for pop and push*/
int sp = 0;             /* next free stack position*/
double val[MAXVAL];     /* value stack*/
// 4-9: for getch and ungetch to handle EOF, we must change the type of buffer array to int:
// indeed, EOF is not a char, and would fail to be stored in the buffer array
int buf[BUFSIZE];      /* buffer for ungetch */
int bufp = 0;           /* next free position in buf */

/* reverse polish calculator, simplified version */
int main(int argc, char *argv[])
{
    int type, r;
    double operand1, operand2;

    do
    {
        type = getop(*(++argv));
        switch (type)
        {
            case NUMBER: 
                push(atoi(*argv));
                break;
            case '+': push(pop() + pop());
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
            case EOF:
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", argv);
                break;
        }
    }
    while (*argv != NULL); // PSA: argv is NULL terminated by convention

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
        printf("error: stack full, can't push %g\n", f);
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
char getop(char *argv)
{
    char op;

    // operator
    
    if (argv == NULL)
        return EOF;

    if (atoi(argv))
    {
       return NUMBER;
    }

    if (strlen(argv) == 1)
    {
        op = *argv;
        return op;   
    }
}