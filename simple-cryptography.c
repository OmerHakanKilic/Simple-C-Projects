#include <stdio.h>
#include <string.h>
#include <unistd.h>

//65 - 90 A - Z, 97 - 122 a - zs

int normalize_key(int key)
{
    return key % 26;
}
char fit_in_alphabet_lower_case(char c)
{
    while (c < 97)
    {
        c += 26;
    }
    while (c > 122)
    {
        c -= 26;
    }
    return c;
}

char fit_in_alphabet_upper_case(char c)
{
    while (c < 65)
    {
        c += 26;
    }
    while (c > 90)
    {
        c -= 26;
    }
    return c;
}

char* decyper()
{
    char* plaintext;
    size_t buffer_size=0;
    ssize_t input_size;
    int key = 0;

    printf("To cypher you need to enter a text and key\nPlease enter your text:\n");
    input_size = getline(&plaintext, &buffer_size, stdin);
    plaintext[strcspn(plaintext, "\n")] = 0;

    printf("input size:%zu\n", input_size);

    printf("Please enter your key: \n");
    scanf("%d", &key);
    while (getchar() != '\n');
    key = normalize_key(key);

    for (int i = 0;i <input_size-1 ; i++)
    {
        if(plaintext[i] == ' ')
        {
            continue;
        }
        else if (plaintext[i] >= 65 && plaintext[i] <= 90)
        {
            plaintext[i] -= key;
            plaintext[i] = fit_in_alphabet_upper_case(plaintext[i]);
        }
        else if(plaintext[i] >= 97 && plaintext[i] <= 122)
        {
            plaintext[i] -= key;
            plaintext[i] =fit_in_alphabet_lower_case(plaintext[i]);
        }
        else
        {
            return "Error: invalid input\n";
        }
    }
    return plaintext;
}

char* cypher()
{
    printf("To cypher you need to enter a text and key\nPlease enter your text:\n");
    char* plaintext;
    size_t buffer_size = 0;
    ssize_t input_size;
    int key = 0;

    input_size = getline(&plaintext, &buffer_size, stdin);
    plaintext[strcspn(plaintext, "\n")] = 0;

    printf("input size:%zu\n", input_size);
    printf("Please enter your key: \n");

    scanf("%d", &key);
    while (getchar() != '\n');
    key = normalize_key(key);
    printf("Normalized key: %d\n", key);

    for (int i = 0;i <input_size-1 ; i++)
    {
        if(plaintext[i] == ' ')
        {
            continue;
        }
        else if (plaintext[i] >= 65 && plaintext[i] <= 90)
        {
            plaintext[i] += key;
            plaintext[i] = fit_in_alphabet_upper_case(plaintext[i]);
        }
        else if(plaintext[i] >= 97 && plaintext[i] <= 122)
        {
            plaintext[i] += key;
            plaintext[i] =fit_in_alphabet_lower_case(plaintext[i]);
        }
        else
        {
            printf("Error: %c with id:%d is invalid\n", plaintext[i],plaintext[i]);
            return "Error: invalid input\n";
        }
    }
    return plaintext;
}

void menu()
{
    printf("To cypher press 1\nTo decyper press 2\n");
    int choice =0;
    scanf("%d",&choice);

    while (getchar() != '\n');
    switch (choice)
    {
        case 1:printf("Cypher: %s", cypher()); break;
        case 2:printf("Decypher: %s", decyper()); break;
        default:printf("Invalid number...");
    }
}

int main()
{

    menu();
    return 0;
}
