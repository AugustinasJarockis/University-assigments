#include <stdio.h>
#include <time.h>

int getPositiveNumber(char *msg);

int main()
{
    getPositiveNumber("Print please\n");
    return 0;
}

int getPositiveNumber(char *msg)
{
    int input;
    do
    {
        printf("%s", msg);
        fflush(stdin);
    }while(!scanf("%d", &input));

    return input;
}
