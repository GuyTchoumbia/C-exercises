#include <stdio.h>
#include <limits.h>
#include <float.h>

/* determine the ranges of char, short, int and long variables,
both signed and unsigned, by printing appropriate values fom standard headers
and by direct computation
*/
char max(char c);

int main()
{
    /* SIGNED CHAR */
    printf("*******\n");
    printf("CHAR\n");
    printf("header max : %d\n", CHAR_MAX);
    printf("header min : %d\n", CHAR_MIN);

    char c = 1;
    int charmax = 0;
    while (c > charmax)
    {
        if (c > charmax)
        {
            charmax = c;
        }
        c++;
    }

    int charmin = 0;
    while (c < charmin) 
    {
        if (c < charmin)
        {
            charmin = c;
        }
        c--;
    }
    printf("max : %d\n", charmax);
    printf("min : %d\n", charmin);


    /* SHORT */
    printf("");
    printf("*******\n");
    printf("SHORT\n");
    printf("header max : %d\n", SHRT_MAX);
    printf("header min : %d\n", SHRT_MIN);
    
    
    int shortmax = 0;
    short s = 0;
 
    while (++s > shortmax)
    {
        if (s > shortmax)
        {
            shortmax = s;
        }
    }

    int shortmin = 0;
    s = 0;
    while (--s < shortmin) 
    {
        if (s < shortmin)
        {
            shortmin = s;
        }
    }

    printf("max : %d\n", shortmax);
    printf("min : %d\n", shortmin);

    printf("");
    printf("*******\n");
    printf("INT\n");
    printf("header max : %d\n", INT_MAX);
    printf("header min : %d\n", INT_MIN);
    
    int intmax = 0;
    int i = 0;
    while (++i > intmax)
    {
        if (i > intmax)
        {
            intmax = i;
        }
    }

    int intmin = 0;
    i = 0;
    while (--i < intmin) 
    {
        if (i < intmin)
        {
            intmin = i;
        }
    }

    printf("max : %d\n", intmax);
    printf("min : %d\n", intmin);

    printf("");
    printf("*******\n");
    printf("LONG\n");
    printf("header max : %d\n", LONG_MAX);
    printf("header min : %d\n", LONG_MIN);
    
    long longmax = 0;
    long l = 0;
    while (++l > longmax)
    {
        if (l > longmax)
        {
            longmax = l;
        }
    }

    long longmin = 0;
    l = 0;
    while (--l < longmin) 
    {
        if (l < longmin)
        {
            longmin = l;
        }
    }

    printf("max : %d\n", longmax);
    printf("min : %d\n", longmin);

    /* FLOAT */

    printf("");
    printf("*******\n");
    printf("FLOAT\n");
    printf("header max : %.g\n", FLT_MAX);
    printf("header min : %.g\n", FLT_MIN);

    return 0;
}
