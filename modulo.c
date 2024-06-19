// C Program to illustrate the working of modulo operator
#include <stdio.h>

int main(void)
{
    int x, y;
    int voltage = 254; // 2 bytes
    int result;

    x = 3;
    y = 4;
    // using modulo operator
    result = x % y;
    printf("3 mod 4: %d", result);
    
    result = voltage % 3;
    printf("\nvoltage mod 3: %d", result);

    result = y % x;
    printf("\n4 mod 3: %d", result);

    // for different values
    x = 4;
    y = 2;
    result = x % y;
    printf("\n4 mod 2: %d\n", result);

    return 0;
}
