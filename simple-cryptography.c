#include <stdio.h>
#include <string.h>

//65 - 90 A - Z, 97 - 122 a - zs

int normalize_key(int key)
{
    key = key % 26;
    return key;
}
char fit_in_alphabet_lower_case(char c)
{
    if(c >= 97 && c <= 122)
    {
        return c;
    }
    else if(c >= 97)
    {
        return fit_in_alphabet_lower_case(-26);
    }
    else if(c <= 122)
    {
        return fit_in_alphabet_lower_case(+26);
    }
    else
    {
        return '!';
    }
}

char fit_in_alphabet_upper_case(char c)
{
    if (c >= 65 && c <= 90)
    {
        return c;
    }
    else if(c >= 65 )
    {
        return fit_in_alphabet_upper_case(c-26);
    }
    else if(c <= 90)
    {
        return fit_in_alphabet_upper_case(c+26);
    }
    else
    {
        return '!';
    }
}

char* decyper()
{
    printf("To cypher you need to enter a text and key\nPlease enter your text:\n");
    char* plaintext;
    size_t buffer_size=0;
    ssize_t input_size;
    int key = 0;
    input_size = getline(&plaintext, &buffer_size, stdin);
    plaintext[strcspn(plaintext, "\n")] = 0;
    printf("input size:%zu\n", input_size);
    printf("Please enter your key: \n");
    scanf("%d", &key);
    key = normalize_key(key);
    for (int i = 0;i <input_size-1 ; i++)
    {
        if(plaintext[i] == 32)
        {
            continue;
        }
        plaintext[i] -= key;
        if (plaintext[i] >= 65-key && plaintext[i] <= 90-key)
        {
            if(plaintext[i] > 90)
            {
                plaintext[i] = fit_in_alphabet_upper_case(plaintext[i]);
            }
        }
        else if(plaintext[i] >= 97-key && plaintext[i] <= 122-key)
        {
            if(plaintext[i] > 122)
            {
                plaintext[i] =fit_in_alphabet_lower_case(plaintext[i]);
            }
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
    size_t buffer_size=0;
    ssize_t input_size;
    int key = 0;
    input_size = getline(&plaintext, &buffer_size, stdin);
    plaintext[strcspn(plaintext, "\n")] = 0;
    printf("input size:%zu\n", input_size);
    printf("Please enter your key: \n");
    scanf("%d", &key);
    key = normalize_key(key);
    for (int i = 0;i <input_size-1 ; i++)
    {
        if(plaintext[i] == 32)
        {
            continue;
        }
        plaintext[i] += key;
        if (plaintext[i] >= 65+key && plaintext[i] <= 90+key)
        {
            if(plaintext[i] > 90)
            {
                plaintext[i] = fit_in_alphabet_upper_case(plaintext[i]);
            }
        }
        else if(plaintext[i] >= 97+key && plaintext[i] <= 122+key)
        {
            if(plaintext[i] > 122)
            {
                plaintext[i] =fit_in_alphabet_lower_case(plaintext[i]);
            }
        }
        else
        {
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
