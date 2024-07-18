#include <stdio.h>

void main() {
    int c, nl, t, b;
    nl = t = b = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            ++nl;
        }
        if (c == '\t') {
            ++t;
        }
        if (c == ' ') {
            ++b;
        }
    }
    printf("%d, %d, %d", nl, t, b);
}