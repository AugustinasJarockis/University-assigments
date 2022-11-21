#include <stdio.h>

void swap(int *a, int *b);

int main()
{
    int a = 5, b = -887;
    printf("%d <-> %d\n", a, b);
    swap(&a, &b);
    printf("%d <-> %d\n", a, b);
    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
