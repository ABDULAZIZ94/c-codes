#include <stdio.h>
#include <stdlib.h>

void bin(unsigned n);

int
main()
{
    int voltage = 254;  // 2 bytes
    int energy = 1450;  // 2 bytes
    int current = 1580; // 2 bytes
    char data[3] ={};
    long data_combine = 0L;

    voltage = voltage >> 2; //cut 2 bit
    data_combine += voltage;
    data_combine = data_combine << 9; //give bit space to next 9 bits of energy
    bin(voltage);
    printf("\n%d\n", voltage);

    energy = energy >> 2;
    data_combine += energy;
    data_combine = data_combine << 9; //give 9 bits space to next 9 bits of current
    bin(energy);
    printf("\n%d\n",energy);
    
    current = current >> 2;
    data_combine += current;
    bin(current);
    printf("\n%d\n", current);

    int s = sizeof(data_combine);
    bin(data_combine);
    // printf("\n%d\n",data_combine);
    return 0;
}

void bin(unsigned n)
{
    /* step 1 */
    if (n > 1)
        bin(n / 2);

    /* step 2 */
    printf("%d", n % 2);
}