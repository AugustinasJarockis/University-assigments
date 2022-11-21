#include <stdio.h>
#include <stdlib.h>

int splitData(int *original_array, int original_size, int first_size, int **first_array, int **second_array);

int main()
{
    int array[] = {4,5,6,4,68,7,6551,6884,6654,684,684};
    int *first = NULL;
    int *second = NULL;
    printf("%d\n", splitData(array, 10, 6, &first, &second));
    for(int i = 0; i < 6; i++)
    {
        printf("%d\n", first[i]);
    }
    printf("==================\n");
    for(int i = 0; i < 4; i++)
    {
        printf("%d\n", second[i]);
    }
    return 0;
}

int splitData(int *original_array, int original_size, int first_size, int **first_array, int **second_array)
{
    if(original_array == NULL || *first_array != NULL || *second_array != NULL || original_size <= 0 || first_size > original_size || first_size < 0)
        return -1;

    *first_array = malloc(sizeof(int) * first_size);
    *second_array = malloc(sizeof(int) * (original_size - first_size));

    if(*first_array == NULL || *second_array == NULL)
        return -1;

    for(int i = 0; i < first_size; i++)
    {
        (*first_array)[i] = original_array[i];
    }
    for(int i = 0; i < original_size - first_size; i++)
    {
        (*second_array)[i] = original_array[i + first_size];
    }

    return 0;
}
