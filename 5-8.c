/* There is no error checking in day_of_year or month_day. Remedy this defect. */

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

    year = 2025;
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
    int leap = is_leap(year);
    if ((month < 1 || month > 12) || (day < 1 || day > daytab[leap][month]))
    {
        return -1;
    }

    for (int i = 1; i < month; i++)
    {
        day += daytab[leap][i];
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
    leap = is_leap(year);

    // check if yearday is valid
    if (yearday < 1 || yearday > (leap ? 366 : 365)) 
    {
        return -1;
    }

    for (i = 1; yearday > daytab[leap][i]; i++)
    {
        yearday -= daytab[leap][i];
    }
    *pmonth = i;
    *pday = yearday;

    return 0;
}

int is_leap(int year)
{
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}