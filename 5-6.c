/* Rewrite appropriate programs from earlier chapters and exercises 
with pointers instead of array indexing .
Good possibilities include getline, atoi, itoa, reverse, strindex, and getop */
#include <stdio.h>
#include <string.h>

#define MAXSIZE     100

int _getline(char *s, int limit);
int _strindex(char *s, char *t);
void reverse(char *str);


int main()
{
    // char s[MAXSIZE], t[MAXSIZE];
    // printf("length: %d", _getline(s, MAXSIZE));
    // STRINDEX TESTS
    // match at the beginning
    char s1[] = "something";
    char t1[] = "some";
    printf("string 1: %s, string 2: %s, index: %d\n", s1, t1, _strindex(s1, t1));
    // match at the end
    char s2[] = "something";
    char t2[] = "thing";
    printf("string 1: %s, string 2: %s, index: %d\n", s2, t2, _strindex(s2, t2));
    // match inside
    char s3[] = "something";
    char t3[] = "meth";
    printf("string 1: %s, string 2: %s, index: %d\n", s3, t3, _strindex(s3, t3));
    // no match
    char s4[] = "something";
    char t4[] = "dot";
    printf("string 1: %s, string 2: %s, index: %d\n", s4, t4, _strindex(s4, t4));

    printf("REVERSE\n");
    printf("string: %s ", s1);
    reverse(s1);
    printf("---> reversed: %s\n", s1);
    return 0;
}

/* getline: get line into s, return length */
int _getline(char *s, int limit)
{
    int i;

    i = 0;
    while (--limit > 0 && (*s=getchar()) != EOF && *s != '\n')
    {
        s++;
        i++;
    }
    if (*s == '\n')
    {
        s++;
        i++; // newline character is counted in length ?!
    }
    *s = '\0';

    return i;
}

/* strindex: return index of t in s, -1 if none */
int _strindex(char *s, char *t)
{
   int index; 
   char *s_begin;
   char *t_begin;

   // save the pointer at the beginning of each string, in order to come back to it
   s_begin = s;
   t_begin = t;
   index = 0;

   while (*s)
   {
        while (*s == *t && *t) // not sure this works
        {
            s++;
            t++;
        }
        if (t > t_begin && !*t)
        {
            return index;
        }
        s = ++s_begin;
        index++;
        t = t_begin;
    }
    return -1;
}

void reverse(char *str)
{
    char temp;
    char *end;
    
    end = str + strlen(str) - 1;

    while (str < end)
    {
        temp = *end;
        *end = *str;
        *str = temp;
        str++;
        end--;
    }
}