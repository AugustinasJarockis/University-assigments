//a
#include <stdio.h>
#include <stdlib.h>

typedef struct List
{
    int value;
    struct List *next;
} List;
List *createList(int value);
void printList(List *list);
int getListSize(List *list);
void insertElement(List **list, int value);
int getElement(List *list);
int deleteElement(List **list);
void destroyList(List **list);

int main()
{
    List * list = createList(5);
    printList(list);
    printf("%d == %d\n", getListSize(list), getElement(list));
    insertElement(&list, 4);
    insertElement(&list, 3);
    insertElement(&list, 2);
    insertElement(&list, 1);
    insertElement(&list, 0);
    printList(list);
    printf("%d == %d\n", getListSize(list), getElement(list));
    deleteElement(&list);
    deleteElement(&list);
    deleteElement(&list);
    printList(list);
    printf("%d == %d\n", getListSize(list), getElement(list));
    destroyList(&list);
    return 0;
}

List *createList(int value)
{
    List *list = malloc(sizeof(List));
    (*list).value = value;
    (*list).next = NULL;
    return list;
}

void printList(List *list)
{
    printf("%d\n", (*list).value);
    if((*list).next != NULL)
        printList((*list).next);
}

int getListSize(List *list)
{
    if((*list).next == NULL)
        return 1;
    return getListSize((*list).next) + 1;
}

void insertElement(List **list, int value)
{
    List *new_list = createList(value);
    (*new_list).next = *list;
    *list = new_list;
}

int getElement(List *list)
{
    return (*list).value;
}

int deleteElement(List **list)
{
    int value = getElement(*list);
    void *temp_ptr = *list;
    *list = (**list).next;
    free(temp_ptr);
    return value;
}

void destroyList(List **list)
{
    while((**list).next != NULL)
    {
        deleteElement(list);
    }
    deleteElement(list);
}
//b
#include <stdio.h>
#include <stdlib.h>
//Point
typedef struct Point
{
    double x, y;
} Point;

void printPoint(Point p);
Point createPoint(double x, double y);
double getDistance(Point a, Point b);
//List
typedef struct List
{
    Point value;
    struct List *next;
} List;

List *createList(Point value);
void printList(List *list);
int getListSize(List *list);
void insertElement(List **list, Point value);
Point getElement(List *list);
Point deleteElement(List **list);
void destroyList(List **list);

int main()
{
    List * list = createList(5);
    printList(list);
    printf("%d == %d\n", getListSize(list), getElement(list));
    insertElement(&list, 4);
    insertElement(&list, 3);
    insertElement(&list, 2);
    insertElement(&list, 1);
    insertElement(&list, 0);
    printList(list);
    printf("%d == %d\n", getListSize(list), getElement(list));
    deleteElement(&list);
    deleteElement(&list);
    deleteElement(&list);
    printList(list);
    printf("%d == %d\n", getListSize(list), getElement(list));
    destroyList(&list);
    return 0;
}

List *createList(Point value)
{
    List *list = malloc(sizeof(List));
    (*list).value = value;
    (*list).next = NULL;
    return list;
}

void printList(List *list)
{
   printPoint((*list).value);
    if((*list).next != NULL)
        printList((*list).next);
}

int getListSize(List *list)
{
    if((*list).next == NULL)
        return 1;
    return getListSize((*list).next) + 1;
}

void insertElement(List **list, Point value)
{
    List *new_list = createList(value);
    (*new_list).next = *list;
    *list = new_list;
}

int getElement(List *list)
{
    return (*list).value;
}

int deleteElement(List **list)
{
    Point value = getElement(*list);
    void *temp_ptr = *list;
    *list = (**list).next;
    free(temp_ptr);
    return value;
}

void destroyList(List **list)
{
    while((**list).next != NULL)
    {
        deleteElement(list);
    }
    deleteElement(list);
}

//Point
void printPoint(Point p)
{
    printf("(%f, %f)\n", p.x, p.y);
}

Point createPoint(double x, double y)
{
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

double getDistance(Point a, Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
