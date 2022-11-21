#include <stdio.h>

#define CAPACITY 1000

void SortArray(int arr[], int arr_size);

int main()
{
    printf("Program to divide a set into two sets with similar sums\n");

    int set[CAPACITY];
    int first_set[CAPACITY];
    int second_set[CAPACITY];
    int set_size = 0;
    int second_set_size = 0;
    int first_set_size = 0;
    int first_set_sum = 0;
    int second_set_sum = 0;
    long long x;

    printf("Insert positive integers. First negative integer will mark the end of the set\n");
    for(set_size = 0; ; set_size++)
    {
        if(set_size > CAPACITY)
        {
            printf("Maximum capacity exceeded\n");
            break;
        }
        printf("Insert value number %d: ", set_size + 1);
        scanf("%d", &set[set_size]);
        if(set[set_size] <= 0)
        {
            break;
        }
    }
    printf("All values have been taken.\n");

    SortArray(set, set_size);
    for(int i = 0; i < set_size; i++)
    {
        if(first_set_sum <= second_set_sum)
        {
            first_set[first_set_size] = set[i];
            first_set_size++;
            first_set_sum += set[i];
        }
        else
        {
            second_set[second_set_size] = set[i];
            second_set_size++;
            second_set_sum += set[i];
        }
    }

    //Print both arrays
    printf("First set:\n");
    for(int i = 0; i < first_set_size; i++)
    {
        printf("%d. %d\n", i + 1, first_set[i]);
    }
    printf("\n");
    printf("Second set:\n");
    for(int i = 0; i < second_set_size; i++)
    {
        printf("%d. %d\n", i + 1, second_set[i]);
    }

    printf("\nAll values have been printed.\n");
    return 0;
}

void SortArray(int arr[], int arr_size)
{
    for(int i = 0; i < arr_size; i++)
    {
        for(int i2 = 0; i2 < arr_size - 1; i2++)
        {
            if(arr[i2] < arr[i2 + 1])
            {
                int temp = arr[i2];
                arr[i2] = arr[i2 + 1];
                arr[i2 + 1] = temp;
            }
        }
    }
}
