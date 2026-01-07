/* Rewrite the routines day_of_year and month_day with pointers instead of indexing */

#include <stdio.h>
#include <assert.h>

int day_of_the_year(int year, int month, int day);
int month_day(int year, int yearday, int *pmonth, int *pday);
int is_leap(int year);

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main()
{
    int year, month, day, result, *pmonth, *pday;

    year = 2024;
    month = 12;
    day = 29;
    pmonth = &month;
    pday = &day;

    result = day_of_the_year(year, month, day);
    printf("%d\n", result);

    month_day(year, result, pmonth, pday);

    printf("%d/%d\n", *pmonth, *pday);

    month = 13;
    result = day_of_the_year(year, month, day);
    assert(result == -1);
    month = 11;
    day = 31;
    result = day_of_the_year(year, month, day);
    assert(result == -1);

    assert(month_day(2000, 400, pmonth, pday) == -1); 

    return 0;
}

/* day_of_the_year: set day of year from month & day
params:
- int year
- int month
- int day

return: 
- the day of the year
- -1 if the month or the year are invalid
*/ 
int day_of_the_year(int year, int month, int day)
{
    int leap;
    
    leap = is_leap(year);
    char *dayPtr;
    char (*monthPtr)[13];

    // error checking
    if ((month < 1 || month > 12) || (day < 1 || day > daytab[leap][month]))
    {
        return -1;
    }
    // point to the right array
    monthPtr = daytab;
    monthPtr++;

    dayPtr = *monthPtr;

    while (--month) // stops when month is null
    {
        day += *++dayPtr; // starts with incrementing *p, since p[0] is illegal (could also have done it before the loop)
    }

    return day;
}

/* mont_day: set month, day, from day of the year
params:
- int year
- int yearday
- int *pmonth
- int *pday

returns:
- -1 if the yearday is invalid
- 0 if success
*/
int month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    char *dayPtr;
    char (*yearPtr)[13];
    leap = is_leap(year);

    // check if yearday is valid
    if (yearday < 1 || yearday > (leap ? 366 : 365)) 
    {
        return -1;
    }

    yearPtr = daytab + leap; 
    dayPtr = *yearPtr;

    for (i = 1; yearday > *++dayPtr; i++)
    {
        yearday -= *dayPtr;
    }
    *pmonth = i;
    *pday = yearday;

    return 0;
}

int is_leap(int year)
{
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}