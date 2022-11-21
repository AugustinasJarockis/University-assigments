#include <stdio.h>
#include <math.h>

int main()
{
    printf("Program for printing all positive numbers in a giving range that has a remainder of 1 when divided by a certain number\n");
    printf("Insert 3 integers - two limits and a divisor: ");
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("Data inserted succesfully\n\n");
    if(a > b || b < 0)
    {
        printf("First number has to be smaller than the second which has to be larger than 0\n");
    }
    else
    {
        printf("Printing all positive numbers in range(%d; %d] that has a remainder of 1 when divided by %d:\n", a, b, c);
        if(c < 0)
            c = fabs(c);
        if(a < 0)
            a = 0;

        int number_to_check = (a / c) * c + c + 1;
        if(number_to_check <= b)
        {
            do
            {
                printf("%d\n", number_to_check);
                number_to_check += c;
            } while(number_to_check <= b);
        }
        printf("All numbers have been printed\n");
    }
    return 0;
}
