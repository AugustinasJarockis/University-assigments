#include <stdio.h>

int main()
{
    while(1)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        printf("Didziausias: %d\nMaziausias: %d\n", a > b ? a > c ? a : c : b > c ? b : c, a < b ? a < c ? a : c : b < c ? b : c);
    }
    return 0;
}
