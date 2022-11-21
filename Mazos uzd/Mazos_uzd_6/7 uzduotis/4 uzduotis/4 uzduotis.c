#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define FAIL_LIMIT 5
#define CAPACITY 255

int isInputValid(char format_str[], char input[]);
void AcquireUI(char text[][CAPACITY]);
void AcquireInput(char text[][CAPACITY], double* year, double* month, double* day);
int WhichDayOfTheWeek(double year, double month, double day);
void Output(char text[][CAPACITY], int weekday);

int main()
{
    char text[12][CAPACITY];
    double year, month, day;
    AcquireUI(text);
    AcquireInput(text, &year, &month, &day);
    Output(text, WhichDayOfTheWeek(year, month, day));
    return 0;
}

void AcquireUI(char text[][CAPACITY])
{
    FILE* f = fopen("week.txt", "r");
    for(int i = 0; i < 12; i++)
    {
        fgets(text[i], CAPACITY, f);
    }
    fclose(f);
}

void AcquireInput(char text[][CAPACITY], double* year, double* month, double* day)
{
    printf("%s", text[8]);
    printf("%s", text[9]);

    char input[50];
    int number_of_fails = -1;
    do
    {
        number_of_fails++;
        if(number_of_fails >= FAIL_LIMIT)
        {
            printf("Maximum fail number exceeded\n");
            exit(0);
        }
        scanf("%s", input);
    } while(!isInputValid("%@>1;i-%@[1;12]>2;#2;i-%@[1;31]>2;#2;i", input) && (printf("%s", text[11]), 1));

    printf("%s", text[10]);

    char year_str[50] = {0};
    int char_c = 0;
    while(input[char_c] != '-')
    {
        year_str[char_c] = input[char_c];
        char_c++;
    }
    int input_el = char_c + 1;
    char_c = 0;
    *year = atoi(year_str);

    char month_str[50] = {0};
    while(input[input_el] != '-')
    {
        month_str[char_c] = input[input_el];
        char_c++;
        input_el++;
    }
    input_el++;
    char_c = 0;
    *month = atoi(month_str);

    char day_str[50] = {0};
    while(input[input_el] != '\0')
    {
        day_str[char_c] = input[input_el];
        char_c++;
        input_el++;
    }
    input_el++;
    char_c = 0;
    *day = atoi(day_str);
}

int WhichDayOfTheWeek(double year, double month, double day)
{
    double cent = year / 100;
    year = (int)year % 100;
    if(month == 1 || month == 2)
        year += 12;
    month -= 2;
    return (int)(day + floor(2.6 * month - 0.2) - 2 * cent + year + floor(year / 4) + floor(cent / 4)) % 7 + 1;
}

void Output(char text[][CAPACITY], int weekday)
{
    printf("%s %s", text[0], text[weekday]);
}

int isInputValid(char format_str[], char input[])
{
    int min, max;
    int min_def = 0, max_def = 0;
    int upper_strict = 0, lower_strict = 0;
    char to_exclude[100][100];
    char to_include[100][100];
    int exc_c = 0, inc_c = 0;
    int minim_s_c;
    int minim_s_c_def = 0;
    int d_c_bef, d_c_aft;
    int d_c_bef_def = 0, d_c_aft_def = 0;
    char cant_be[100][100];
    char has_to_be[100][100];
    int cant_be_c = 0, has_to_be_c = 0;
    char stop_value[100][100];
    int stop_value_c = 0;

    int in_place = 0;
    for(int i = 0; format_str[i] != '\0'; in_place++, i++)
    {
        if(format_str[i] == '%' && format_str[i + 1] == '@')
        {
            i += 2;
            if(format_str[i] == '[' || format_str[i] == '(')
            {
                if(format_str[i] == '(')
                    lower_strict = 1;
                else
                    lower_strict = 0;

                i++;
                if(format_str[i] != '?')
                {
                    char min_limit_str[100] = {0};
                    min_def = 1;
                    for(int i2 = 0; format_str[i] != ';'; i2++, i++)
                    {
                        min_limit_str[i2] = format_str[i];
                    }
                    min = atoi(min_limit_str);
                }
                else
                    i++;
                i++;
                if(format_str[i] != '?')
                {
                    char max_limit_str[100] = {0};
                    max_def = 1;
                    for(int i2 = 0; format_str[i] != ']' && format_str[i] != ')'; i2++, i++)
                    {
                        max_limit_str[i2] = format_str[i];
                    }
                    max = atoi(max_limit_str);
                }
                else
                    i++;

                if(format_str[i] == ')')
                    upper_strict = 1;
                else
                    upper_strict = 0;

                i++;
            }

            if(format_str[i] == '!')
            {
                i--;
                do
                {
                    i += 2;
                    int symbol_nr = 0;
                    while(!((format_str[i] == '%' && format_str[i + 1] == '!') || (format_str[i] == '%' && format_str[i + 1] == '$')))
                    {
                        to_exclude[exc_c][symbol_nr] = format_str[i];
                        symbol_nr++;
                        i++;
                    }
                    exc_c++;
                }
                while(format_str[i] == '%' && format_str[i + 1] == '!');
                i += 2;
            }

            if(format_str[i] == '^')
            {
                i--;
                do
                {
                    i += 2;
                    int symbol_nr = 0;
                    while(!((format_str[i] == '%' && format_str[i + 1] == '^') || (format_str[i] == '%' && format_str[i + 1] == '$')))
                    {
                        to_include[inc_c][symbol_nr] = format_str[i];
                        symbol_nr++;
                        i++;
                    }
                    inc_c++;
                }
                while(format_str[i] == '%' && format_str[i + 1] == '^');
                i += 2;
            }

            if(format_str[i] == '>')
            {
                i++;
                char digit_count_str[100] = {0};
                minim_s_c_def = 1;
                for(int i2 = 0; format_str[i] != ';'; i2++, i++)
                {
                    digit_count_str[i2] = format_str[i];
                }
                minim_s_c = atoi(digit_count_str);
                i++;
            }

            if(format_str[i] == '#')
            {
                i++;
                char digit_count_str[100] = {0};
                d_c_bef_def = 1;
                for(int i2 = 0; format_str[i] != ';'; i2++, i++)
                {
                    digit_count_str[i2] = format_str[i];
                }
                d_c_bef = atoi(digit_count_str);
                i++;
            }

            if(format_str[i] == '.')
            {
                i++;
                char digit_count_str[100] = {0};
                d_c_aft_def = 1;
                for(int i2 = 0; format_str[i] != ';'; i2++, i++)
                {
                    digit_count_str[i2] = format_str[i];
                }
                d_c_aft = atoi(digit_count_str);
                i++;
            }

            if(format_str[i] == '/')
            {
                i--;
                do
                {
                    i += 2;
                    int symbol_nr = 0;
                    while(!((format_str[i] == '%' && format_str[i + 1] == '/') || (format_str[i] == '%' && format_str[i + 1] == '$')))
                    {
                        cant_be[cant_be_c][symbol_nr] = format_str[i];
                        symbol_nr++;
                        i++;
                    }
                    cant_be_c++;
                }
                while(format_str[i] == '%' && format_str[i + 1] == '/');
                i += 2;
            }

            if(format_str[i] == '+')
            {
                i--;
                do
                {
                    i += 2;
                    int symbol_nr = 0;
                    while(!((format_str[i] == '%' && format_str[i + 1] == '+') || (format_str[i] == '%' && format_str[i + 1] == '$')))
                    {
                        has_to_be[has_to_be_c][symbol_nr] = format_str[i];
                        symbol_nr++;
                        i++;
                    }
                    has_to_be_c++;
                }
                while(format_str[i] == '%' && format_str[i + 1] == '+');
                i += 2;
            }

            if(format_str[i] == '|')
            {
                i--;
                do
                {
                    i += 2;
                    int symbol_nr = 0;
                    while(!((format_str[i] == '%' && format_str[i + 1] == '|') || (format_str[i] == '%' && format_str[i + 1] == '$')))
                    {
                        stop_value[stop_value_c][symbol_nr] = format_str[i];
                        symbol_nr++;
                        i++;
                    }
                    stop_value_c++;
                }
                while(format_str[i] == '%' && format_str[i + 1] == '|');
                i += 2;
            }
            //double ===========================================================================================================================
            if(format_str[i] == 'd')
            {
                char number_str[100];
                int digit_c = 0;
                if(input[in_place] == '-')
                {
                    number_str[digit_c] = input[in_place];
                    digit_c++;
                    in_place++;
                }
                while(input[in_place] != '\0' && isdigit(input[in_place]))
                {
                    number_str[digit_c] = input[in_place];
                    digit_c++;
                    in_place++;
                }
                if(input[in_place] == '.' || input[in_place] == ',')
                {
                    in_place++;
                    number_str[digit_c] = '.';
                    digit_c++;
                    while(input[i] != '\0' && isdigit(input[in_place]))
                    {
                        number_str[digit_c] = input[in_place];
                        digit_c++;
                        in_place++;
                    }
                }
                number_str[digit_c] = '\0';
                in_place--;

                if(has_to_be_c > 0)
                {
                    int match_found = 0;
                    for(int i2 = 0; i2 < has_to_be_c; i2++)
                    {
                        if(!strcmp(number_str, has_to_be[i2]))
                        {
                            match_found = 1;
                            break;
                        }
                    }
                    if(match_found == 0)
                    {
                        printf("Input doesn't match any possible value\n");
                        return 0;
                    }
                    has_to_be_c = 0;
                }

                for(int i2 = 0; i2 < cant_be_c; i2++)
                {
                    if(!strcmp(number_str, cant_be[i2]))
                    {
                        printf("Input can't contain %s\n", cant_be[i2]);
                        return 0;
                    }
                }
                cant_be_c = 0;

                if(minim_s_c_def)
                {
                    int i2 = 0;
                    while(number_str[i2] != '\0')
                    {
                        i2++;
                    }
                    if(i2 < minim_s_c)
                    {
                        printf("Number must contain at least %d symbols\n", minim_s_c);
                        return 0;
                    }
                    minim_s_c = 0;
                }

                if(d_c_bef_def)
                {
                    for(int i2 = 0; number_str[i2] != '\0' && number_str[i2] != '.'; i2++)
                    {
                        if(i2 >= d_c_bef)
                        {
                            printf("Number can't have more than %d digits in the whole part\n", d_c_bef);
                            return 0;
                        }
                    }
                    d_c_bef_def = 0;
                }

                if(d_c_aft_def)
                {
                    int before_dot = 0;
                    int dot_was = 0;
                    for(int i2 = 0; number_str[i2] != '\0'; i2++)
                    {
                        if(!dot_was)
                        {
                            before_dot++;
                        }
                        if(number_str[i2] == '.')
                        {
                            dot_was = 1;
                        }
                        if(i2 - before_dot >= d_c_aft)
                        {
                            printf("Number can't have more than %d digits in the fraction part\n", d_c_aft);
                            return 0;
                        }
                    }
                    d_c_aft_def = 0;
                }

                int number_value = atoi(number_str);

                if(min_def)
                {
                    if((lower_strict == 1 && number_value <= min_def) || (lower_strict == 0 && number_value < min_def))
                    {
                        if(max_def)
                        {
                            if(lower_strict == 1)
                            {
                                if(upper_strict == 1)
                                {
                                    printf("Value has to fall in range (%d; %d)\n", min, max);
                                }
                                else
                                {
                                    printf("Value has to fall in range (%d; %d]\n", min, max);
                                }
                            }
                            else
                            {
                                if(upper_strict == 1)
                                {
                                    printf("Value has to fall in range [%d; %d)\n", min, max);
                                }
                                else
                                {
                                    printf("Value has to fall in range [%d; %d]\n", min, max);
                                }
                            }
                        }
                        else
                        {
                            if(lower_strict == 1)
                            {
                                printf("Value has to be larger than %d\n", min);
                            }
                            else
                            {
                                printf("Value has to be larger than or equal to %d\n", min);
                            }
                        }
                        return 0;
                    }
                }

                if(max_def)
                {
                    if((upper_strict == 1 && number_value >= max) || (upper_strict == 0 && number_value > max))
                    {
                        if(min_def)
                        {
                            if(upper_strict == 1)
                            {
                                if(lower_strict == 1)
                                {
                                    printf("Value has to fall in range (%d; %d)\n", min, max);
                                }
                                else
                                {
                                    printf("Value has to fall in range (%d; %d]\n", min, max);
                                }
                            }
                            else
                            {
                                if(upper_strict == 1)
                                {
                                    printf("Value has to fall in range [%d; %d)\n", min, max);
                                }
                                else
                                {
                                    printf("Value has to fall in range [%d; %d]\n", min, max);
                                }
                            }
                        }
                        else
                        {
                            if(upper_strict == 1)
                            {
                                printf("Value has to be smaller than %d\n", max);
                            }
                            else
                            {
                                printf("Value has to be smaller than or equal to %d\n", max);
                            }
                        }
                        return 0;
                    }
                    max_def = 0;
                }
                min_def = 0;

                for(int i2 = 0; i2 < exc_c; i2++)
                {
                    for(int i3 = 0; number_str[i3] != '\0'; i3++)
                    {
                        if(number_str[i3] == to_exclude[i2][0])
                        {
                            int check_start = i3;
                            int exc_ind = 0;
                            while(number_str[i3] == to_exclude[i2][exc_ind] && to_exclude[i2][exc_ind] != '\0')
                            {
                                i3++;
                                exc_ind++;
                            }
                            if(to_exclude[i2][exc_ind] == '\0')
                            {
                                printf("Input can not contain %s\n", to_exclude[i2]);
                                return 0;
                            }
                            else
                                i3 = check_start;
                        }
                    }
                }
                exc_c = 0;

                for(int i2 = 0; i2 < inc_c; i2++)
                {
                    int contains_string = 0;
                    for(int i3 = 0; number_str[i3] != '\0'; i3++)
                    {
                        if(number_str[i3] == to_include[i2][0])
                        {
                            int check_start = i3;
                            int inc_ind = 0;
                            while(number_str[i3] == to_include[i2][inc_ind] && to_include[i2][inc_ind] != '\0')
                            {
                                i3++;
                                inc_ind++;
                            }
                            if(to_include[i2][inc_ind] == '\0')
                            {
                                contains_string = 1;
                                break;
                            }
                            else
                                i3 = check_start;
                        }
                    }
                    if(contains_string == 0)
                    {
                        printf("Input must contain %s\n", to_include[i2]);
                        return 0;
                    }
                }
                inc_c = 0;

            }
            //int ============================================================================================================
            else if(format_str[i] == 'i')
            {
                char number_str[100];
                int digit_c = 0;
                if(input[in_place] == '-')
                {
                    number_str[digit_c] = input[in_place];
                    digit_c++;
                    in_place++;
                }
                while(input[in_place] != '\0' && isdigit(input[in_place]))
                {
                    number_str[digit_c] = input[in_place];
                    digit_c++;
                    in_place++;
                }
                number_str[digit_c] = '\0';
                in_place--;

                if(has_to_be_c > 0)
                {
                    int match_found = 0;
                    for(int i2 = 0; i2 < has_to_be_c; i2++)
                    {
                        if(!strcmp(number_str, has_to_be[i2]))
                        {
                            match_found = 1;
                            break;
                        }
                    }
                    if(match_found == 0)
                    {
                        printf("Input doesn't match any possible value\n");
                        return 0;
                    }
                    has_to_be_c = 0;
                }

                for(int i2 = 0; i2 < cant_be_c; i2++)
                {
                    if(!strcmp(number_str, cant_be[i2]))
                    {
                        printf("Input can't contain %s\n", cant_be[i2]);
                        return 0;
                    }
                }
                cant_be_c = 0;

                if(minim_s_c_def)
                {
                    int i2 = 0;
                    while(number_str[i2] != '\0')
                    {
                        i2++;
                    }
                    if(i2 < minim_s_c)
                    {
                        printf("Number must contain at least %d symbols\n", minim_s_c);
                        return 0;
                    }
                    minim_s_c = 0;
                }

                if(d_c_bef_def)
                {
                    for(int i2 = 0; number_str[i2] != '\0'; i2++)
                    {
                        if(i2 >= d_c_bef)
                        {
                            printf("Number can't have more than %d digits in the whole part\n", d_c_bef);
                            return 0;
                        }
                    }
                    d_c_bef_def = 0;
                }

                d_c_aft_def = 0;

                int number_value = atoi(number_str);

                if(min_def)
                {
                    if((lower_strict == 1 && number_value <= min) || (lower_strict == 0 && number_value < min))
                    {
                        if(max_def)
                        {
                            if(lower_strict == 1)
                            {
                                if(upper_strict == 1)
                                {
                                    printf("Value has to fall in range (%d; %d)\n", min, max);
                                }
                                else
                                {
                                    printf("Value has to fall in range (%d; %d]\n", min, max);
                                }
                            }
                            else
                            {
                                if(upper_strict == 1)
                                {
                                    printf("Value has to fall in range [%d; %d)\n", min, max);
                                }
                                else
                                {
                                    printf("Value has to fall in range [%d; %d]\n", min, max);
                                }
                            }
                        }
                        else
                        {
                            if(lower_strict == 1)
                            {
                                printf("Value has to be larger than %d\n", min);
                            }
                            else
                            {
                                printf("Value has to be larger than or equal to %d\n", min);
                            }
                        }
                        return 0;
                    }
                }

                if(max_def)
                {
                    if((upper_strict == 1 && number_value >= max) || (upper_strict == 0 && number_value > max))
                    {
                        if(min_def)
                        {
                            if(upper_strict == 1)
                            {
                                if(lower_strict == 1)
                                {
                                    printf("Value has to fall in range (%d; %d)\n", min, max);
                                }
                                else
                                {
                                    printf("Value has to fall in range (%d; %d]\n", min, max);
                                }
                            }
                            else
                            {
                                if(upper_strict == 1)
                                {
                                    printf("Value has to fall in range [%d; %d)\n", min, max);
                                }
                                else
                                {
                                    printf("Value has to fall in range [%d; %d]\n", min, max);
                                }
                            }
                        }
                        else
                        {
                            if(upper_strict == 1)
                            {
                                printf("Value has to be smaller than %d\n", max);
                            }
                            else
                            {
                                printf("Value has to be smaller than or equal to %d\n", max);
                            }
                        }
                        return 0;
                    }
                    max_def = 0;
                }
                min_def = 0;

                for(int i2 = 0; i2 < exc_c; i2++)
                {
                    for(int i3 = 0; number_str[i3] != '\0'; i3++)
                    {
                        if(number_str[i3] == to_exclude[i2][0])
                        {
                            int check_start = i3;
                            int exc_ind = 0;
                            while(number_str[i3] == to_exclude[i2][exc_ind] && to_exclude[i2][exc_ind] != '\0')
                            {
                                i3++;
                                exc_ind++;
                            }
                            if(to_exclude[i2][exc_ind] == '\0')
                            {
                                printf("Input can not contain %s\n", to_exclude[i2]);
                                return 0;
                            }
                            else
                                i3 = check_start;
                        }
                    }
                }
                exc_c = 0;

                for(int i2 = 0; i2 < inc_c; i2++)
                {
                    int contains_string = 0;
                    for(int i3 = 0; number_str[i3] != '\0'; i3++)
                    {
                        if(number_str[i3] == to_include[i2][0])
                        {
                            int check_start = i3;
                            int inc_ind = 0;
                            while(number_str[i3] == to_include[i2][inc_ind] && to_include[i2][inc_ind] != '\0')
                            {
                                i3++;
                                inc_ind++;
                            }
                            if(to_include[i2][inc_ind] == '\0')
                            {
                                contains_string = 1;
                                break;
                            }
                            else
                                i3 = check_start;
                        }
                    }
                    if(contains_string == 0)
                    {
                        printf("Input must contain %s\n", to_include[i2]);
                        return 0;
                    }
                }
                inc_c = 0;

            }
            //String =======================================================================================================================================
            else if(format_str[i] == 's')
            {
                char number_str[100];
                int digit_c = 0;
                int stop_found = 0;
                while(input[in_place] != '\0' && !stop_found)
                {
                    for(int i2 = 0; i2 < stop_value_c; i2++)
                    {
                        int current_check = in_place;
                        int value_check = 0;
                        while(input[current_check] == stop_value[i2][value_check] && stop_value[i2][value_check] != '\0')
                        {
                            current_check++;
                            value_check++;
                        }
                        if(stop_value[i2][value_check] == '\0')
                        {
                            stop_found = 1;
                            break;
                        }
                    }
                    number_str[digit_c] = input[in_place];
                    digit_c++;
                    in_place++;
                }
                stop_value_c = 0;
                if(stop_found == 1)
                {
                    digit_c--;
                    in_place--;
                }
                number_str[digit_c] = '\0';
                in_place--;

                if(has_to_be_c > 0)
                {
                    int match_found = 0;
                    for(int i2 = 0; i2 < has_to_be_c; i2++)
                    {
                        if(!strcmp(number_str, has_to_be[i2]))
                        {
                            match_found = 1;
                            break;
                        }
                    }
                    if(match_found == 0)
                    {
                        printf("Input doesn't match any possible value\n");
                        return 0;
                    }
                    has_to_be_c = 0;
                }

                for(int i2 = 0; i2 < cant_be_c; i2++)
                {
                    if(!strcmp(number_str, cant_be[i2]))
                    {
                        printf("Input can't contain %s\n", cant_be[i2]);
                        return 0;
                    }
                }
                cant_be_c = 0;

                if(minim_s_c_def)
                {
                    int i2 = 0;
                    while(number_str[i2] != '\0')
                    {
                        i2++;
                    }
                    if(i2 < minim_s_c)
                    {
                        printf("Number must contain at least %d symbols\n", minim_s_c);
                        return 0;
                    }
                    minim_s_c = 0;
                }

                if(d_c_bef_def)
                {
                    for(int i2 = 0; number_str[i2] != '\0'; i2++)
                    {
                        if(i2 >= d_c_bef)
                        {
                            printf("Number can't have more than %d digits in the whole part\n", d_c_bef);
                            return 0;
                        }
                    }
                    d_c_bef_def = 0;
                }

                d_c_aft_def = 0;

                for(int i2 = 0; i2 < exc_c; i2++)
                {
                    for(int i3 = 0; number_str[i3] != '\0'; i3++)
                    {
                        if(number_str[i3] == to_exclude[i2][0])
                        {
                            int check_start = i3;
                            int exc_ind = 0;
                            while(number_str[i3] == to_exclude[i2][exc_ind] && to_exclude[i2][exc_ind] != '\0')
                            {
                                i3++;
                                exc_ind++;
                            }
                            if(to_exclude[i2][exc_ind] == '\0')
                            {
                                printf("Input can not contain %s\n", to_exclude[i2]);
                                return 0;
                            }
                            else
                                i3 = check_start;
                        }
                    }
                }
                exc_c = 0;

                for(int i2 = 0; i2 < inc_c; i2++)
                {
                    int contains_string = 0;
                    for(int i3 = 0; number_str[i3] != '\0'; i3++)
                    {
                        if(number_str[i3] == to_include[i2][0])
                        {
                            int check_start = i3;
                            int inc_ind = 0;
                            while(number_str[i3] == to_include[i2][inc_ind] && to_include[i2][inc_ind] != '\0')
                            {
                                i3++;
                                inc_ind++;
                            }
                            if(to_include[i2][inc_ind] == '\0')
                            {
                                contains_string = 1;
                                break;
                            }
                            else
                                i3 = check_start;
                        }
                    }
                    if(contains_string == 0)
                    {
                        printf("Input must contain %s\n", to_include[i2]);
                        return 0;
                    }
                }
                inc_c = 0;
            }
            //File ================================================================================================================================
            else if(format_str[i] == 'f')
            {
                char number_str[100];
                int digit_c = 0;
                int stop_found = 0;
                while(input[in_place] != '\0' && !stop_found)
                {
                    for(int i2 = 0; i2 < stop_value_c; i2++)
                    {
                        int current_check = in_place;
                        int value_check = 0;
                        while(input[current_check] == stop_value[i2][value_check] && stop_value[i2][value_check] != '\0')
                        {
                            current_check++;
                            value_check++;
                        }
                        if(stop_value[i2][value_check] == '\0')
                        {
                            stop_found = 1;
                            break;
                        }
                    }
                    number_str[digit_c] = input[in_place];
                    digit_c++;
                    in_place++;
                }
                stop_value_c = 0;
                if(stop_found == 1)
                {
                    digit_c--;
                    in_place--;
                }
                number_str[digit_c] = '\0';
                in_place--;

                if(has_to_be_c > 0)
                {
                    int match_found = 0;
                    for(int i2 = 0; i2 < has_to_be_c; i2++)
                    {
                        if(!strcmp(number_str, has_to_be[i2]))
                        {
                            match_found = 1;
                            break;
                        }
                    }
                    if(match_found == 0)
                    {
                        printf("Input doesn't match any possible value\n");
                        return 0;
                    }
                    has_to_be_c = 0;
                }

                for(int i2 = 0; i2 < cant_be_c; i2++)
                {
                    if(!strcmp(number_str, cant_be[i2]))
                    {
                        printf("Input can't contain %s\n", cant_be[i2]);
                        return 0;
                    }
                }
                cant_be_c = 0;

                if(minim_s_c_def)
                {
                    int i2 = 0;
                    while(number_str[i2] != '\0')
                    {
                        i2++;
                    }
                    if(i2 < minim_s_c)
                    {
                        printf("Number must contain at least %d symbols\n", minim_s_c);
                        return 0;
                    }
                    minim_s_c = 0;
                }

                if(d_c_bef_def)
                {
                    for(int i2 = 0; number_str[i2] != '\0'; i2++)
                    {
                        if(i2 >= d_c_bef)
                        {
                            printf("Number can't have more than %d digits in the whole part\n", d_c_bef);
                            return 0;
                        }
                    }
                    d_c_bef_def = 0;
                }

                d_c_aft_def = 0;

                for(int i2 = 0; i2 < exc_c; i2++)
                {
                    for(int i3 = 0; number_str[i3] != '\0'; i3++)
                    {
                        if(number_str[i3] == to_exclude[i2][0])
                        {
                            int check_start = i3;
                            int exc_ind = 0;
                            while(number_str[i3] == to_exclude[i2][exc_ind] && to_exclude[i2][exc_ind] != '\0')
                            {
                                i3++;
                                exc_ind++;
                            }
                            if(to_exclude[i2][exc_ind] == '\0')
                            {
                                printf("Input can not contain %s\n", to_exclude[i2]);
                                return 0;
                            }
                            else
                                i3 = check_start;
                        }
                    }
                }
                exc_c = 0;

                for(int i2 = 0; i2 < inc_c; i2++)
                {
                    int contains_string = 0;
                    for(int i3 = 0; number_str[i3] != '\0'; i3++)
                    {
                        if(number_str[i3] == to_include[i2][0])
                        {
                            int check_start = i3;
                            int inc_ind = 0;
                            while(number_str[i3] == to_include[i2][inc_ind] && to_include[i2][inc_ind] != '\0')
                            {
                                i3++;
                                inc_ind++;
                            }
                            if(to_include[i2][inc_ind] == '\0')
                            {
                                contains_string = 1;
                                break;
                            }
                            else
                                i3 = check_start;
                        }
                    }
                    if(contains_string == 0)
                    {
                        printf("Input must contain %s\n", to_include[i2]);
                        return 0;
                    }
                }
                inc_c = 0;

                FILE* temporary = fopen(number_str, "r");
                if(!temporary)
                {
                    printf("File %s could not be found\n", number_str);
                    return 0;
                }
                fclose(temporary);
            }
            else
            {
                printf("ERROR: variable type not sprecified\n");
            }
        }
        else if(input[in_place] != format_str[i])
        {
            printf("Input doesn't match format\n");
            return 0;
        }
    }

    if(input[in_place] != '\0')
    {
        printf("Input doesn't match format\n");
        return 0;
    }
    return 1;
}
