#include <stdio.h>
#include <string.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        printf(" %.2x ", start[i]);
    }

    printf("\n");
}

void show_int(int x)
{
    show_bytes((byte_pointer)&x, sizeof(int));
}

void show_float(float x)
{
    show_bytes((byte_pointer)&x, sizeof(float));
}

void show_pointer(void *x)
{
    show_bytes((byte_pointer)&x, sizeof(void *));
}

void inplace_swap(int *x, int *y)
{
    *y = *x ^ *y;
    printf("Step1 result: %d, %d\n", *x, *y);

    *x = *x ^ *y; // = *x ^ *x ^ *y = *y
    printf("Step2 reulst: %d, %d\n", *x, *y);

    *y = *x ^ *y; // = (*x ^ *x ^ *y) ^ (*x ^ *y) = *x
    printf("Step3 result: %d, %d\n", *x, *y);
}

int main()
{

    int intVal = 12345;

    float floatVal = 12345.0;

    int *pVal = &intVal;

    show_int(intVal);

    show_float(floatVal);

    show_pointer(pVal);

    int a = 0x12345678;
    byte_pointer ap = (byte_pointer)&a;
    show_bytes(ap, 1); /* A. */
    show_bytes(ap, 2); /* B. */
    show_bytes(ap, 3); /* C. */

    const char *m = "mnopqr";
    show_bytes((byte_pointer)m, strlen(m));

    int one = 10;
    int two = 20;

    printf("before swap: %d, %d \n", one, two);

    inplace_swap(&one, &two);

    printf("swap result: %d, %d \n", one, two);

    return 0;
}