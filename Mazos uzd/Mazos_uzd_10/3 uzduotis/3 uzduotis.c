#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

char* my_strncpy(char* destination, const char* source, size_t num);

int main()
{
    char *test0 = "Bananas";
    char *destination = malloc(100);
    assert(!strcmp(my_strncpy(destination, test0, 4), "Bana"));
    assert(!strcmp(destination, "Bana"));

    char *test1 = "Granatas";
    assert(!strcmp(my_strncpy(destination, test1, 20), "Granatas"));
    assert(!strcmp(destination, "Granatas"));
    assert(destination[19] == '\0');

    char *test2 = NULL;
    assert(my_strncpy(destination, test2, 15) == NULL);

    char *test3 = "Bananas";
    char *destination1 = NULL;
    assert(!strcmp(my_strncpy(destination1, test3, 0), ""));

    return 0;
}

char* my_strncpy(char* destination, const char* source, size_t num)
{
    if(source == NULL)
    {
        return NULL;
    }
    char *return_str = malloc(sizeof(char) * num);
    int i = -1;
    if(destination != NULL)
    {
        do
        {
            i++;
            destination[i] = source[i];
            return_str[i] = source[i];
        }
        while(source[i] != '\0' && i < num);
    }
    else
    {
        do
        {
            i++;
            return_str[i] = source[i];
        }
        while(source[i] != '\0' && i < num);
    }

    if(i < num)
    {
        for(int i2 = i; i2 < num; i2++)
        {
            return_str[i2] = '\0';
            if(destination != NULL)
            {
                destination[i2] = '\0';
            }
        }
    }
    return_str[num] = '\0';
    if(destination != NULL)
    {
        destination[num] = '\0';
    }
    return return_str;
}
