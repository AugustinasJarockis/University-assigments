#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 1000

void generateArray(int data[], int size, int low, int high);

int main()
{
    int data[CAPACITY];
    generateArray(data, 100, 0, 100);
    for(int i = 0; i < 100; i++)
        printf("%d\n", data[i]);
    return 0;
}

void generateArray(int data[], int size, int low, int high)
{
    if(size > CAPACITY || low >= high)
    {
        printf("Incorrect arguments passed to function\n");
        return;
    }

    for(int i = 0; i < size; i++)
    {
        data[i] = rand() % (high - low) + low;
    }
}
