#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

char *___strtok_internal_value___;

char *my_strtok ( char * str, const char *delim );

int main()
{
    char *str = "Komjaunuolis - tyras komunistines ateities uztikrintojas - yra butinas darnios tarybines visuomenes garantavimui";
    assert(!strcmp(my_strtok ( str, "-" ), "Komjaunuolis "));
    assert(!strcmp(my_strtok ( NULL, "-" ), " tyras komunistines ateities uztikrintojas "));
    assert(!strcmp(my_strtok ( NULL, "-" ), " yra butinas darnios tarybines visuomenes garantavimui"));
    assert(!strcmp(my_strtok ( str, "-" ), "Komjaunuolis "));
    assert(!strcmp(my_strtok ( NULL, "-" ), " tyras komunistines ateities uztikrintojas "));

    assert(!strcmp(my_strtok ( str, " - " ), "Komjaunuolis"));
    assert(!strcmp(my_strtok ( NULL, " - " ), "tyras"));
    assert(!strcmp(my_strtok ( NULL, "- " ), "komunistines"));
    assert(!strcmp(my_strtok ( NULL, " -" ), "ateities"));
    assert(!strcmp(my_strtok ( NULL, " - " ), "uztikrintojas"));
    assert(!strcmp(my_strtok ( NULL, "-" ), " "));
    assert(!strcmp(my_strtok ( NULL, "-" ), " yra butinas darnios tarybines visuomenes garantavimui"));
    return 0;
}

char *my_strtok ( char * str, const char *delim )
{
    if(str == NULL)
    {
        free(str);
        str = ___strtok_internal_value___;
    }

    for(int i = 0; str[i] != '\0'; i++)
    {
        int buvo = 0;
        for(int i2 = 0; delim[i2] != '\0'; i2++)
        {
            if(str[i] == delim[i2])
            {
                buvo = 1;
            }
        }
        if(buvo == 0)
        {
            str += i;
            break;
        }
    }

    if(str[0] == '\0')
    {
        ___strtok_internal_value___ = NULL;
        free(str);
        str = NULL;
        return NULL;
    }

    for(int i = 0; str[i] != '\0'; i++)
    {
        for(int i2 = 0; delim[i2] != '\0'; i2++)
        {
            if(str[i] == delim[i2])
            {
                ___strtok_internal_value___ = str + i * sizeof(char);
                char *new_str = malloc((i + 1) * sizeof(char));
                strncpy(new_str, str, i);
                free(str);
                str = new_str;
                str[i] = '\0';
                goto OUTATHISLOOP;
            }
        }
    }
    OUTATHISLOOP:
    return str;
}
