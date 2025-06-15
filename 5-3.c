// Write a pointer version of the function strcat that copies the string t to the end of s
#include <stdio.h>
#define MAXSIZE     100

int main()
{
    void strcat(char[], const char[]);
    char s[MAXSIZE] = "put something";
    char *t = " at the end";
    
    strcat(s, t);
    printf("%s\n", s);

}

/* copies the string t at the end of s */
void strcat(char *s, const char *t)
{
    while (*s)
    {
        s++;
    }
    while (*s = *t)
    {
        s++;
        t++;
    }
}