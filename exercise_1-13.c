#include <stdio.h>

#define IN 1
#define OUT 0

void main() {
    int c, count, length, state, i, j;
    int histogram[256];
    
    state = OUT;
    count = length = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') { // space character
            if (state == IN) { // getting OUT of a word
                histogram[count] = length;  // stash the length of the word
                count++; // increase word count/array index
                length = 0;  // reinit length
            }
            state = OUT;            
        }
        else { // non-space character
            state = IN;
            length++;
        }
    }
    printf("word count : %d\n", count);
    for (i = 0; i < 30; i++) {
        putchar('_');
    }
    putchar('\n');
    for (i = 0; i < count; i++) {
        for (j = 0; j < histogram[i]; j++) {
            putchar('_');
        }
        putchar('|');
        putchar('\n');  
    }
}