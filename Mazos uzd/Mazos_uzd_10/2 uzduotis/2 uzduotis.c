#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int my_strlen(char *str);
char* my_strcpy(char* destination, const char* source);

int main()
{
    char *test0 = "Bananas";
    char *destination = malloc(100);
    assert(!strcmp(my_strcpy(destination, test0), "Bananas"));
    assert(!strcmp(destination, "Bananas"));

    char *test1 = "Granatas";
    assert(!strcmp(my_strcpy(destination, test1), "Granatas"));
    assert(!strcmp(destination, "Granatas"));

    char *test2 = NULL;
    assert(my_strcpy(destination, test2) == NULL);

    char *test3 = "Bananas";
    char *destination1 = NULL;
    assert(!strcmp(my_strcpy(destination1, test3), "Bananas"));

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

char* my_strcpy(char* destination, const char* source)
{
    if(source == NULL)
    {
        return NULL;
    }
    char *return_str = malloc(sizeof(char) * my_strlen(source));
    if(destination != NULL)
    {
        int i = -1;
        do
        {
            i++;
            destination[i] = source[i];
            return_str[i] = source[i];
        }
        while(source[i] != '\0');
    }
    else
    {
        int i = -1;
        do
        {
            i++;
            return_str[i] = source[i];
        }
        while(source[i] != '\0');
    }
    return return_str;
}
