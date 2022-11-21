#include <stdio.h>
#include <math.h>
#include <string.h>

#define CAPACITY 1000

int StringSize(char string[]);

int main()
{
    printf("Program for finding a number with largest amount of digits\n");
    printf("Insert a series of positive integers. The first negative integer will be considered to be the end of the set\n");
    char numbers_with_most_digits[CAPACITY][256];
    int largest_number_count = 0;
    char number[256];
    int max_size = 0;
    do
    {
        scanf("%s", &number);
        int size = StringSize(number);
        if(max_size < size)
        {
            max_size = size;
            largest_number_count = 1;
            strcpy(numbers_with_most_digits[0], number);
        }
        else if(max_size == size)
        {
            strcpy(numbers_with_most_digits[largest_number_count], number);
            largest_number_count++;
        }
    }
    while(number[0] != '-');
    if(max_size == 0)
    {
        printf("Please input at least one positive integer\n");
    }
    else
    {
        printf("Numbers with largest amount of digits:\n");
        int i = 0;
        do
        {
            printf("%4d. %s <- %d digits\n", i + 1, numbers_with_most_digits[i], max_size);
            i++;
        } while(i < largest_number_count);
        printf("All numbers have been printed\n");
    }
    return 0;
}

int StringSize(char string[])
{
    int size = 0;
    if(string[size] != '\0' && string[size] != '-')
    {
        do
            size++;
        while(string[size] != '\0' && string[size] != '-');
    }
    return size;
}
