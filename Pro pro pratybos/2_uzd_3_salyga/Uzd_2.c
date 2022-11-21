#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define CAPACITY 10000

void Input(int* element_count, int vector[]);
int IsInputValid(char input[]);
void LargestDistanceBetweenTwoExtremes(int element_count, int vector[], int* extreme_1, int* extreme_2);
void Output(int extreme_1, int extreme_2);

int main()
{
    int element_count;
    int vector[CAPACITY];
    int extreme_1, extreme_2;
    int continue_program = 1;
    while(continue_program)
    {
        Input(&element_count, vector);
        LargestDistanceBetweenTwoExtremes(element_count, vector, &extreme_1, &extreme_2);
        Output(extreme_1, extreme_2);

        //Ask if user wants to continue working
        printf("\nContinue using the program? y/n\n");
        getchar();
        char answer = getchar();
        if(!(answer == 'y' || answer == 'Y'))
            continue_program = 0;
    }
    return 0;
}

void Input(int* element_count, int vector[])
{
    printf("Program to find greatest distance between two vector's extremes\n");
    printf("Insert vector element count\n");
    char input[10];
    //Get and check vector size input
    int ok_to_continue = 0;
    while(!ok_to_continue)
    {
        do
        {
            scanf("%s", &input);
        }
        while(!IsInputValid(input));
        *element_count = atoi(input);
        if(*element_count > 10000 || *element_count < 2)
            printf("Element count has to be between 2 and %d\n", CAPACITY);
        else
            ok_to_continue = 1;
    }
    //Get and check vector's elements' input
    printf("Insert %d integers\n", *element_count);
    for(int i = 0; i < *element_count; i++)
    {
        do
        {
            printf("Insert %d number: ", i + 1);
            scanf("%s", &input);
        }
        while(!IsInputValid(input));
        vector[i] = atoi(input);
    }
    printf("All values have been taken\n\n");
}

int IsInputValid(char input[])
{
    int i = 0;
    if(input[0] == '-')
        i = 1;
    for(; input[i] != '\0'; i++)
    {
        if(!isdigit(input[i]))
        {
            printf("Wrong input. Please input an integer\n");
            return 0;
        }
    }
    return 1;
}

void LargestDistanceBetweenTwoExtremes(int element_count, int vector[], int* extreme_1, int* extreme_2)
{
    int current_trend_start = 0;
    int is_increasing;
    if(vector[0] > vector[1])
        is_increasing = 1;
    else
        is_increasing = 0;
    //Go through entire vector and find the largest distance
    for(int i = 0; i < element_count - 1; i++)
    {
        if(is_increasing == 1 && vector[i] < vector[i + 1])
        {
            is_increasing = 0;
            if(i - current_trend_start > *extreme_2 - *extreme_1)
            {
                *extreme_2 = i;
                *extreme_1 = current_trend_start;
            }
            current_trend_start = i;
        }
        else if(is_increasing == 0 && vector[i] > vector[i + 1])
        {
            is_increasing = 1;
            if(i - current_trend_start > *extreme_2 - *extreme_1)
            {
                *extreme_2 = i;
                *extreme_1 = current_trend_start;
            }
            current_trend_start = i;
        }
    }
    if(element_count - current_trend_start - 1 > *extreme_2 - *extreme_1)
    {
        *extreme_2 = element_count - 1;
        *extreme_1 = current_trend_start;
    }
}

void Output(int extreme_1, int extreme_2)
{
    printf("Largest distance between two vector's extremes is %d, between elements %d and %d\n", extreme_2 - extreme_1, extreme_1 + 1, extreme_2 + 1);
}
//13:07 |Backslash |forgot element count stsrs |need double getchar |forgot to check end
//14:08 kodas baigtas dar nebent commentarai
