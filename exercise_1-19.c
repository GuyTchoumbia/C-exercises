#include <stdio.h>

#define MAXLINE 1000

void reverse(char str[]);
int getline(char str[], int limit);

int main()
{
    int len;    //current line length
    char line[MAXLINE];  // longest line saved here

    while ((len = getline(line, MAXLINE)) > 0)
    {
        reverse(line);
    }    
    return 0;
}

void reverse(char str[])
{
    int i, j;
    
    for (i = 0; str[i] != '\0'; i++); // get to the last character of the string

    char reversed[i];
    j = 0;
    while (i >= 0) 
    {
        reversed[j++] = str[--i];
    }
    reversed[j] = '\0'; 
    printf("%s\n", reversed);
}

/* getline: read a line into s, return length */
int getline(char str[], int limit) {
    int c, i;

    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        str[i] = c;
    }
    str[i] = '\0';
    return i;
}