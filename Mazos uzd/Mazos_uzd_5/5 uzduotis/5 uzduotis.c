#include <stdio.h>
#include <string.h>

#define CAPACITY 1000

int IsPossible(char x[], int number);
void RemoveChar(char x[], int address);

int main()
{
    printf("Program to find if all set's numbers' digits have an equivalent in the first number\n");

    int set[CAPACITY];
    int set_size = 0;
    char x[CAPACITY];

    printf("Insert an integer. It will be the number others will be checked against: ");
    scanf("%s", &x);
    printf("Insert positive integers. First negative integer will mark the end of the set\n");
    for(set_size = 0; ; set_size++)
    {
        if(set_size > CAPACITY)
        {
            printf("Maximum capacity exceeded\n");
            break;
        }
        printf("Insert value number %d: ", set_size + 1);
        scanf("%d", &set[set_size]);
        if(set[set_size] <= 0)
        {
            break;
        }
    }
    printf("All values have been taken.\n");
    int all_posssible = 1;
    for(int i = 0; i < set_size; i++)
    {
        char x_copy[CAPACITY];
        strcpy(x_copy, x);
        if(!IsPossible(x_copy, set[i]))
        {
            all_posssible = 0;
            break;
        }
    }
    if(all_posssible == 1)
        printf("All numbers from the set can be made from digits of %s\n", x);
    else
        printf("Not all numbers from the set can be made from digits of %s\n", x);

    return 0;
}

int IsPossible(char x[], int number)
{
    while(number != 0)
    {
        char char_to_find = number % 10 + 48;
        int char_found = 0;
        for(int i = 0; x[i] != '\0'; i++)
        {
            if(x[i] == char_to_find)
            {
                RemoveChar(x, i);
                char_found = 1;
                break;
            }
        }
        if(char_found == 0)
            return 0;
        number /= 10;
    }
    return 1;
}

void RemoveChar(char x[], int index)
{
    for(int i = index; i == 0 || x[i - 1] != '\0'; i++)
    {
        x[i] = x[i + 1];
    }
}
