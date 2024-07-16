#include <stdio.h>
#include <math.h>
#include "utils.h"

void itob(int n, char s[], int b);

int main()
{
    int n, b;
    char s[50];

    n = 143;
    b = 12;

    itob(n, s, b);
    printf("%s", s);
    return 0;
}

/* converts integer n into a base b character representation in the string s
*  possible values of a single digit: [0-9a-z]. 
*  so that's 36 characters, meaning that our max base is 36.
*  anymore and you'd need to create a new notation system.
*/
void itob(int n, char s[], int b)
{ 
    int i, r;
    char values[36]; 
    // we just made an expand function to fill the array
    i = 0;
    expand("0-9a-z", values);

    do 
    {
        r = n % b;        
        s[i++] = values[r]; // directly taken from the values array
        n /= b;
    }
    while (n);

    s[i] = '\0';
    reverse(s);
}
