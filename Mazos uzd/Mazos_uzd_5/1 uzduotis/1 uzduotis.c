#include <stdio.h>

#define CAPACITY 10

int main()
{
    printf("Program to manipulate an array\n");

    //Declaration
    int array[CAPACITY] = { 0 };
    int array_size = CAPACITY;

    //Printment
    printf("Original array values:\n");
    for(int i = 0; i < array_size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    //Assignment
    array[0] = 1;
    array[3] = 2;
    array[9] = 3;

    //Erasure
    for(int i = 2; i < array_size - 1; i++)
    {
        array[i] = array[i + 1];
    }
    array_size--;

    //Insertment
    int temp = array[6];
    array[6] = 4;
    for(int i = 7; i < array_size + 1; i++)
    {
        int super_temp = array[i];
        array[i] = temp;
        temp = super_temp;
    }
    array_size++;

    //Printment
    printf("Array values after assignment, insertment and erasure:\n");
    for(int i = 0; i < array_size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    //Integers input
    int x, y;
    printf("Insert two integers: array index ([0; %d]) and value to assign\n", array_size);
    scanf("%d %d", &x, &y);
    printf("Data acquired succesfully\n");
    array[x] = y;
    printf("Element modified succesfully\n");

    //Input erasure
    printf("Insert an integer: array index ([0; %d]) of a value to erase\n", array_size);
    scanf("%d", &x);
    printf("Data acquired succesfully\n");
    for(int i = x; i < array_size - 1; i++)
    {
        array[i] = array[i + 1];
    }
    array_size--;
    printf("Element erased succesfully\n");

    //Input insertment
    printf("Insert two integers: array index ([0; %d]) and value to insert\n", array_size);
    scanf("%d %d", &x, &y);
    printf("Data acquired succesfully\n");
    temp = array[x];
    array[x] = y;
    for(int i = x + 1; i < array_size + 1; i++)
    {
        int super_temp = array[i];
        array[i] = temp;
        temp = super_temp;
    }
    array_size++;

    //Printment
    printf("Array values after all operations:\n");
    for(int i = 0; i < array_size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}
