#include <stdio.h>

#define MAXLINE 10

int getline(char line[], int maxline);
void copy(char from[], char to[]);

/* print longest input line*/
int main()
{
    int c, len, max;
    char line[MAXLINE], longest[MAXLINE];
    
    max = 0;
    while ((len = getline(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            if (len == MAXLINE - 1 && line[len] != '\n')
            {
                while ((c = getchar()) != '\n' && c != EOF)  
                { 
                    len ++;
                }                
            }
        }
        max = len;
        copy(line, longest);
    }
    if (max > 0) /* there was a line */
    {
        printf("longest line : %s\n max chars : %d", longest, max);
    }
    return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char from[], char to[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0') {
        i++;
    }
}