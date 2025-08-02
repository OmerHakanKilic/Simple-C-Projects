#include <stdio.h>

int factoriel(int i)
{
    if(i==1) return 1;

    return factoriel(i-1)*i;
}

int main()
{
    int number=0;
    int result=0;
    printf("Enter number: \n");
    scanf("%d",&number);
    result=factoriel(number);
    printf("%d",result);
    return 0;
}