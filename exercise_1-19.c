#include <stdio.h>

#define MAXSIZE 1000

void reverse(char string[]);
int getline(char* s, int lim);

/* getline: read a line into s, return length */
int getline(char *s, int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = '\0';        
    }
    return i;    
}

void reverse(char string[]) 
{
    char c;
    int i, j;
    
    for (i = 0; string[i] != '\0'; i++);

    for (j = 0; j < i; j++ ) // swap last char with first IN THE SAME STRING
    {
        c = string[--i];
        string[i] = string[j];
        string[j] = c;
    }
}

int main()
{
    char line[MAXSIZE];
    while (getline(line, MAXSIZE) > 0)
    {        
        reverse(line);
        printf("%s\n", line);        
    }
    return 0;
}

