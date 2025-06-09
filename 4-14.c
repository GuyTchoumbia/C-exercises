// Define a macro swap(t, x, y) that interchanges two arguements of type t.
// (Block structure will help)
 
#include <stdio.h>
#define swap(t, x, y){ t _; _ = x; x = y; y = _;}

int main()
{
    printf("INTEGERS\n");
    int x = 10;
    int y = 5;
    printf("x = %d\ny = %d\n", x, y);
    swap(int, x, y);
    printf("swapped\n");
    printf("x = %d\n", x);
    printf("y = %d\n", y);

    printf("STRINGS\n");
    char a = 's';
    char b = 'a';
    printf("a = %c\nb = %c\n", a, b);
    swap(char, a, b);
    printf("swapped\n");
    printf("a = %c\nb = %c\n", a, b);

    printf("variable with _ in the name\n");
    double an_example = 5.142564;
    double another_example_oh_that = 1.0000001;
    swap(double, an_example, another_example_oh_that);
    printf("an_example = %f\nanother_example_of_that = %f\n", an_example, another_example_oh_that);
}