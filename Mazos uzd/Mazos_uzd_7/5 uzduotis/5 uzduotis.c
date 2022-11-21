#include <stdio.h>

long getFileSize(char *fileName);

int main()
{
    printf("%d", getFileSize("65 uzduotis.exe"));
    return 0;
}

long getFileSize(char *fileName)
{
    FILE *f = fopen(fileName, "rb");

    if(f == NULL)
        return -1;

    fseek(f, 0, SEEK_END);
    int file_size = ftell(f);
    fclose(f);
    return file_size;
}
