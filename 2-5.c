#include <stdio.h>

/* I don't get it this is extremely simple */

int any(char s1[], char s2[]);

int main()
{
    char s1[] = "something";
    char s2[] = "meth";

    printf("%d\n", any(s1, s2)); 
    return 0;
}

int any(char s1[], char s2[])
{
    int i, j;
    i = j = 0;
    while(s1[i] != '\0')
    {
        while(s2[j] != '\0')
        {
            if (s1[i] == s2[j])
            {
                return i;
            }
            ++j;
        }
        ++i;
    }
    return -1;
}