#include <stdio.h>
#include <math.h>

int main()
{
    int skaicius;
    printf("Iveskite viena sveika skaiciu: ");
    scanf("%d", &skaicius);
    //Skaiciaus skaitmenu kiekio nustatymas
    int count = 0;
    int temp = skaicius;
    while(temp != 0)
    {
        count++;
        temp /= 10;
    }
    //Skaiciaus skaitmenu rikiavimas
    for(int i = 0; i < count; i++)
    {
        for(int i2 = 0; i2 < count - 1; i2++)
        {
            int skaitmuo1 = (skaicius % (int)round(pow(10, i2 + 1))) / (int)round(pow(10, i2));
            int skaitmuo2 = (skaicius % (int)round(pow(10, i2 + 2))) / (int)round(pow(10, i2 + 1));
            if(((skaitmuo1 > skaitmuo2) && skaicius >= 0) || ((skaitmuo1 < skaitmuo2) && skaicius < 0))
            {
                skaicius += 9 * (skaitmuo1 - skaitmuo2) * (int)round(pow(10, i2));
            }
        }
    }
    //Isvestis
    printf("Isrikiuotas skaicius: %d", skaicius);
    return 0;
}
