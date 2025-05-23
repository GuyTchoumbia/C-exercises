#include <stdio.h>

main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("%6s %4s\n", "T(°C)", "T(°F)");

    celsius = lower;
    while (celsius <= upper) {
        fahr = (9.0 / 5.0) * (celsius + 32.0);
        printf("%4.0f %6.1f\n", celsius, fahr);
        celsius += step;
    }
}