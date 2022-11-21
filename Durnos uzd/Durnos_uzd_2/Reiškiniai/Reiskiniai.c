#include <stdio.h>
#include <math.h>

int main()
{
    double x, y, z;
    printf("Iveskite tris realiuosius skaicius: ");
    scanf("%lf%lf%lf", &x, &y, &z);
    double rez1 = x + 4*y + pow(z, 3);
    double rez2 = (x + sqrt(y)) * (pow(z, 4) - fabs(z) + 46.3);
    printf("x + 4y + z^3 = %.2f\n", rez1);
    printf("(x + sqrt(y))(z^4-|z|+46.3) = %.2f\n", rez2);
    return 0;
}
