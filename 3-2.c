#include <stdio.h>

#define MAXSIZE 100

void escape(char s[], char t[]);
void escapeToReal(char s[], char t[]);

int main()
{
    char s[] = "let's try a tab \t and then a newline \n";
    char t[MAXSIZE];

    escape(s, t);
    printf("%s", t);
}

/* just with tab and newline characters */
void escape(char s[], char t[])
{
    int i, j;
    
    i = j = 0;

    while (s[i] != '\0')
    {
        switch (s[i])
        {
            case '\t' : 
                t[j++] = '\\';
                t[j++] =  't';
                break;
            case '\n' :
                t[j++] = '\\';
                t[j++] =  'n';
                break;
            default:
                t[j++] = s[i];
        }               
        ++i;
    }
    t[j] = '\0';
}

void escapeToReal(char s[], char t[])
{
    int i, j;
    
    i = j = 0;

    while (s[i] != '\0')
    {
        if (s[i] == '\\')
        {
            switch (s[++i])
            {
                case 't' : 
                    t[j++] = '\t';
                    break;
                case 'n' :
                    t[j++] = '\n';
                    break;
                default:
                    t[j++] = s[i++];
            }   
        }
        else
        {
            t[j++] = s[i++];
        }
    }
}