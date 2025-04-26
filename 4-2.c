#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAXLINE 100

/* rudimentary calculator */
int main()
{
    double _atof(char[]);
    char *numbers[4] = {"45641.2e10", "-5.65e-5", "8646.464", "1e-6"};
    int i;
    for (i = 0; i < 4; i++)
    {
        printf("%f\n", _atof(numbers[i]));
    }
    return 0;
}

/* atof: convert string s to double */
double _atof(char s[])
{
    double val, power;
    int i, sign, exponant, exponantSign;

    for (i = 0; isspace(s[i]); i++);  // isspace tests if the char is a white space ( == '/s') => skip whitespaces at the beginning
    sign = (s[i] == '-') ? -1 : 1; // test for minus sign
    if (s[i] == '+' || s[i] == '-') // skip sign char
    {
        i++;
    }
    for (val = 0.0; isdigit(s[i]); i++)  //
    {
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.')
    {
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    // add scientific notation management: same principle as before, with e/E, another sign, an exponant value
    if (s[i] == '\0')
    {
        return sign * val / power;
    }
    if (s[i] == 'e' || s[i] == 'E')
    {
        i++;
    }
    exponantSign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') // skip exponent sign char
    {
        i++;
    }
    for (exponant = 0; isdigit(s[i]); i++)
    {
        exponant = 10 * exponant + (s[i] - '0');
    }
    return sign * val / power * pow(10, exponantSign * exponant);
}