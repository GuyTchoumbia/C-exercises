#include <stdio.h>
#define IN 1
#define OUT 0

main() {
    int state, c;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') { 
            putchar('\n');
            while ((c = getchar()) == ' ' || c == '\n' || c == '\t');
        }        
        else putchar(c);

    }
}