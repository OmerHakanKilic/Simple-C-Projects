#include <stdio.h>
#include <string.h>

void reverse_string(char *string)
{
    int size= strlen(string);
    char temp[size+1];
    strcpy(temp, string);

    for(int i=0;i<size; i++)
    {
        string[i] = temp[size-i-1];
    }
}

int main(void)
{
    int string_lenght=0;
    printf("Please enter the lenght of the string you want to reverse: \n");
    scanf("%d", &string_lenght);
    getchar();
    string_lenght++;
    char input[string_lenght];
    printf("Please enter a string: \n");
    fgets(input, string_lenght, stdin);

    reverse_string(input);

    printf("Reversed string: %s", input);
    return 0;
}
