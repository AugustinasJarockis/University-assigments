#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 1000

int* createArray(int size, int low, int high);
int generateArray(int *data, int size, int low, int high);

int main()
{
    int* array = createArray(10, -5, 5);
    for(int i = 0; i < 10; i++)
    {
        printf("%d\n", array[i]);
    }
    free(array);
    return 0;
}

int* createArray(int size, int low, int high)
{
    int* array = malloc(size * sizeof(int));
    if(array == NULL || generateArray(array, size, low, high) == -1)
        return NULL;
    return array;
}

int generateArray(int *data, int size, int low, int high)
{
    if(size > CAPACITY || low >= high)
    {
        printf("Incorrect arguments passed to function\n");
        return -1;
    }

    for(int i = 0; i < size; i++)
    {
        *(data + i) = rand() % (high - low) + low;
    }

    return 0;
}
