#include <stdio.h>

#define CAPACITY 1000

int main()
{
    printf("Program to find all values from the set the multiplication of which is equal to a value\n");
    printf("Insert 2 positive integers: the result of multiplication that should be found and number of element in the set: ");

    int s, n;
    scanf("%d%d", &s, &n);
    if(n > CAPACITY)
    {
        printf("Maximum number of elements is %d\n", CAPACITY);
    }
    else
    {
        printf("Now insert %d positive intergers:\n", n);
        int x[CAPACITY];
        for(int i = 0; i < n; i++)
        {
            printf("Insert value number %d: ", i + 1);
            scanf("%d", &x[i]);
            if(x[i] <= 0)
            {
                i--;
                printf("Value has to be positive. Please insert new value.\n");
            }
        }
        printf("All values have been taken.\n");
        printf("Printing all pairs of values the product of which is equal to %d:\n", s);
        int pair_count = 1;
        for(int i = 0; i < n; i++)
        {
            for(int i2 = i + 1; i2 < n; i2++)
            {
                if(x[i] * x[i2] == s)
                {
                    printf("%d. [%d] %d, [%d] %d\n", pair_count, i, x[i], i2, x[i2]);
                    pair_count++;
                }
            }
        }
        if(pair_count == 1)
            printf("There are no pairs of values with a product of %d\n", s);
        else
            printf("All pairs have been printed\n");
    }
    return 0;
}
