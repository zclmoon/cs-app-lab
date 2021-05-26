#include <stdio.h>

int main()
{
    int64_t x = 0x87654321;

    printf("x: 0x%08x\n", x);

    // problem A
    int64_t mask1 = 0x000000FF;
    int64_t result1 = x & mask1;

    printf("result1: 0x%08x\n", result1);


    int64_t mask2 = 0xFFFFFF00;
    int64_t result2 = x ^ mask2;

    printf("result1: 0x%08x\n", result2);


    int64_t mask3 = 0x000000FF;
    int64_t result3 = x | mask3;

    printf("result1: 0x%08x\n", result3);

    return 0;
}