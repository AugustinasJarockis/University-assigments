#include <stdio.h>

int main()
{
    int x0;
    printf("Iveskite pirmaji sekos nari: ");
    scanf("%d", &x0);
    int xn = x0;
    if(xn > 0)
    {
        printf("\nSekos nariai: \n");
        while (xn != 1)
        {
            printf("%d", xn);
            printf("\n");
            if(xn % 2 == 0)
            {
                xn /= 2;
            }
            else
            {
                xn = 3 * xn + 1;
            }
        }
        printf("%d", xn);
        printf("\n");
    }
    else
    {
        printf("Ivestis neteisinga");
    }
    return 0;
}
