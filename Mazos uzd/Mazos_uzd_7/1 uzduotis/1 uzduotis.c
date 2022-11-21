#include <stdio.h>

int isInRange(int number, int low, int high);

int main()
{
    printf("%d", isInRange(1, 1, 4));
    return 0;
}

int isInRange(int number, int low, int high)
{
    if(low > high || number < low || number > high)
        return 0;
    return 1;
}
