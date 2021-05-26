#include <stdio.h>

void inplace_swap(int *x, int *y)
{
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

void reverse_array(int a[], int len)
{
    int first, last;
    for (first = 0, last = len - 1; first < last; first++, last--)
    {
        inplace_swap(&a[first], &a[last]);
    }
}

void print_arr(int a[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ->", a[i]);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6,7};
    int len = 7;

    printf("Before revese: \n");
    print_arr(arr, len);
    printf("\n");

    reverse_array(arr, len);

    printf("after revese: \n");
    print_arr(arr, len);
    printf("\n");

    return 0;
}