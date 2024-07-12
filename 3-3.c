#include <stdio.h>

#define MAXSIZE 1000

void expand(char s1[], char s2[]);

int main()
{
    char* s1 = "1-5-9a-d-g";
    char s2[MAXSIZE];

    expand(s1, s2);
    printf("%s", s2);

    return 0;
}

void expand(char s1[], char s2[])
{
    int i, j, k;
    i = j = 0;

    while (s1[i] != '\0')
    {
        // pattern digit dash digit
        if
        (
            (s1[i] >= '0' && s1[i] <= '9') // some char is a digit
            && s1[i + 1] == '-' // next char is a dash
            && (s1[i + 2] >= '0' && s1[i + 2] <= '9') // next char after dash is also a digit
        )
        {
            k = 0;
            while (s1[i] + k <= s1[i + 2])
            {   
                s2[j++] = s1[i] + k++;    
            }
        }
        // pattern lowercase dash lowercase
        else if 
        (
            (s1[i] >= 'a' && s1[i] <= 'z') // some char is a digit
            && s1[i + 1] == '-' // next char is a dash
            && (s1[i + 2] >= 'a' && s1[i + 2] <= 'z') // next char after dash is also a digit
        )
        {
            k = 0;
            while (s1[i] + k <= s1[i + 2])
            {
                s2[j++] = s1[i] + k++;    
            }
        }
        // pattern uppercase dash uppercase
        else if 
        (
            (s1[i] >= 'A' && s1[i] <= 'Z') // some char is a digit
            && s1[i + 1] == '-' // next char is a dash
            && (s1[i + 2] >= 'A' && s1[i + 2] <= 'A') // next char after dash is also a digit
        )
        {
            k = 0;
            while (s1[i] + k <= s1[i + 2])
            {
                s2[j++] = s1[i] + k++;    
            }
        }
        ++i;
    }
    s2[j] = '\0';
}