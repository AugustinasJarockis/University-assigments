#include <stdio.h>
#include <assert.h>

int my_strlen(char *str);

int main()
{
    char str[] = "Labas";
    assert(my_strlen(str) == 5);
    char str1[] = "Labas Labas";
    assert(my_strlen(str1) == 11);
    char *str2 = NULL;
    assert(my_strlen(str2) == -1);
    char *str3 = "";
    assert(my_strlen(str3) == 0);
    char *str4 = "Pateiktoms užduotims atlikti pasirinktinai įgyvendinkite pasirinktas funkcijas iš string.h, o vienetų testams vykdyti\
pasinaudokite assert.h. Šių užduočių kontekste funkcija main – ne daugiau nei vienetų testų vykdymo priemonė. Funkcijų\
viduje negali būti funkcionalumo, kuris netikrinamas main viduje esančiais testais.\
Kiekvieną užduotį rašykite atskirame kodo faile. Atliktas užduotis įkelkite į VU VMA, laikydamiesi pateiktų nurodymų";
    assert(my_strlen(str4) != 0);
    return 0;
}

int my_strlen(char *str)
{
    if(str == NULL)
    {
        return -1;
    }
    int len = 0;
    while(str[len] != '\0')
    {
        len++;
    }
    return len;
}
