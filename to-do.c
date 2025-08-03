#include <stdio.h>
#include <string.h>
#define MAX_ITEMS 10
#define MAX_LENGTH 50

void empty_array(char todos[MAX_ITEMS][MAX_LENGTH])
{
    for(int i=0; i < MAX_ITEMS; i++)
    {
        strcpy(todos[i], "");
    }
}

int find_empty_index(char todos[MAX_ITEMS][MAX_LENGTH])
{
    for(int i=0; i < MAX_ITEMS; i++)
    {
        if(strlen(todos[i]) == 0)
        {
            return i;
        }
    }

    return -1;
}

void add_to_do(char todos[MAX_ITEMS][MAX_LENGTH])
{
    char new_todo[MAX_LENGTH];
    int empty_index = find_empty_index(todos);
    printf("Please enter to-do: \n");
    scanf("%s", &new_todo);
    strcpy(todos[empty_index], new_todo);
}

void show_to_do(char todos[MAX_ITEMS][MAX_LENGTH])
{
    for(int i=0; i < MAX_ITEMS; i++)
    {
        printf("%d- %s\n", (i+1), todos[i]);
    }
}


void delete_to_do(char todos[MAX_ITEMS][MAX_LENGTH])
{
    int item_to_delete = 0;
    show_to_do(todos);
    printf("Please enter to-do number to delete: \n");
    scanf("%d", &item_to_delete);

    strcpy(todos[item_to_delete-1], "");
    printf("Item number %d is deleted.\n", &item_to_delete);


}


void menu(void)
{
    char todos[MAX_ITEMS][MAX_LENGTH];
    empty_array(todos);
    menu:

    printf("1-Add To Do\n");
    printf("2-Delete To Do\n");
    printf("3-Show To Do\n");
    printf("4-Exit\n");

    int choice=0;
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            add_to_do(todos);
            goto menu;
            break;
        case 2:
            delete_to_do(todos);
            goto menu;
            break;
        case 3:
            show_to_do(todos);
            goto menu;
            break;
        case 4:
            return;
    }

}

int main(void)
{
    menu();
    return 0;
}
