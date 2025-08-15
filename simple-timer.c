#include <stdio.h>
#include<unistd.h>

int main()
{

    int time_to_measure;
    printf("Enter the time want to measure: \n");
    scanf("%d", &time_to_measure);

    while(time_to_measure>=0)
    {
        printf("Time remaining: %d\n", time_to_measure);
        sleep(1);
        time_to_measure--;
    }
    printf("Timer off");
    return 0;
}
