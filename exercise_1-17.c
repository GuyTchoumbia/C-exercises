#include <stdio.h>

#define MAXLINE 1000
#define MIN 10

int getline(char line[], int maxline);
void copy(char from[], char to[]);

/* print longest input line*/
int main()
{
    int len, min, i, j;
    char line[MAXLINE];
    char lines[10][MAXLINE];
    
    i = 0;
    while ((len = getline(line, MAXLINE)) > 0 && i < 10)
    {
        if (len > MIN)
        {            
            copy(line, lines[i]);
            i++;
        }
    }
    printf("%s\n", "ending the program, printing the lines");
    for (j = 0; j < i; j++)
    {
        printf("%s", lines[j]);
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