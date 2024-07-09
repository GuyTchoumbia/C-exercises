#include <stdio.h>

/* write an alternate version of squeeze(s1, s2)
that deletes each character in s1 that matches any character in the string s2.

*/
void squeeze(char s1[], char s2[]);

int main()
{
    char s1[] = "something";
    char s2[] = "meth";
    
    squeeze(s1 , s2);
    printf("%s", s1);
    return 0;
}

void squeeze(char s1[], char s2[])
{
    // It's just another loop over the first squeeze, I don't get it.
    int i, j, k;
    for (k = 0; s2[k] != '\0'; k++)
    {
        for (i = j = 0; s1[j] != '\0'; ++i)
        {
            if (s1[i] != s2[k])
            {
                s1[j++] = s1[i];
            }
        }
    }
}