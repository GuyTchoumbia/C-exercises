#include <stdio.h>
#include <time.h>

#define SIZE 65000

int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[], int n);

int main()
{
    int i, x, res, count;
    int v[SIZE];

    for (i = 0; i < SIZE; ++i)
    {
        v[i] = i;
    }

    printf("x = ?\n");
    scanf("%d", &x);
    printf("x : %d\n", x);

    clock_t begin = clock();
    res =  binsearch(x, v, SIZE);
    clock_t end = clock();
    double time1 = (double)(end - begin) / CLOCKS_PER_SEC;

    begin = clock();
    res =  binsearch2(x, v, SIZE);
    end = clock();
    double time2 = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("time 1 : %.9f, time2 : %.9f\n", time1, time2); // too fast to be measurable
    return 0;
}


/* binsearch: find x in v[0] <= ... <= v[n - 1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0,
    high = n - 1;

    
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x < v[mid])
        {
            high = mid - 1;
        }
        else if (x > v[mid])
        {
            low = mid + 1;
        }   
        else
        {
            return mid;
        }
    }
    return - 1; 
}


/* binsearch: find x in v[0] <= ... <= v[n - 1] */
int binsearch2(int x, int v[], int n)
{
    int low, high, mid;

    low = 0,
    high = n - 1;

    /*  something like this?
    *   instead of testing for equality you let the loop run until there is 
    *   convergence of low and high ( => low < high breaks because low = high)
    *   as for the difference in run-time...
    */
    while (low < high)
    {
        mid = ((low + high) / 2) + 1; // + 1 needed the shake up the last loops near convergence, or mid will remain at the same index indefinitely
        if (x < v[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid;
        }   
    }
    return x == v[low] ? low : - 1; 
}