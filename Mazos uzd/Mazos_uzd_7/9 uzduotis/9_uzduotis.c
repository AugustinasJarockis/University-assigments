#include <stdio.h>

int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg, void (*functions[])());
void printFunc();
int main()
{
    void (*functions[10])();
    functions[0] = printFunc;
    functions[1] = printFunc;
    functions[2] = printFunc;
    functions[3] = printFunc;
    functions[4] = printFunc;
    functions[5] = printFunc;
    char *menuOptions[] = {"Vistiena", "Kiauliena", "Jautiena", "Aviena"};
    printf("%d", showMenu("Maistas", menuOptions, 4, "Kurio patiekalo noretumete", functions));
    return 0;
}

int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg, void (*functions[])())
{
    int user_choice;
    do
    {
        printf("\n%s\n", menuTitle);
        for(int i = 0; i < menuSize; i++)
        {
            printf("%s\n", menuOptions[i]);
        }
        printf("%s\n", inputMsg);
        fflush(stdin);
    } while(!scanf("%d", &user_choice) || user_choice > menuSize || user_choice <= 0);

    (*functions[user_choice - 1])();
}

void printFunc()
{
    printf("Maisto gaminimas vyksta\n");
}
