#include <stdio.h>

long getFileSize(char *fileName);
char* largestFile(int file_c, char** filenames);

int main(int argc, char** argv)
{
    if(argc == 1)
        printf("No filenames provided\n");
    else
        printf("This file has the largest size: %s\n", largestFile(argc, argv));
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

char* largestFile(int file_c, char** filenames)
{
    int largest_file_index = 0;
    int largest_file_size = getFileSize(filenames[0]);
    for(int i = 1; i < file_c - 1; i++)
    {
        int file_size = getFileSize(filenames[i]);
        if(file_size > largest_file_size)
        {
            largest_file_size = file_size;
            largest_file_index = i;
        }
    }
    return filenames[largest_file_index];
}
