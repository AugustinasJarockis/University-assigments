#include <stdio.h>

int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg);

int main()
{
    char *menuOptions[] = {"Vistiena", "Kiauliena", "Jautiena", "Aviena"};
    printf("%d", showMenu("Maistas", menuOptions, 4, "Kurio patiekalo noretumete"));
    return 0;
}

int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg)
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

    return user_choice;
}
