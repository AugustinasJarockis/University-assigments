#include <stdio.h>

#define CAPACITY 1000

int main()
{
    printf("Program to find if a number is a sum of set's members\n");

    int set[CAPACITY];
    int active_set_members[CAPACITY] = { 0 };
    int set_size = 0;
    long long x;

    printf("Insert an integer. It will be the number that will be checked if it has sum: ");
    scanf("%d", &x);
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
    int posssible = 0;
    int not_all_tested = 1;
    while(not_all_tested)
    {
        for(int i = 0; i < set_size; i++)
        {
            if(active_set_members[i] == 1)
            {
                active_set_members[i] = 0;
            }
            else
            {
                active_set_members[i] = 1;
                break;
            }

            if(i == set_size - 1)
            {
                not_all_tested = 0;
                break;
            }
        }
        int sum = 0;
        for(int i = 0; i < set_size; i++)
        {
            sum += set[i] * active_set_members[i];
        }
        if(x == sum)
        {
            posssible = 1;
            break;
        }
    }
    if(posssible == 1)
    {
        printf("%d is the sum of\n", x);
        int i = 0;
        for(; i < set_size; i++)
        {
            if(active_set_members[i] == 1)
            {
                printf("%d ", set[i]);
                break;
            }
        }
        for(i++; i < set_size; i++)
        {
            if(active_set_members[i] == 1)
            {
                printf("+ %d ", set[i]);
            }
        }
    }
    else
        printf("%d is impossible to express as a sum of the set's members\n", x);

    return 0;
}
