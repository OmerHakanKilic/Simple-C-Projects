#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int generate_number()
{
    int number = 0;
    srand(time(NULL));
    number = rand() % 100 + 1;
    return number;
}

bool turn(int number)
{
    int guess;
    printf("Please enter a number: \n");
    scanf("%d", &guess);

    if(guess == number)
    {
        return true;
    }
    if(guess > number)
    {
        printf("Your guess is bigger than the generated number\n");
        return false;
    }
    if(guess < number)
    {
        printf("Your guess is smaller than the generated number\n");
        return false;
    }

}

int main(void)
{
    bool win = false;
    int number = generate_number();
    int tries = 0;

    printf("Welcome to the number guessing game!\n");
    printf("You need to guess a randomly generated number between 1 and 100\n");

    do
    {
        win = turn(number);
        tries++;
    }
    while(!win);

    printf("You won with %d tries!", tries);
    return 0;
}
