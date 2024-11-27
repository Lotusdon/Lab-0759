#include <stdio.h>
#include <string.h>

typedef struct
{
    float maths;
    float science;
    float english;
} Marks;

typedef struct
{
    char roll_no[20];
    char name[30];
    Marks marks;
} Student;


int main()
{
    Student students[5];

    for (int i = 0; i < 5; i++)
    {
        printf("Enter roll number of student %d: ", i + 1);
        fgets(students[i].roll_no, sizeof(students[i].roll_no), stdin);
        students[i].roll_no[strcspn(students[i].roll_no, "\n")] = '\0';

        printf("Enter name of student %d: ", i + 1);
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';

        printf("Enter marks obtained in Maths, Science and English: ");
        scanf("%f %f %f", &students[i].marks.maths, &students[i].marks.science, &students[i].marks.english);
        getchar();
        printf("\n");
    }

    float sum;
    for (int i = 0; i < 5; i++)
    {
        sum = 0;
        sum += students[i].marks.maths + students[i].marks.science + students[i].marks.english;
        printf("The average marks of %s (%s) is %.2f.\n", students[i].name, students[i].roll_no, sum / 3);
    }

    return 0;
}
