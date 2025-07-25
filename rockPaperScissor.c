#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int turn(int choice)
{
    srand(time(NULL));
    int aiChoice = rand() % 3 + 1;

    printf("AI: %d\n", aiChoice);

    if(choice == aiChoice)
    {
        return 0;
    }
    switch(choice)
    {
        case 1:
            if(aiChoice==2)
            {
                return -1;
            }
            if(aiChoice==3)
            {
                return 1;
            }
        case 2:
            if(aiChoice==1)
            {
                return 1;
            }
            if(aiChoice==3)
            {
                return -1;
            }
        case 3:
            if(aiChoice==1)
            {
                return -1;
            }
            if(aiChoice==2)
            {
                return 1;
            }
    }

}
int main(void)
{
    int choice = 0;
    printf("Welcome to rock, paper, scissors game!\nPlease select rock, paper or scissor with typing the associated number.\n1)Rock\n2)Paper\n3)Scissor\n");

    scanf("%d", &choice);

    int result = turn(choice);

    switch(result)
    {
        case 1:
            printf("You won!");
            break;
        case -1:
            printf("You lost!");
            break;
        case 0:
            printf("Draw!");
            break;
        default:
            break;
    }

    return 0;
}
