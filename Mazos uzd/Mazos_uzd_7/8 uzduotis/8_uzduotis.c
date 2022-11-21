#include <stdio.h>

#define CAPACITY 10000

int partition(int array[], int low, int high);
void quickSort(int array[], int low, int high);

int main()
{
    int array[CAPACITY];
    for(int i = 0; i < CAPACITY; i++)
    {
        array[i] = CAPACITY - i - 1;
    }

    for(int i = 0; i < CAPACITY; i++)
    {
        printf("%d\n", array[i]);
    }
    quickSortNonRecursive(array, 0, CAPACITY - 1);
    printf("==============================================================================================================================\n");
    for(int i = 0; i < CAPACITY; i++)
    {
        printf("%d\n", array[i]);
    }
    return 0;
}
void quickSortNonRecursive(int array[], int low, int high)
{
    int pivots[CAPACITY][2];
    pivots[0][0] = low;
    pivots[0][1] = high;

    int comparasson_count = 1;
    for(int i = 0; i < comparasson_count; i++)
    {
        int new_pivot = partition(array, pivots[i][0], pivots[i][1]);

        if(pivots[i][0] < new_pivot)
        {
            pivots[comparasson_count][0] = pivots[i][0];
            pivots[comparasson_count][1] = new_pivot - 1;
            comparasson_count++;
        }
        if(new_pivot < pivots[i][1])
        {
            pivots[comparasson_count][0] = new_pivot + 1;
            pivots[comparasson_count][1] = pivots[i][1];
            comparasson_count++;
        }
    }
}

void quickSort(int array[], int low, int high)
{
    if(low < high)
    {
        int part = partition(array, low, high);

        quickSort(array, low, part - 1);
        quickSort(array, part + 1, high);
    }
}

int partition(int array[], int low, int high)
{
    int pivot = array[high];

    int i = low - 1;

    for(int i2 = low; i2 < high; i2++)
    {
        if(array[i2] <= pivot)
        {
            i++;

            int temp = array[i];
            array[i] = array[i2];
            array[i2] = temp;
        }
    }

    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    return i + 1;
}
