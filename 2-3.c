#include <stdio.h>
#include <math.h>

#define  MAXSIZE 1000
#define VALID 1
#define WRONG 0

int hexToInt(char* str);
void getString(char str[]);
int validate(char* str);

int main()
{
    int c, i;
    char str[MAXSIZE] = "";

    getString(str);
    while (!validate(str))
    {
        getString(str);
    }

    /* convert and print */
    printf("%s to int => %d\n", str, hexToInt(str));

    return 0;
}

/* get the input string */
void getString(char str[])
{
    int c, i;
    i = 0;
    
    while ((c = getchar()) != EOF && c != '\n')
    {
        str[i++] = c;
    }
    str[i] = '\0';
}

/* validate the string
must start with 0 then x or X,
then numbers, or letters between a and f or A and F

*/
int validate(char* str)
{
    int i;

    if (str[0] != '0')
    {
        printf("first char is wrong\n");
        return WRONG;
    }
    if (str[1] != 'x' && str[1] != 'X')
    {
        printf("second char is wrong\n");
        return WRONG;
    }
    for (i = 2; str[i] != '\0'; ++i)
    { 
        // simpler for me to find what's good than what the opposite of it is
        if ((str[i] < '0' || str[i]  > '9') // is not a number
            && (str[i] < 'a' || str[i] > 'f') // and is not a lowercase letter between 'a' and 'f' 
            && (str[i] < 'A' || str[i] > 'F')) // and is not an uppercase letter between 'A' anf 'F'
        {
            printf("wrong char %c at position %d\n", str[i], i + 1);
            return WRONG;
        }  
    }
    printf("string is valid\n");
    return VALID;    
}

int hexToInt(char* str)
{
    int i, result, len;
    
    // go to last non '\0' character and get the length
    for (len = 0; str[len] != '\0'; ++len); 

    result = 0;
    i = len - 1;
    while (str[i] != 'x' && str[i] != 'X')
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            result += (str[i] - '0') * pow(16, len - i - 1);
        }
        else if (str[i] >= 'a' && str[i] <= 'f')
        {
            result += (str[i] - 'a' + 10) * pow(16, len - i - 1);
        }
        else if ((str[i] >= 'A' && str[i] <= 'F'))
        {
            result += (str[i] - 'A' + 10) * pow(16, len - i - 1);
        }
        else
        {
            printf("invalid string\n");
            return -1;
        }     
        --i;   
    }
    return result;
}