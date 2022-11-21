#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 1000

int getValue(FILE **file, int index, int *value);
int setValue(FILE **file, int index, int value);
int addValue(FILE **file, int index, int value);
int remValue(FILE **file, int index, char *filename);

long getFileSize(FILE **file);

int main()
{
    int v1 = 49;
    int v2 = 48;
    FILE* f = fopen("t.txt", "r+b");
    /*setValue(&f, 0, 50);
    getValue(&f, 0, &v1);
    addValue(&f, 0, v1);
    addValue(&f, 0, v2);
    addValue(&f, 0, v1);
    addValue(&f, 0, v2);*/
    char filename[] = "t.txt";
    remValue(&f, 4 * sizeof(int), filename);
    fclose(f);
    return 0;
}

int getValue(FILE **file, int index, int *value)
{
    if(index > getFileSize(file))
        return -1;

    fseek(*file, index, SEEK_SET);
    fread(value, sizeof(int), 1, *file);

    return 0;
}

int setValue(FILE **file, int index, int value)
{
    if(index + sizeof(int) > getFileSize(file))
        return -1;

    fseek(*file, index, SEEK_SET);
    fwrite(&value, sizeof(int), 1, *file);

    return 0;
}

int addValue(FILE **file, int index, int value)
{
    int file_size = getFileSize(file);
    if(index > file_size)
        return -1;

    fseek(*file, index, SEEK_SET);
    void *buffer = malloc(file_size - index);
    fread(buffer, sizeof(char), file_size - index, *file);

    fseek(*file, 0, SEEK_SET);
    fwrite(&value, sizeof(int), 1, *file);
    fseek(*file, index + sizeof(int), SEEK_SET);
    fwrite(buffer, sizeof(char), file_size - index, *file);
    free(buffer);
    return 0;
}

int remValue(FILE **file, int index, char *filename)
{
    int file_size = getFileSize(file);
    if(index + sizeof(int) > file_size)
        return -1;

    char start_buffer[CAPACITY];
    fseek(*file, 0, SEEK_SET);
    fread(start_buffer, sizeof(char), index, *file);
    char end_buffer[CAPACITY];
    fseek(*file, index + sizeof(int), SEEK_SET);
    fread(end_buffer, sizeof(char), file_size - index - sizeof(int), *file);

    fclose(*file);
    *file = fopen("~temp.txt", "wb");
    fwrite(start_buffer, sizeof(char), index, *file);
    fwrite(end_buffer, sizeof(char), file_size - index - sizeof(int), *file);
    fclose(*file);

    remove(filename);
    rename("~temp.txt", filename);
    *file = fopen(filename, "r+b");
    return 0;
}

long getFileSize(FILE **file)
{
    fseek(*file, 0, SEEK_END);
    int file_size = ftell(*file);
    return file_size;
}
