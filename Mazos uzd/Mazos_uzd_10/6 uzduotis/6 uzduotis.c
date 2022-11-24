#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

size_t my_strcspn ( const char * str1, const char * str2 );

int main()
{
    {
        char *str1 = "Joris";
        char *str2 = "u";
        assert(my_strcspn ( str1, str2 ) == 5);
    }
    {
        char *str1 = "Traukinys";
        char *str2 = "Aseris";
        assert(my_strcspn ( str1, str2 ) == 1);
    }
    {
        char *str1 = "Zimbabve";
        char *str2 = "Kolukets";
        assert(my_strcspn ( str1, str2 ) == 7);
    }
    {
        char *str1 = NULL;
        char *str2 = "Kolukets";
        assert(my_strcspn ( str1, str2 ) == 0);
    }
    {
        char *str1 = "Zimbabve";
        char *str2 = NULL;
        assert(my_strcspn ( str1, str2 ) == 8);
    }
    return 0;
}

size_t my_strcspn ( const char * str1, const char * str2 )
{
    if(str1 == NULL)
    {
        return 0;
    }
    if(str2 == NULL)
    {
        return strlen(str1);
    }
    for(int i = 0; str1[i] != '\0'; i++)
    {
        for(int i2 = 0; str2[i2] != '\0'; i2++)
        {
            if(str1[i] == str2[i2])
            {
                return i;
            }
        }
    }
    return strlen(str1);
}
