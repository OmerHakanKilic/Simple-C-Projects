#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ListNode
{
        char* todo;
        struct ListNode* next;
};

typedef struct ListNode node;

node* create_node(char* data)
{
    node* result=malloc(sizeof(node));
    result->todo = data;
    result->next = NULL;
    return result;
}

void insert_to_do(node** head, char* data)
{
    node* new_head;
    new_head = create_node(data);
    new_head->next = *head;
    *head = new_head;
}

void add_to_do(node** head)
{
    node* new_head;
    char* input;
    size_t input_lenght = 0;
    printf("Please enter to-do: \n");
    getline(&input, &input_lenght, stdin);
    new_head = create_node(input);
    new_head->next = *head;
    *head = new_head;

}

void show_to_do(node* head)
{
    int i=0;
    node* temp = head;
    while(temp != NULL)
    {
        i++;
        printf("%d-%s \n", i, temp->todo);
        temp=temp->next;
    }
}


void delete_to_do(node** head)
{
    int input = 0;
    node* current = *head;
    node* previous=NULL;

    show_to_do(*head);
    printf("Please enter to-do number to delete: \n");

    scanf("%d", &input);
    while (getchar() != '\n');
    if (input <= 0)
    {
        printf("Invalid number. To-do numbers start from 1.\n");
        return;
    }
    for (int i = 1; i < input && current != NULL; i++)
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL)
    {
        printf("To-do item number %d does not exist.\n", input);
        return;
    }

    if (previous == NULL) {
        *head = current->next;
    } else {
        previous->next = current->next;
    }

    printf("Item with text %s is deleted.\n", current->todo);
    free(current->todo);
    free(current);
}

void load_from_file(node** head)
{
    FILE* file= fopen("savefile.txt", "r");
    char* file_input_line = NULL;
    size_t len = 0;
    char* temp;
    if (file == NULL)
    {
        return;
    }
    while((len = getline(&file_input_line, &len, file)) != -1)
    {
        temp = strdup(file_input_line);
        if (temp == NULL) {
            perror("Failed to duplicate string");
            free(file_input_line);
            fclose(file);
            return;
        }

        insert_to_do(head, temp);
    }

    free(file_input_line);
    fclose(file);
}

void save_to_file(node* head)
{
    FILE* file= fopen("savefile.txt", "w");

    node* temp = head;
    while(temp != NULL)
    {
        fprintf(file, "%s", temp->todo);
        temp=temp->next;
    }
    fclose(file);

}

void menu(void)
{
    node* head = NULL;
    load_from_file(&head);

    menu:
    printf("---------------------------------------\n");
    printf("1-Add To Do\n");
    printf("2-Delete To Do\n");
    printf("3-Show To Do\n");
    printf("4-Save\n");
    printf("5-Exit\n");
    printf("---------------------------------------\n");

    int choice=0;
    scanf("%d", &choice);

    while(getchar() != '\n');  //deal with leftovers

    switch(choice)
    {
        case 1:
            add_to_do(&head);
            goto menu;
            break;
        case 2:
            delete_to_do(&head);
            goto menu;
            break;
        case 3:
            show_to_do(head);
            goto menu;
            break;
        case 4:
            save_to_file(head);
            goto menu;
            break;
        case 5:
            return;
        default:
            printf("Please select an option between 1 and 4.\n");
            goto menu;
            break;
    }

}

int main(void)
{
    menu();
    return 0;
}
