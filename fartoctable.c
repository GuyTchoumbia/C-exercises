#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20

main() {
    int fahr;

    printf("%4s %6s\n", "T(°F)", "T(°C)");

    for (fahr = UPPER; fahr >= LOWER; fahr -= STEP) {
        printf("%4d %6.1f\n", fahr, (5.0 / 9.0) * (fahr -32));
    }
}