#include <stdio.h>
int main(void)
{
    char a[10]="poiuytr";
    char *c = a;
    char *b = "abcdefghi";

    printf("%c", c[0]);
    return 0;
}