#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DoublyLinkedList
{
    char** arr;
    int arr_size;
    struct DoublyLinkedList *previous;
    struct DoublyLinkedList *next;
} DoublyLinkedList;
DoublyLinkedList *createDoublyLinkedList();
//void printDoublyLinkedList(DoublyLinkedList *list);
int partitionList(DoublyLinkedList **list, int low, int high, int mode);
void quickSortString(DoublyLinkedList **list, int list_nr, int low, int high);
int partitionString(DoublyLinkedList *list, int list_nr, int low, int high);
void quickSortList(DoublyLinkedList **list, int low, int high, int mode);
int getDoublyLinkedListSize(DoublyLinkedList *list);
int getArraySize(DoublyLinkedList *list, int element);
DoublyLinkedList *getElement(DoublyLinkedList *list, int element);
void insertElement(DoublyLinkedList **list);
void insertString(DoublyLinkedList **list, int list_entry, char *str);
char **getArray(DoublyLinkedList *list, int index);
char *getStr(DoublyLinkedList *list, int arr_index, int str_index);
void deleteElement(DoublyLinkedList **list);
void destroyDoublyLinkedList(DoublyLinkedList **list);
void swapElements(DoublyLinkedList *a, DoublyLinkedList *b);

int main()
{
    DoublyLinkedList * list = createDoublyLinkedList();
    //printList(list);
    printf("%d\n", getDoublyLinkedListSize(list)/*, getElement(list)*/);
    insertElement(&list);
    insertElement(&list);
    insertElement(&list);
    insertElement(&list);
    insertElement(&list);
    //printList(list);
    char *str = "Amazing";
    insertString(&list, 3, str);
    printf("%d\n", getDoublyLinkedListSize(list));
    deleteElement(&list);
    deleteElement(&list);
    deleteElement(&list);
    //printList(list);
    printf("%d\n", getDoublyLinkedListSize(list));
    destroyDoublyLinkedList(&list);
    return 0;
}

DoublyLinkedList *createDoublyLinkedList()
{
    DoublyLinkedList *list = malloc(sizeof(DoublyLinkedList));
    (*list).arr = NULL;
    (*list).arr_size = 0;
    (*list).previous = NULL;
    (*list).next = NULL;
    return list;
}

/*void printList(DoublyLinkedList *list)
{
    printf("%d\n", (*list).value);
    if((*list).next != NULL)
        printList((*list).next);
}*/

int getDoublyLinkedListSize(DoublyLinkedList *list)
{
    if((*list).next == NULL)
        return 1;
    return getDoublyLinkedListSize((*list).next) + 1;
}

int getArraySize(DoublyLinkedList *list, int element)
{
    if(element == 0)
    {
        return (*list).arr_size;
    }
    return getArraySize((*list).next, element - 1);
}

void insertElement(DoublyLinkedList **list)
{
    DoublyLinkedList *new_list = createDoublyLinkedList();
    (*new_list).next = *list;
    (**list).previous = new_list;
    *list = new_list;
}

void insertString(DoublyLinkedList **list, int list_entry, char *str)
{
    if(list_entry == 0)
    {
        (**list).arr = realloc((**list).arr, ((**list).arr_size + 1) * sizeof(char));
        (**list).arr[(**list).arr_size] = str;
        (**list).arr_size++;
    }
    else
    {
        insertString(&((**list).next), list_entry - 1, str);
    }
}

char **getArray(DoublyLinkedList *list, int index)
{
    if(index > 0)
        return getArray((*list).next, index - 1);
    return (*list).arr;
}

char *getStr(DoublyLinkedList *list, int arr_index, int str_index)
{
    if(arr_index > 0)
        return getStr((*list).next, arr_index - 1, str_index);
    return (*list).arr[str_index];
}

DoublyLinkedList *getElement(DoublyLinkedList *list, int element)
{
    if(element == 0)
    {
        return list;
    }
    return getElement((*list).next, element - 1);
}

void deleteElement(DoublyLinkedList **list)
{
    free((**list).arr);
    void *temp_ptr = *list;
    if((**list).next != NULL)
    {
        *list = (**list).next;
        (**list).previous = NULL;
    }
    free(temp_ptr);
}

void destroyDoublyLinkedList(DoublyLinkedList **list)
{
    while((**list).next != NULL)
    {
        deleteElement(list);
    }
    deleteElement(list);
    (*list) = NULL;
}

void quickSortString(DoublyLinkedList **list, int list_nr, int low, int high)
{
    if(low < high)
    {
        int part = partitionList(*list, list_nr, low, high);

        quickSortList(list, list_nr, low, part - 1);
        quickSortList(list, list_nr, part + 1, high);
    }
}

int partitionString(DoublyLinkedList *list, int list_nr, int low, int high)
{
    while(list_nr != 0)
    {
        list = (*list).next;
        list_nr--;
    }
    int pivot = (*list).arr[high];
    int i = low - 1;
    for(int i2 = low; i2 < high; i2++)
    {
        if(strcmp((*list).arr[i2], (*list).arr[high]) <= 0)
        {
            i++;

            char *temp = (*list).arr[i2];
            (*list).arr[i2] = (*list).arr[i];
            (*list).arr[i] = temp;
        }
    }

    char *temp = (*list).arr[high];
    (*list).arr[high] = (*list).arr[i + 1];
    (*list).arr[i + 1] = temp;
    return i + 1;
}

void quickSortList(DoublyLinkedList **list, int low, int high, int mode)
{
    if(low < high)
    {
        int part = partitionList(list, low, high, mode);

        quickSortList(list, low, part - 1, mode);
        quickSortList(list, part + 1, high, mode);
    }
}

int partitionList(DoublyLinkedList **list, int low, int high, int mode)
{
    int pivot = getArraySize((*list), high);
    int i = low - 1;
    for(int i2 = low; i2 < high; i2++)
    {
        if(getArraySize((*list), i2) * mode <= pivot * mode)
        {
            i++;
            swapElements(getElement((*list), i), getElement((*list), i2));
        }
    }
    swapElements(getElement((*list), i + 1), getElement((*list), high));
    return i + 1;
}

void swapElements(DoublyLinkedList *a, DoublyLinkedList *b)
{
    void *ptr_prev = (*a).previous;
    void *ptr_next = (*a).next;
    (*a).previous = (*b).previous;
    (*a).next = (*b).next;
    (*b).previous = ptr_prev;
    (*b).next = ptr_next;
}
