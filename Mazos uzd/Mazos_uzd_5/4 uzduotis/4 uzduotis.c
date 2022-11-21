#include <stdio.h>

#define CAPACITY 1000

int IsPrime(int number);

int main()
{
    printf("Program to find all primes in a set\n");
    printf("Insert positive integers. First negative integer will mark the end of the set\n");

    int set[CAPACITY];
    int set_size = 0;
    int found_primes[CAPACITY];

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
    printf("Printing all primes in the set:\n");
    int prime_count = 1;
    for(int i = 0; i < set_size; i++)
    {
        if(IsPrime(set[i]))
        {
            int has_been = 0;
            for(int i2 = 0; i2 < prime_count - 1 && has_been == 0; i2++)
            {
                if(set[i] == found_primes[i2])
                {
                    has_been = 1;
                }
            }
            if(has_been == 0)
            {
                printf("%d. %d\n", prime_count, set[i]);
                found_primes[prime_count - 1] = set[i];
                prime_count++;
            }
        }
    }
    if(prime_count == 1)
        printf("There are no primes\n");
    else
        printf("All primes have been printed\n");

    return 0;
}

int IsPrime(int number)
{
    if(number % 3 == 0 || number % 2 == 0 || number == 1)
        return 0;
    else if(number == 2 || number == 3)
        return 1;
    for(int currentCheck = 6; currentCheck <= sqrt(number); currentCheck += 6)
    {
        if(number % (currentCheck - 1) == 0 || number % (currentCheck + 1) == 0)
        {
            return 0;
        }
    }
    return 1;
}
