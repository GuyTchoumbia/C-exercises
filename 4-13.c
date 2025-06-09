// Write a recursive version of the function reverse(s), which reverses the string s in place

#include <string.h>
#include <stdio.h>

void qsort(int[], int, int);
void swap_char(char[], int, int);
void swap_int(int[], int, int);
void reverser(char str[], int, int);
void recursive_reverse(char[]);

int main()
{
    // int test[] = {9, 4, 7, 1, 5, 8, 2, 6, 3}; 
    // qsort(test, 0, 8);
    char test[] = "something";
    printf("%s reversed is ", test);
    recursive_reverse(test);
    printf("%s\n", test);
}

/* reverse: reverse string s in place */
void normal_reverse(char str[])
{
    int ch, i, j;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--)
    {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
    }
}

void recursive_reverse(char str[])
{
    int start = 0;
    int end = strlen(str) - 1;
    reverser(str, start, end);
}

void reverser(char str[], int start, int end)
{
    if (start < end)
    {
        swap_char(str, start, end);
        reverser(str, ++start, --end);
    }
}

/* qsort */
void qsort(int v[], int left, int right)
{
    int i, last;
    void swap_int(int v[], int i, int j);
    /* do nothing if array contains fewer than 2 elements */
    if (left >= right)
    {
        return;
    }
    swap_int(v, left, (left + right) / 2);
    last = left;

    for (i = left + 1; i <= right; i++)
    {
        if (v[i] < v[left])
        {
            swap_int(v, ++last, i);
        }
    }
    swap_int(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

/* swap */
void swap_int(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void swap_char(char str[], int i, int j)
{
    int temp;

    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}