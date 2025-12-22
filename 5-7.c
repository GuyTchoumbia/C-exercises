/* Let us illustrate by writing a program that will sort a set of text lines into alphabetic
order, a stripped-down version of the UNIX program sort */
/* Rewrite readlines to store lines in an array supplied by main, rather than
calling alloc to maintain storage */

#include <stdio.h>
#include <string.h>

#define MAXLINES 50
#define MAXLEN 1000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], char (*buffer)[MAXLEN], int nlines);
void writelines(char *lineptr[], int nlines);
int _getline(char *, int);
void qsort(char *lineptr[], int left, int right);

/* sort input lines */
int main()
{
    int nlines; // number of input lines to read
    char buffer[MAXLINES][MAXLEN];

    if ((nlines = readlines(lineptr, buffer, MAXLINES)) >= 0)
    {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }
}

/* readlines: read input lines
args:
    char *lineptr[]: array of strings to read from
    char (*buffer)[MAXLEN] or char[][MAXLEN]: memory buffer 
    int maxlines: maximum number of lines to read
return:
int number of lines actually read
*/
int readlines(char *lineptr[], char (*buffer)[MAXLEN], int maxlines)
{
    int len, nlines;
    char line[MAXLEN]; // === char *line

    nlines = 0;
    while ((len=_getline(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines)
        {
            return -1; // fail? just break, no?
        }
        else
        {
            line[len - 1] = '\0'; // replace newline with string termination 
            strcpy(buffer[nlines], line);
            lineptr[nlines] = buffer[nlines];
            nlines++;
        }
    }
    return nlines;
}

/* writelines: write output lines
args:
    char *lineptr[]:  array of strings to read from
    int maxlines: amximum number of lines to read 
*/
void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
    {
        printf("%s\n", *lineptr++);
    }
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
    int i, last;
    void _swap (char *v[], int i, int j);

    if (left >= right) // do nothing if array contains fewer than 2 elements
    {
        return;
    }
    _swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
    {
        if (strcmp(v[i], v[left]) < 0)
        {
            _swap(v, ++last, i);
        }
    }
    _swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j]*/
void _swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


/* getline: get line into s, return length */
int _getline(char *s, int limit)
{
    int i;

    i = 0;
    while (--limit > 0 && (*s=getchar()) != EOF && *s != '\n')
    {
        s++;
        i++;
    }
    if (*s == '\n')
    {
        s++;
        i++; // newline character is counted in length ?!
    }
    *s = '\0';

    return i;
}