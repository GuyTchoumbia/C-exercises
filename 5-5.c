/*
Write versions of the library functions strncopy, strncat, strncmp, 
which operate on at most the first n characters of their argument strings.
For example, strncopy(s, t, n) copies at most n characters of t to s.
*/
#include <stdio.h>
#include <string.h>
#define SIZE    100

void custom_strncopy(char *, const char *, int);
void custom_strncat(char *, const char *, int);
int custom_strncmp(const char *, const char *, int);

int main()
{
    char s[SIZE] = "something";
    char *t = " wicked this way comes";
    // Tests
    printf("TEST STRCOPY\n");
    int n = 7; // first word of t
    printf("n = %d\n", n);
    custom_strncopy(s, t, n);
    printf("%s\n", s);

    n = 12; // 2 words of t
    // need to reinitialize s in between tests
    memset(s, 0, SIZE);
    strcpy(s, "something");
    printf("n = %d\n", n);
    custom_strncopy(s, t, n);
    printf("%s\n", s);

    n = 0;
    memset(s, 0, SIZE);
    strcpy(s, "something");
    printf("n = %d\n", n);
    custom_strncopy(s, t, n);
    printf("%s\n", s);

    n = 78; // way more than t allows
    memset(s, 0, SIZE);
    strcpy(s, "something");
    printf("n = %d\n", n);
    custom_strncopy(s, t, n);
    printf("%s\n", s);

    printf("TEST STRCAT\n");
    memset(s, 0, SIZE);
    strcpy(s, "something");
    n = 7; // first word of t
    printf("n = %d\n", n);
    custom_strncat(s, t, n);
    printf("%s\n", s);

    n = 12; // 2 words of t
    memset(s, 0, SIZE);
    strcpy(s, "something");
    printf("n = %d\n", n);
    custom_strncat(s, t, n);
    printf("%s\n", s);

    n = 0;
    memset(s, 0, SIZE);
    strcpy(s, "something");
    printf("n = %d\n", n);
    custom_strncat(s, t, n);
    printf("%s\n", s);

    n = 78; // way more than t allows
    memset(s, 0, SIZE);
    strcpy(s, "something");
    printf("n = %d\n", n);
    custom_strncat(s, t, n);
    printf("%s\n", s);

    memset(s, 0, SIZE);
    strcpy(s, "something wicked this way comes");
    t = "something wicked this way doesn't come";

    printf("TEST STRCMP\n");
    n = 7; // first word
    printf("n = %d\n", n);
    printf("%d\n", custom_strncmp(s, t, n));

    n = 12; // 2 words of t
    printf("n = %d\n", n);
    printf("%d\n", custom_strncmp(s, t, n));

    n = 0;
    printf("n = %d\n", n);
    custom_strncmp(s, t, n);
    printf("%d\n", custom_strncmp(s, t, n));

    n = 27;
    printf("n = %d\n", n);
    custom_strncmp(s, t, n);
    printf("%d\n", custom_strncmp(s, t, n));

    n = 78; // way more than t allows
    printf("n = %d\n", n);
    custom_strncmp(s, t, n);
    printf("%d\n", custom_strncmp(s, t, n));

    return 0;
}

/* copies at most n characters of string t into string s*/
void custom_strncopy(char *s, const char *t, int n)
{
    // copy n first characters of t to s
    while (n > 0 && *t)
    {
        *s++ = *t++;
        n--;
    }
}

/* copies at most n characters of string t at the end of string s */
void custom_strncat(char *s, const char *t, int n)
{
    // set s at the end of the string (on the '\0')
    while (*s)
    {
        s++;
    }
    // copy n first characters of t to s
    while (n > 0 && *t)
    {
        *s++ = *t++;
        n--;
    }
}

/* compares n first characters of strings s and t
returns <O if s < t, 0 if s == t, >0 if s > t
*/
int custom_strncmp(const char *s, const char *t, int n)
{
    while (n-- > 0 && *s && *t)
    {
        if (*s++ != *t++)
        {
            return *s - *t; 
        } 
    }

    return 1;
}
