#include <stdio.h>

int strrindex(char s[], char t[]);

int main()
{
    char s[] = "azfdsfaz fdsfds fds";
    char t[] = "fd";

    printf("%d", strrindex(s, t));
}

int strrindex(char s[], char t[])
{// returns the position of the rightmost occurence of t in s, -1 if none
    int i, j, index;

    i = j = 0;
    index = -1;
    
    while (s[i] != '\0')
    {
        if (s[i++] == t[j++])
        {
            if (t[j] == '\0')
            {
                index = i - j + 1;
            }
        }
        else
        {
            j = 0;
        }        
    }
    return index;
}