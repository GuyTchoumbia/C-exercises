#include <stdio.h>

void lower(char str[]);

int main()
{
    char str[10];
    printf("x ? : ");
    scanf("%s", str);
    lower(str);
    printf("%s", str);
    return 0;
}

void lower(char str[])
{
    int i;

    i = 0;
    while(str[i] != '\0')
    {
        str[i] = (str[i] >= 'A' && str[i] <= 'Z') ? str[i] += 32 : str[i];
        ++i;
    }
}