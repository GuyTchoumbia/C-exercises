#include <stdio.h>

void main() {
    long c;
    c = getchar();
    while (c != EOF) {
        if (c == ' ') { 
            putchar(c) ; 
            while (c == ' '); // do nothing                     
        }
        else { 
            putchar(c);
        }        
        c = getchar();             
    }
}