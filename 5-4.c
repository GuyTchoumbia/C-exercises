// Write the function strend(s, t), 
// which returns 1 if the string t occurs at the end of the string,
// and zero otherwise

#include <stdio.h>

int main()
{
    int strend(const char *, const char *);
    char *s = "is it at the end";
    char *t = "at thef end";
    
    printf("%d\n", strend(s, t));

}

/* returns 1 if the string t occurs at the end of string s, 0 otherwise*/
int strend(const char *s, const char *t)
{
    // there is no way to check for the start boundary of a string
    // so we need the length of at least the string t
    // we need each pointer to be on their respective end of the string, so might as well get the length at the same time 
    // (could use sizeof too, but that's not the point of the exercise)
    unsigned int len_t;
    
    while (*s)
    {
        s++;
    }
    for (len_t = 0; *t; t++, len_t++);

    // s and t are now positionned on the '\0'. we can go reverse
    while (len_t-- > 0)
    {
        if (*s-- != *t--)
        {
            return 0;
        }
    }
    return 1;
}