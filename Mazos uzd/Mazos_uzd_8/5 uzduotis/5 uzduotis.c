#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char*** createStringTable(int n, int m);
int assignString(char ***table, int i, int j, char* str);
char* getString(char ***table, int i, int j);
void freeTableData(char ***table, int n, int m);

int main()
{
    char ***array = createStringTable(10, 15);
    assignString(array, 2, 14, "Kapitonas pitonas");
    printf("%s\n", getString(array, 2, 14));
    freeTableData(array, 10, 15);
    return 0;
}

char*** createStringTable(int n, int m)
{
    char ***table = malloc(n * sizeof(char**));
    if(table == NULL)
        return NULL;
    for(int i = 0; i < n; i++)
    {
        table[i] = malloc(m * sizeof(char*));
        if(table[i] == NULL)
            return NULL;
        for(int i2 = 0; i2 < m; i2++)
        {
            table[i][i2] = NULL;
        }
    }
    return table;
}

int assignString(char ***table, int i, int j, char* str)
{
    table[i][j] = malloc(sizeof(char) * (strlen(str) + 1));
    if(table[i][j] == 0)
        return -1;
    strcpy(table[i][j], str);
    return 0;
}

char* getString(char ***table, int i, int j)
{
    return table[i][j];
}

void freeTableData(char ***table, int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int i2 = 0; i2 < m; i2++)
        {
            free(table[i][i2]);
        }
        free(table[i]);
    }
    free(table);
}
