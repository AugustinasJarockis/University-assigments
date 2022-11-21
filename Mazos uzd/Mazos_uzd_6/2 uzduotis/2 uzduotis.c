#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int IsInputValid(char input[]);
void Input(char number[]);
int FindLength(char number[]);
void Output(char number[], int result);

int main()
{
    char number[10];
    Input(number);
    int result = FindLength(number);
    Output(number, result);
    return 0;
}

int IsInputValid(char input[])
{
    int i = 0;
    if(input[0] == '-')
    {
        printf("Wrong input. Input has to be between 10 and 1000\n");
        return 0;
    }
    for(; input[i] != ','; i++)
    {
        if(!isdigit(input[i]))
        {
            printf("Wrong input. Please input a real number\n");
            return 0;
        }
    }
    input[i] = '.';
    for(int i2 = 1; input[i + i2] != '\0'; i2++)
    {
        if(!isdigit(input[i + i2]))
        {
            printf("Wrong input. Please input a real number\n");
            return 0;
        }
        if(i2 > 3)
        {
            printf("Wrong input. Only 3 decimal places are allowed\n");
            return 0;
        }
    }
    if(atoi(input) < 10 || atoi(input) > 1000)
        printf("Wrong input. Input has to be between 10 and 1000\n");
    input[i] = ',';
    return 1;
}

void Input(char number[])
{
    printf("Program to find number's digit count\n");
    do
    {
        FILE* f;
        do
        {
            printf("Insert a name of a file containing a real number no smaller than 10 and no larger than 1000\n");
            char file_name[300];
            scanf("%s", &file_name);
            f = fopen(file_name, "r");
        } while(!f && (printf("File not found\n"), 1));
        printf("File found\n");
        fscanf(f, "%s", number);
        fclose(f);
    }
    while(!IsInputValid(number));
    printf("Value taken\n\n");
}

int FindLength(char number[])
{
    int length = 0;
    int is_dot_present = 0;
    for(; number[length] != '\0'; length++)
    {
        if(number[length] == ',')
            is_dot_present = 1;
    }
    return length - is_dot_present;
}

void Output(char number[], int result)
{
    printf("Length of %s = %d", number, result);
}
