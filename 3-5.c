#include <stdio.h>
#include <math.h>
#include "utils.h"

void itob(int n, char s[], int b);

int main()
{
    int n, b;
    char s[50];

    n = 13;
    b = 3;

    itob(n, s, b);
    printf("%s", s);
    return 0;
}

/* converts integer n into a base b character representation in the string s */
void itob(int n, char s[], int b)
{
    int i, r;

    i = 0;

    do 
    {
        r = n % b;        
        s[i++] = r + '0';
        n /= b;
    }
    while (n);

    s[i] = '\0';
    reverse(s);
}
