// 4-10: polish calculator with getline to read input
// getch and ungetch become unnecessary, we can read directly from the input string/array
// position and the input array are now external variables, used by main and getops both.
// main will initialize the input by calling getline, and getops will read from it
#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>
#include <math.h>

#define MAXOP   10 /* max size of operand or operator */
#define MAXVAL  100     /* maximum depth of val stack */
#define MAXINPUT 100 // maximum size for the input line
#define NUMBER   '0' /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);

// external value for input
input[MAXINPUT];

/* external variables for pop and push*/
int sp = 0;             /* next free stack position*/
double val[MAXVAL];     /* value stack*/
position = 0; // position in the string
/* reverse polish calculator */
int main()
{
    int type, r;
    double operand1, operand2;
    char s[MAXOP];
    
    getline(input, MAXINPUT);

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
            case NUMBER: 
                push(atof(s));
                break;
            // 4-6: add a variable for the last printed value
            case 'r': 
                push(r);
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
                r = pop();
                printf("\t%.8g\n", r);
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

    while (isblank(s[0] = ch = input[position++])) // skip whitespace
    {
        ;
    }
    s[1] = '\0';
    // operator
    if (!isdigit(ch) && ch != '.')
    {
        return ch;   
    }
    i = 0;
    if (isdigit(ch))  /* collect integer part */
    {
        while (isdigit(s[++i] = ch = input[position++]))
        {
            ;
        }
    }
    if (ch == '.')
    {
        while (isdigit(s[++i] = ch = input[position++]))
        {
            ;
        }
    }
    s[i] = '\0';
    if (ch != EOF)
    {
        position--;
    }
    return NUMBER;
}
