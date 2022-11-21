#include <stdio.h>
#include <math.h>

#define CAPACITY 10000

int main()
{
    printf("Program for finding sum, average, maximum and minimum values in a given set\n");
    printf("Insert a positive integer - number of set's elements: ");
    int n;
    float set[CAPACITY];
    scanf("%d", &n);
    printf("\nInsert %d real numbers\n", n);
    if(n < 1 || n > CAPACITY)
    {
        printf("The number has to be an integer in range [1; %d]\n", CAPACITY);
    }
    else
    {
        float sum = 0, average, max = -214748364, min = 214748364;
        int i = 0;
        do
        {
            printf("Insert %d number of the set: ", i + 1);
            scanf("%f", &set[i]);
            if(set[i] > max)
                max = set[i];
            if(set[i] < min)
                min = set[i];
            sum += set[i];
            i++;
        } while(i < n);
        printf("All numbers have been inserted\n\n");
        average = sum / n;
        printf("Set sum: %.3f\n", sum);
        printf("Set average: %.3f\n", average);
        printf("Set maximum: %.3f\n", max);
        printf("Set minimum: %.3f\n", min);
    }
    return 0;
}
