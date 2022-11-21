#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int IsInputValid(char input[]);
int Input();
int FindFactorial(int number);
void Output(int number, int result);

int main()
{
    int number = Input();
    int result = FindFactorial(number);
    Output(number, result);
    return 0;
}

int IsInputValid(char input[])
{
    for(int i = 0; input[i] != '\0'; i++)
    {
        if(!isdigit(input[i]))
        {
            printf("Wrong input. Please input a positive integer\n");
            return 0;
        }
    }
    if(atoi(input) == 0)
        printf("Wrong input. Input has to be larger than 0\n");
    return 1;
}

int Input()
{
    printf("Program to find number's factorial\n");
    printf("Insert a positive integer\n");
    char input[10];
    int number;
    do
    {
        scanf("%s", &input);
    }
    while(!IsInputValid(input));
    number = atoi(input);
    printf("Value taken\n\n");
    return number;
}

int FindFactorial(int number)
{
    int result = 1;
    for(int i = 2; i <= number; i++)
    {
        result *= i;
    }
    return result;
}
void Output(int number, int result)
{
    printf("%d! = %d", number, result);
    FILE* f = fopen("out.txt", "w");
    fprintf(f, "%d! = %d", number, result);
    fclose(f);
}
