#include <stdio.h>

int main() {
    int c;
    printf("%d", EOF);
    while ((c = getchar()) != EOF)
        //printf("getchar() != EOF => %d\n", (c != EOF));
        putchar(c);
    return 0;
}