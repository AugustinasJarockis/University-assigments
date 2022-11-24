#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void *my_memset(void *str, unsigned char c, size_t n);

int main()
{
    char *str = malloc(10);
    char *result = "bbbbbbbbbb";
    my_memset(str, 'b', 10);
    assert(!strcmp(str, result));

    char *result1 = "aaaabbbbbb";
    my_memset(str, 'a', 4);
    assert(!strcmp(str, result1));

    assert(!my_memset(NULL, 'b', 10));
    return 0;
}

void *my_memset(void *str, unsigned char c, size_t n)
{
    if(str == NULL)
    {
        return NULL;
    }
    for(int i = 0; i < n; i++)
    {
        ((char*) str)[i] = c;
    }
    return str;
}
