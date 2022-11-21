#include <stdio.h>
#include <stdlib.h>

struct Mem
{
    void* ptr;
    int size;
};
struct Mem myMemory[100000];

int myMalloc(int byte_c);
int myCalloc(int element_c, int element_size);
int myRealloc(int index, int byte_c);
void myFree(int index);
int getMallocSize(int index);
void freeAll();
void defragmentMemory();

int main()
{
    myMemory[0].size = 0;
    myMemory[0].ptr = NULL;
    return 0;
}

int myMalloc(int byte_c)
{
    myMemory[0].size++;
    myMemory[myMemory[0].size].ptr = malloc(byte_c);
    myMemory[myMemory[0].size].size = byte_c;
    if(myMemory[myMemory[0].size].ptr == NULL)
        return -1;
    return myMemory[0].size;
}

int myCalloc(int element_c, int element_size)
{
    myMemory[0].size++;
    myMemory[myMemory[0].size].ptr = calloc(element_c, element_size);
    myMemory[myMemory[0].size].size = element_c * element_size;
    if(myMemory[myMemory[0].size].ptr == NULL)
        return -1;
    return myMemory[0].size;
}

int myRealloc(int index, int byte_c)
{
    myMemory[index].ptr = realloc(myMemory[index].ptr, byte_c);
    myMemory[index].size = byte_c;
    if(myMemory[index].ptr == NULL)
        return -1;
    return index;
}

void myFree(int index)
{
    free(myMemory[index].ptr);
    for(int i = index; i <= myMemory[0].size; i++)
    {
        myMemory[i].ptr = myMemory[i + 1].ptr;
        myMemory[i].size = myMemory[i + 1].size;
    }
    myMemory[0].size--;
}

int getMallocSize(int index)
{
    if(index >= myMemory[0].size)
        return -1;
    return myMemory[index].size;
}

void freeAll()
{
    for(int i = 1; i <= myMemory[0].size; i++)
    {
        free(myMemory[i].ptr);
        myMemory[i].size = 0;
        myMemory[i].ptr = NULL;
    }
    myMemory[0].size = 0;
}

void defragmentMemory()
{
    for(int i = 1; i <= myMemory[0].size; i++)
    {
        free(myMemory[i].ptr);
    }
    int cumulative_size = 0;
    for(int i = 1; i <= myMemory[0].size; i++)
    {
        cumulative_size += myMemory[i].size;
    }
    void *all_mem_start = malloc(cumulative_size);
    void *current_mem_start = all_mem_start;
    for(int i = 1; i <= myMemory[0].size; i++)
    {
        myMemory[i].ptr = current_mem_start;
        current_mem_start += myMemory[i].size;
    }
}
