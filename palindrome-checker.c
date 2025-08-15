#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool check_palindrome(char* string)
{
    int size = strlen(string);

    for(int i=0; i<=size/2; i++)
    {
        if(string[i] != string[size-2-i])
        {
            return false;
        }

    }
    return true;
}

int main()
{
    size_t input_lenght=0;
    char* input;

    printf("Enter a word to check if it is a palindrome: \n");
    getline(&input, &input_lenght, stdin);

    bool result = check_palindrome(input);

    if(result)
    {
        printf("The word is a palindrome!");
    }
    else
    {
        printf("The word is not a palindrome!");
    }
    return 0;
}
