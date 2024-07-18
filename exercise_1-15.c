#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float fahrtocels(float temp);

int main() {
    float fahr;
    printf("%4s %6s\n", "T(°F)", "T(°C)");

    for (fahr = LOWER; fahr <= UPPER; fahr += STEP) {
        printf("%4.0f %6.1f\n", fahr, fahrtocels(fahr));
    }
    return 0;    
}

float fahrtocels(float fahr) {
    return  (5.0 / 9.0) * (fahr - 32);
}