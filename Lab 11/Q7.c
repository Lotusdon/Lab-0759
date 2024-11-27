#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[20];
    int year_established;
    char departments[5][20];
} Company;

int main()
{
    Company company;

    printf("Enter the name of the company: ");
    fgets(company.name, sizeof(company.name), stdin);
    company.name[strcspn(company.name, "\n")] = '\0';

    printf("Enter the year the company was established: ");
    scanf("%d", &company.year_established);
    getchar();

    for (int i = 0; i < 5; i++)
    {
        printf("Enter the name of department %d: ", i + 1);
        fgets(company.departments[i], sizeof(company.departments[i]), stdin);
        company.departments[i][strcspn(company.departments[i], "\n")] = '\0';
    }

    printf("\nPrinting all the details:\n");
    printf("Company name: %s\n", company.name);
    printf("Year established: %d\n", company.year_established);
    for (int i = 0; i < 5; i++)
    {
        printf("Department %d: %s\n", i + 1, company.departments[i]);
    }

    return 0;
}
