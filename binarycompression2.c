#include <stdio.h>
#include <stdlib.h>

void bin(unsigned n);
struct data_transfer *binarytocharary(unsigned long data);

struct data_transfer{
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
    unsigned long data_combine = 0L;

    voltage = voltage >> 2; //cut 2 bit
    data_combine += voltage;
    data_combine = data_combine << 9; //give bit space to next 9 bits of energy
    // bin(voltage);
    // printf("\n%d\n", voltage);

    energy = energy >> 2;
    data_combine += energy;
    data_combine = data_combine << 9; //give 9 bits space to next 9 bits of current
    // bin(energy);
    // printf("\n%d\n",energy);
    
    current = current >> 2;
    data_combine += current;
    // bin(current);
    // printf("\n%d\n", current);

    // printf("data combine in decimal: %d\n", data_combine);

    // int s = sizeof(data_combine);
    data = binarytocharary(data_combine);
    // printf("\n\n");
    // bin(data_combine);
    // printf("\n");
    // bin(data[0]);
    // printf("\n");
    // printf("\n%s\n", data_combine);
    return 0;
}

struct data_transfer * binarytocharary(unsigned long data){
    // unsigned char trans[3] = {};
    // unsigned char *transfer = trans;
    struct data_transfer * data_trans = malloc(sizeof(struct data_transfer));
    // int c = 0;
    // int iteration = 0;

    data_trans->first_byte = data & 0b11111111;
    data = data >> 8;
    data_trans->second_byte = data & 0b11111111;
    data = data >> 8;
    data_trans->third_byte = data & 0b11111111;
    // for(int i= 0; i<3; i++){
    //     trans[i] = data & 0b11111111;
    //     data = data >> 8;
    //     bin(trans[i]);
    //     printf("\n");
    // }

    // char c1 = data & 0xF;
    // printf("\n\nc1: ");
    // bin(c1);
    // printf("\n");
    // printf("data: ");
    // bin(data);
    // printf("\n");
    // printf("hex:0x%.1X char c1:%c decimal c1:%d sizeof c1:%d",c1, c1, c1, sizeof(c1));

    // data = data >> 4;
    // c1 = data & 0xF;
    // printf("\n\nc1: ");
    // bin(c1);
    // printf("\n");
    // printf("data: ");
    // bin(data);
    // printf("\n");
    // printf("hex:0x%.1X char c1:%c decimal c1:%d sizeof c1:%d", c1, c1, c1, sizeof(c1));

    // while(data>0){
        
    //     c += data % 2;
    //     // printf("binary c: ");
    //     // bin(c);
    //     // printf("\n");

    //     // printf("c: %d data: %d \n",c , data);
    //     data = (data / 2);
        
    //     // 8 times = 1 char
    //     if (iteration % 8 == 0)
    //     {
    //         int i = iteration / 8;
    //         transfer[i] = (char) c;
    //         printf("i: %d trans: %d\n",i, transfer[i]);
    //     }
        
    //     iteration += 1;

    // }
    // printf("\n");
    return data_trans;
}

// void bin(unsigned n)
// {
//     /* step 1 */
//     if (n > 1)
//         bin(n / 2);

//     /* step 2 */
//     printf("%d", n % 2);
// }