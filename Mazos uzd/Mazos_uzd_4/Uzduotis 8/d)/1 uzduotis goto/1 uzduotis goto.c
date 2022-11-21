#include <stdio.h>
#include <math.h>

int main()
{
    printf("Program for finding solutions to quadratic equation\n");
    printf("Insert 3 integers - the coefficients of the formula: ");
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("Data inserted succesfully\n\n");
    int discriminant = b*b - 4 * a * c;
    if(discriminant > 0)
    {
        printf("Number of solutions: 2\n");
        printf("x1 = %f\n", (-b - sqrt(discriminant)) / (2 * a));
        printf("x2 = %f\n", (-b + sqrt(discriminant)) / (2 * a));
    }
    else if(discriminant == 0)
    {
        printf("Number of solutions: 1\n");
        printf("x = %f\n", (-b - sqrt(discriminant)) / (2 * a));
    }
    else
        printf("Number of solutions: 0\n");
    return 0;
}
