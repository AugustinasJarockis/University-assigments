#include <stdio.h>

int main()
{
    const char zymejimu_eil[] =
    {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
        'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
        'u', 'v', 'w', 'x', 'y', 'z'
    };
    int prad_sys, gal_sys;
    char skaicius[1000], kon_skaicius[1000];
    START:
    printf("Is kelintaines sistemos versti: ");
    scanf("%d", &prad_sys);
    printf("I kelintaine sistema versti: ");
    scanf("%d", &gal_sys);
    printf("Iveskite sveika skaiciu pasirinktoje sistemoje: ");
    scanf("%s", &skaicius);
    int simbreiks[1000];
    int skaiciaus_ilgis = 0;
    while(skaicius[skaiciaus_ilgis] != '\0')
    {
        skaiciaus_ilgis++;
    }
    for(int i = 0; i < skaiciaus_ilgis; i++)
    {
        if(isdigit(skaicius[i]))
        {
            simbreiks[i] = skaicius[i] - 48;
        }
        else if(isalpha(skaicius[i]))
        {
            if(skaicius[i] >= 65 && skaicius[i] <= 90)
            {
                simbreiks[i] = skaicius[i] - 55;
            }
            else
            {
                simbreiks[i] = skaicius[i] - 87;
            }
        }
    }
    long long skaicius_desimtainiame = 0;
    for(int i = 0; i < skaiciaus_ilgis; i++)
    {
        skaicius_desimtainiame += simbreiks[i] * (int)round(pow(prad_sys, skaiciaus_ilgis - i - 1));
    }
    char rev_kon_skaicius[1000];
    int naujo_skaiciaus_ilgis = 0;
    for(int i = 0; skaicius_desimtainiame != 0; i++)
    {
        rev_kon_skaicius[i] = zymejimu_eil[skaicius_desimtainiame % gal_sys];
        naujo_skaiciaus_ilgis++;
        skaicius_desimtainiame /= gal_sys;
    }
    for(int i = 0; i < naujo_skaiciaus_ilgis; i++)
    {
        kon_skaicius[i] = rev_kon_skaicius[naujo_skaiciaus_ilgis - i - 1];
    }
    kon_skaicius[naujo_skaiciaus_ilgis] = '\0';
    printf("Jusu skaicius pasirinktoje sistemoje: %s\n", kon_skaicius);
    goto START;
    return 0;
}
