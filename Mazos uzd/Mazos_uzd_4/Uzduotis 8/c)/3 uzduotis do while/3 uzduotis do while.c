#include <stdio.h>
#include <math.h>

int main()
{
    printf("Program for printing a sequence of numbers in golden ratio\n");
    printf("Insert 3 positive integers - two first elements of the sequence and the number of elements to be printed: ");
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("Data inserted succesfully\n\n");
    if(a > b)
    {
        printf("First number has to be smaller than the second\n");
    }
    else
    {
        printf("Printing the sequence from %d to %d element\n", a, c);
        printf("0. %d\n", a);
        printf("1. %d\n", b);
        int element_nr = 2;
        int next_element = a + b;
        int previous_element = b;
        if(element_nr <= c)
        {
            do
            {
                printf("%d. %d\n", element_nr, next_element);
                int temp = next_element;
                next_element += previous_element;
                previous_element = temp;
                element_nr++;
            } while(element_nr <= c);
        }
        printf("All elements have been printed\n");
    }
    return 0;
}
