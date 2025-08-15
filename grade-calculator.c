#include <stdio.h>

typedef struct Student
{
    int grades[3];
    char* name;
} Student;

int calculate_avarage_of_student(Student s)
{
    int result=0;

    for(int i=0; i<3; i++)
    {
        result += s.grades[i];
    }
    return result/3;
}

int main()
{
    int number_of_students;
    printf("Enter the number of students you want to record: \n");
    scanf("%d", &number_of_students);
    while (getchar() != '\n');
    Student students[number_of_students];

    for(int i=0; i<number_of_students; i++)
    {
        size_t input_lenght=0;
        printf("Please enter the student's name: \n");
        getline(&students[i].name, &input_lenght, stdin);

        printf("Please enter %s's first grade: \n", students[i].name);
        scanf("%d", &students[i].grades[0]);

        printf("Please enter %s's second grade: \n", students[i].name);
        scanf("%d", &students[i].grades[1]);

        printf("Please enter %s's third grade: \n", students[i].name);
        scanf("%d", &students[i].grades[2]);
        while (getchar() != '\n');
    }

    for(int i=0; i<number_of_students; i++)
    {
        int avarage = calculate_avarage_of_student(students[i]);
        printf("%s", students[i].name);
        printf("Average: %d\n", avarage);
        if(avarage>=60)
        {
            printf("-Passed-\n");
        }
        else
        {
            printf("-Failed-\n");
        }
    }

    return 0;
}
