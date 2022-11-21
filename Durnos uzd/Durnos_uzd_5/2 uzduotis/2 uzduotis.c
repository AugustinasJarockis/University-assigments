#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CAPACITY 1000

int main()
{
    srand(time(NULL));
    printf("Program to generate a certain number of random numbers\n");
    printf("Insert 3 positive integers: two limits and number of values to generate: ");
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("Data acquired\n\n");
    int array[CAPACITY];

    if(a >= b)
    {
        printf("First value has to be smaller than the second\n");
    }
    else
    {
        if(c > 1000)
        {
            printf("Exceeded array bounds. Printing 1000 numbers instead:\n");
            c = 1000;
        }
        for(int i = 0; i < c; i++)
        {
            array[i] = rand() % (b - a) + a;
            printf("Value nr %4d: %d\n", i + 1, array[i]);
        }
    }
    return 0;
}
