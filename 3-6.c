#include <stdio.h>
#include "utils.h"

void itoa(int n, char s[], int min);

int main()
{
    int n, b;
    char s[10];

    n = 143;
    b = 10;

    itoa(n, s, b);
    printf("%s", s);
    return 0;
}

void itoa(int n, char s[], int min)
{
    int i, sign;

    /* posit the int but keep track of the sign */
    if ((sign = n) < 0)
    {
        n = -n;  
    }

    i = 0;
    do
    {
        s[i++] = n % 10 + '0';
    } 
    while ((n /= 10) > 0); 

    while (i < min)
    {
        s[i++] = ' ';
    }
    
    if (sign < 0)
    {
        s[i++] = '-'; /* taking care of the sign */
    }

    s[i] = '\0'; /* closing character */
    reverse(s);
}