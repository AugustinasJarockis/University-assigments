#include <stdio.h>

int getFactorial(int number);
int getFactorialNoRecursion(int number);

int main()
{
    printf("%d", getFactorialNoRecursion(-5));
    return 0;
}

int getFactorial(int number)
{
    if(number < 0)
        return 0;
    if(number == 0 || number == 1)
        return 1;
    return number * getFactorial(number - 1);
}

int getFactorialNoRecursion(int number)
{
    if(number < 0)
        return 0;
    if(number == 0 || number == 1)
        return 1;

    int result = number;
    while(number != 2)
    {
        number--;
        result *= number;
    }
    return result;
}
