#include <stdio.h>
#include <string.h>

struct book
{
    char author[50];
    char title[50];
};

void printOptions(void)
{
    printf("\n---------------------------------\n");
    printf("Please select an option: \n");
    printf("1. Add book information\n");
    printf("2. Display book information\n");
    printf("3. To list all books of a given author \n");
    printf("4. To list the count of books in the library\n");
    printf("\n---------------------------------\n");
}

void addBookInformation(struct book booklist[50])
{
    if(strlen(booklist[49].title) != 0)
    {
        printf("Reached maximum limit for adding books!");
        return;
    }

    struct book temp;
    printf("Please enter author: \n");
    scanf("%s", &temp.author);
    printf("Please enter title: \n");
    scanf("%s", &temp.title);

    for(int i=0; i<50;i++)
    {
        if(strlen(booklist[i].title) == 0)
        {
            booklist[i] = temp;
            printf("Temp added to %d", i);
            return;
        }
    }


}

void displayBookInformation(struct book booklist[50])
{
    for(int i=0; i<50;i++)
    {
        if(strlen(booklist[i].title)== 0)
        {
            break;
        }
        printf("Book author: %s\n", booklist[i].author);
        printf("Book title: %s\n", booklist[i].title);
    }
}

void listAuthorBooks(struct book booklist[50])
{
    char temp[50];
    printf("Enter the author to search: \n");
    scanf("%s", &temp);

    for(int i=0; i<50;i++)
    {
        if(strlen(booklist[i].title)== 0)
        {
            return;
        }
        if(strcmp(booklist[i].author,temp)==0)
        {
            printf("Book author: %s\n", booklist[i].author);
            printf("Book title: %s\n", booklist[i].title);
        }
    }
}

void countBooks(struct book booklist[50])
{
    for(int i=0; i<50;i++)
    {
        if(strlen(booklist[i].title) == 0)
        {
            printf("There are %d books in the library.", i);
            return;
        }
    }
}

int main(void)
{
    struct book booklist[50];

main_menu:
    int choice;
    printOptions();
    scanf("%d", &choice);


    switch(choice)
    {
        case 1:
            addBookInformation(booklist);
            goto main_menu;
        case 2:
            displayBookInformation(booklist);
            goto main_menu;
        case 3:
            listAuthorBooks(booklist);
            goto main_menu;
        case 4:
            countBooks(booklist);
            goto main_menu;
        default:
            break;
    }


    return 0;
}
