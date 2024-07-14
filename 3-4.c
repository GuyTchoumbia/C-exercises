#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "utils.h"

void itoa(int n, char s[]);
void itoa2(int n, char s[]);



int main()
{
    int x;
    char s[50];
    x = INT_MIN;

    itoa2(x, s);
    printf("%s", s);
    
}

/*  itao: convert n to characters in s 
*   can't actually print minimum int value, because it posits   
*/

void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0) // record sign
    {
        n = -n; // make positive. Fucks up if n = INT_MIN
    }
    i = 0;
    do {       // generate digits in reverse order
        s[i++] = n % 10 + '0';  // get next digit 
    }
    while ((n /= 10) > 0); // delete it
    if (sign < 0)
    {
        s[i++] = '-';    
    }
    s[i] = '\0';
    reverse(s);
}

void itoa2(int n, char s[])
{
    int i, sign;
    unsigned int abs;

    
    if ((sign = n) < 0) // record sign
    {
        abs = -n;  // put the absolute value in an unsigned variable.
    }
    i = 0;
    do {       // generate digits in reverse order
        s[i++] = abs % 10 + '0';  // get next digit 
    }
    while ((abs /= 10) > 0); // delete it
    if (sign < 0)
    {
        s[i++] = '-';    
    }
    s[i] = '\0';
    reverse(s);
}

