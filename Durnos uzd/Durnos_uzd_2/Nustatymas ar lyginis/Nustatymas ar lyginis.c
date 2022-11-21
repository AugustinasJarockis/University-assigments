#include <stdio.h>

int main()
{
    int skaicius;
    printf("Iveskite skaiciu");
    skaicius = 15;//scanf("%d", &skaicius);
    printf("%s", skaicius % 2 == 0 ? "Skaicius lyginis" : "Skaicius nelyginis");
    return 0;
}
