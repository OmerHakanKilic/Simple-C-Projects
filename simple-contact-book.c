#include <stdio.h>
#include <string.h>

#define MAX_CONTACT_NUMBER 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 15

struct Contact
{
    char name[MAX_NAME_LENGTH];
    char number[MAX_PHONE_NUMBER_LENGTH];
};

void empty_array(struct Contact contact_book[MAX_CONTACT_NUMBER])
{
    for(int i=0; i < MAX_CONTACT_NUMBER; i++)
    {
        strcpy(contact_book[i].name, "");
        strcpy(contact_book[i].number, "");
    }
}

int find_empty_index(struct Contact contact_book[MAX_CONTACT_NUMBER])
{
    for(int i=0; i < MAX_CONTACT_NUMBER; i++)
    {
        if(strlen(contact_book[i].name) == 0)
        {
            return i;
        }
    }

    return -1;
}
void add(struct Contact contact_book[MAX_CONTACT_NUMBER])
{
    char new_name[MAX_NAME_LENGTH];
    char new_number[MAX_PHONE_NUMBER_LENGTH];
    int empty_index = find_empty_index(contact_book);

    printf("Please enter contact name: ");
    scanf("%s", new_name);
    printf("Please enter contact number: ");
    scanf("%s", new_number);

    struct Contact new_contact;
    strcpy(new_contact.name, new_name);
    strcpy(new_contact.number, new_number);
    contact_book[empty_index] = new_contact;
}
void show(struct Contact contact_book[MAX_CONTACT_NUMBER])
{
    for(int i=0; i < MAX_CONTACT_NUMBER; i++)
    {
        if(strlen(contact_book[i].name) != 0)
        {
            printf("%d- Name: %s\n", (i+1), contact_book[i].name);
            printf("   Number: %s\n", contact_book[i].number);
        }
    }
}
void delete(struct Contact contact_book[MAX_CONTACT_NUMBER])
{
    int contact_to_delete = 0;
    show(contact_book);
    printf("Please enter contact number to delete: \n");
    scanf("%d", &contact_to_delete);

    strcpy(contact_book[contact_to_delete-1].name, "");
    strcpy(contact_book[contact_to_delete-1].number, "");
}

void menu(void)
{
    struct Contact contact_book[MAX_CONTACT_NUMBER];
    empty_array(contact_book);
    menu:

    printf("1-Add phone number \n");
    printf("2-Delete phone number\n");
    printf("3-Show phone numbers\n");
    printf("4-Exit\n");

    int choice=0;
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            add(contact_book);
            goto menu;
            break;
        case 2:
            delete(contact_book);
            goto menu;
            break;
        case 3:
            show(contact_book);
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
