#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define FAIL_LIMIT 5

int IsInputValid(char input[]);
void Input(char number[]);
FILE* File_Name_Input();
void FindMiddleNumber(char number[], char answer[]);
void Output(FILE* f, char answer[]);

int main()
{
    char number[300];
    Input(number);
    char answer[300];
    FindMiddleNumber(number, answer);
    Output(File_Name_Input(), answer);
    return 0;
}

int IsInputValid(char input[])
{
    int last_was_semicolon = 1;
    int dot_was = 0;
    int semicolon_count = 0;
    for(int i = 0; input[i] != '\0'; i++)
    {
        if(!isdigit(input[i]) && !((input[i] == '.' || input[i] == ',') &&
           !dot_was && !last_was_semicolon) && !(input[i] == ';' && semicolon_count < 2) && !(input[i] == '-' && last_was_semicolon == 1))
        {
            printf("Wrong input. Please try again\n");
            return 0;
        }
        if(input[i] == '.' || input[i] == ',')
            dot_was = 1;
        if(last_was_semicolon)
            last_was_semicolon = 0;
        if(input[i] == ';')
        {
            semicolon_count++;
            dot_was = 0;
            last_was_semicolon = 1;
        }
    }
    if(semicolon_count != 2)
    {
        printf("Wrong input. Please try again\n");
        return 0;
    }
    return 1;
}

void Input(char number[])
{
    printf("Program to find middle number in an input\n");
    printf("Insert the string. Separate numbers with semicolons\n");
    int number_of_fails = -1;
    do
    {
        number_of_fails++;
        if(number_of_fails >= FAIL_LIMIT)
        {
            printf("Maximum fail number exceeded\n");
            exit(0);
        }
        scanf("%s", number);
    }
    while(!IsInputValid(number));
    printf("Value taken\n\n");
}

FILE* File_Name_Input()
{
    FILE* f;
    int number_of_fails = -1;
    LOOP_START:
    do
    {
        number_of_fails++;
        if(number_of_fails >= FAIL_LIMIT)
        {
            printf("Maximum fail number exceeded\n");
            exit(0);
        }
        char file_name[300];
        printf("Insert a name of an output file. Must end with .txt\n");
        scanf("%s", &file_name);
        int i = 0;
        while(file_name[i] != '\0')
            i++;
        if(file_name[i - 4] != '.' ||
           file_name[i - 3] != 't' ||
           file_name[i - 2] != 'x' ||
           file_name[i - 1] != 't')
        {
            printf("Filename must end with \".txt\". Please insert new file name\n");
            goto LOOP_START;
        }
        f = fopen(file_name, "w");
    } while(!f && (printf("File not found\n"), 1));
    return f;
}

void FindMiddleNumber(char number[], char answer[])
{
    int i = 0;
    while(number[i] != ';')
        i++;
    i++;
    int answer_letter_nr = 0;
    while(number[i] != ';')
    {
        answer[answer_letter_nr] = number[i];
        answer_letter_nr++;
        i++;
    }
    answer[answer_letter_nr] = '\0';
}

void Output(FILE* f, char answer[])
{
    fprintf(f, "%s", answer);
    fclose(f);
}

