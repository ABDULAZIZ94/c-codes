#include<stdio.h>

int main(){
    int voltage = 254;  // 2 bytes
    int energy = 1450;  // 2 bytes
    int current = 1580; // 2 bytes
    int temp ;
    int result;

    unsigned long data_combine = 0L;

    // voltage = voltage - (voltage % 3) / 3;
    voltage = voltage % 3;
    printf("voltage mod 3: %d\n", voltage);
    voltage = 254 / 3;
    printf("voltage: %d\n", voltage);
    temp = voltage % 3; //84 % 3
    printf("temp voltage: %d\n", temp);
    voltage = 254 % 3;
    printf("voltage: %d\n", voltage);
    voltage = 84;
    printf("voltage: %d\n", voltage);
    return 0;
}