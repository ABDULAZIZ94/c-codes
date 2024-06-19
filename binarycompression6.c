#include <stdio.h>
#include <stdlib.h>

void bin(unsigned n);
struct data_transfer *binarytocharary(unsigned long data);
int *datatransfertointarry(struct data_transfer *data);

struct data_transfer
{
    unsigned char first_byte;
    unsigned char second_byte;
    unsigned char third_byte;
};

int main()
{
    int voltage = 254;  // 2 bytes
    int energy = 1450;  // 2 bytes
    int current = 1580; // 2 bytes
    struct data_transfer *data;
    int *decoded_data;
    unsigned long data_combine = 0L;

    // voltage = (voltage - (voltage % 3)) / 3;
    voltage = voltage >> 2; // cut 2 bit
    data_combine += voltage;
    data_combine = data_combine << 9; // give bit space to next 9 bits of energy
    bin(voltage);
    printf("\n%d\n", voltage);

    // energy = (energy - (energy % 3)) / 3;
    energy = energy >> 2; // cut 2 bit
    data_combine += energy;
    data_combine = data_combine << 9; // give 9 bits space to next 9 bits of current
    bin(energy);
    printf("\n%d\n", energy);

    // current = (current - (current % 3)) / 3;
    current = current >> 2; // cut bit
    data_combine += current;
    bin(current);
    printf("\n%d\n", current);

    printf("\nData Combine: %d\n", data_combine);
    data = binarytocharary(data_combine);

    printf("\nFirst Byte: %d\n", data->first_byte);
    printf("Second Byte: %d\n", data->second_byte);
    printf("Third Byte: %d\n", data->third_byte);

    decoded_data = datatransfertointarry(data);
    // printf("\nDecoded data 1: %d", decoded_data);
    // printf("\nDecoded data 2: %d", decoded_data);
    // printf("\nDecoded data 3: %d\n", decoded_data);
    return 0;
}

struct data_transfer *binarytocharary(unsigned long data)
{
    struct data_transfer *data_trans = malloc(sizeof(struct data_transfer));

    data_trans->third_byte = data & 0xFF;
    data = data >> 8;
    data_trans->second_byte = data & 0xFF;
    data = data >> 8;
    data_trans->first_byte = data & 0xFF;
    printf("\nInside binary to chararray\n");
    printf("\nFirst Byte: %d\n", data_trans->first_byte);
    bin(data_trans->first_byte);
    printf("\nSecond Byte: %d\n", data_trans->second_byte);
    bin(data_trans->second_byte);
    printf("\nThird Byte: %d\n", data_trans->third_byte);
    bin(data_trans->third_byte);

    return data_trans;
}

int *datatransfertointarry(struct data_transfer *data)
{
    unsigned long temp_combine = 0L;
    unsigned int data_ary[3];
    int *data_ary_ptr = &data_ary;
    int accurancy = 2;

    temp_combine = data->first_byte | temp_combine;
    temp_combine = temp_combine << 8;
    printf("\ndecode temp_combine: %d\n", temp_combine);
    bin(temp_combine);
    temp_combine = data->second_byte | temp_combine;
    temp_combine = temp_combine << 8;
    printf("\ndecode temp_combine: %d\n", temp_combine);
    bin(temp_combine);
    temp_combine = data->third_byte | temp_combine;
    printf("\ndecode temp_combine: %d\n", temp_combine);
    bin(temp_combine);

    data_ary[2] = temp_combine & 0b111111111; // copy 9 bit
    printf("\n data 3: %d", data_ary[2]);
    temp_combine = temp_combine >> 9;
    data_ary[2] = data_ary[2] << 2; // to 11 bit, times 4

    data_ary[1] = temp_combine & 0b111111111; // copy 9 bit
    printf("\n data 2: %d", data_ary[1]);
    temp_combine = temp_combine >> 9;
    data_ary[1] = data_ary[1] << 2; // to 11 bit, times 4

    data_ary[0] = temp_combine & 0b111111; // copy 6 bit
    printf("\n data 1: %d\n", data_ary[0]);
    // temp_combine =  temp_combine >> 6;
    data_ary[0] = data_ary[0] << 2; // to 11 bit, times 4

    printf("\n data 1: %d", (int)data_ary[0] + accurancy);
    printf("\n data 2: %d", (int)data_ary[1] + accurancy);
    printf("\n data 3: %d\n", (int)data_ary[2] + accurancy);
    return data_ary_ptr;
}

void bin(unsigned n)
{
    if (n > 1)
        bin(n / 2);

    printf("%d", n % 2);
}