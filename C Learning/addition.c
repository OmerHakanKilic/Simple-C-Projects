#include <stdio.h>

int addition(int a, int b)
{
    return a+b;
}


int main(void)
{
    int a,b = 0;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);
    int result = addition(a,b);
    printf("Result: %d", result);
    return 0;
}

