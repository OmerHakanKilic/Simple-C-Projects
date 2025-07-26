#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int find_operator_index(char input[])
{
    int input_lenght = strlen(input);

    for(int i=0; i < input_lenght; i++)
    {
        switch(input[i])
        {
            case '+':
                return i;
            case '-':
                return i;
            case '*':
                return i;
            case '/':
                return i;
        }
    }
    return -1;
}

int calculate_first_operand(int operator_index, char input[])
{
    char operand_string[operator_index];
    int operand_int;

    for(int i = 0; i < operator_index; i++)
    {
        operand_string[i] = input[i];
    }

    sscanf(operand_string, "%d", &operand_int);
    return operand_int;
}

int calculate_second_operand(int operator_index, char input[])
{
    char operand_string[100];
    int operand_int;
    bool input_end_not_reached = true;
    int i = operator_index+1;
    int j = 0;

    while(input_end_not_reached)
    {
        if(input[i] == '\0')
        {
            input_end_not_reached = false;
        }

        operand_string[j] = input[i];

        i++;
        j++;
    }

    operand_string[0]=input[operator_index+1];
    printf("operand_string: %s", operand_string);
    sscanf(operand_string, "%d", &operand_int);
    return operand_int;
}

int main(void)
{
    char input[10];
    int result;

    printf("Please enter the operation: ");
    scanf("%s", input);

    int operator_index = find_operator_index(input);
    char operator_string = input[operator_index];
    int first_operand = calculate_first_operand(operator_index, input);
    int second_operand = calculate_second_operand(operator_index, input);

    printf("\nfirst operand: %d\n", first_operand);
    printf("second_operand: %d\n", second_operand);

    switch(operator_string)
    {
        case '+':
            result = first_operand+second_operand;
            break;
        case '-':
            result = first_operand-second_operand;
            break;
        case '*':
            result = first_operand*second_operand;
            break;
        case '/':
           result = first_operand/second_operand;
           break;
    }

    printf("Result: %d", result);
    return 0;
}
