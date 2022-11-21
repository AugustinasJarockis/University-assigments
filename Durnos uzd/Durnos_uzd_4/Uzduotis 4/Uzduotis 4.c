#include <stdio.h>
#include <math.h>

int GreatestCommonDivisor(int a, int b);

int main()
{
    printf("Program to find greatest common divisor and least common multiple\n");
    printf("Insert 3 integers: ");
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("Data inserted succesfully\n\n");
    int gcd1 = GreatestCommonDivisor(a, b);
    int gcd2 = GreatestCommonDivisor(gcd1, c);
    int lcm1 = a * b / gcd1;
    int gcd_su_lcm = GreatestCommonDivisor(lcm1, c);
    int lcm2 = (lcm1 * c) / gcd_su_lcm;
    printf("Greatest common divisor: %d\n", gcd2);
    printf("Least common multiple: %d\n", lcm2);
    return 0;
}

int GreatestCommonDivisor(int a, int b)
{
    if(a > b)
    {
        int temp = b;
        b = a;
        a = temp;
    }

    if(a == 0)
    {
        return b;
    }
    else
    {
        return GreatestCommonDivisor(b % a, a);
    }
}
