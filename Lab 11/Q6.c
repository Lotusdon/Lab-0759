#include <stdio.h>
#include <string.h>

typedef struct
{
    char city[50];
    char zip_code[50];
} Address;

typedef struct
{
    char name[20];
    int id;
    float salary;
    Address address;
} Employee;

int main()
{
    int n;
    FILE *fptr;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    getchar();

    Employee employees[n];
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter details for employee %d:", i + 1);
        printf("Name: ");
        fgets(employees[i].name, sizeof(employees[i].name), stdin);
        employees[i].name[strcspn(employees[i].name, "\n")] = '\0';
        printf("ID: ");
        scanf("%d", &employees[i].id);
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
        getchar();
        printf("City: ");
        fgets(employees[i].address.city, sizeof(employees[i].address.city), stdin);
        employees[i].address.city[strcspn(employees[i].address.city, "\n")] = '\0';
        printf("Zip Code: ");
        fgets(employees[i].address.zip_code, sizeof(employees[i].address.zip_code), stdin);
        employees[i].address.zip_code[strcspn(employees[i].address.zip_code, "\n")] = '\0';
    }

    fptr = fopen("employees.dat", "wb");
    if (fptr == NULL)
    {
        printf("Error opening file for writing.\n");
        return 1;
    }
    fwrite(employees, sizeof(Employee), n, fptr);
    fclose(fptr);

    printf("Employee data saved to file.\n");

    fptr = fopen("employees.dat", "rb");
    if (fptr == NULL)
    {
        printf("Error opening file for reading.\n");
        return 1;
    }
    printf("\nEmployee Details:\n");
    fread(employees, sizeof(Employee), n, fptr);
    for (int i = 0; i < n; i++)
    {
        printf("\nName: %s\n", employees[i].name);
        printf("ID: %d\n", employees[i].id);
        printf("Salary: %.2f\n", employees[i].salary);
        printf("City: %s\n", employees[i].address.city);
        printf("Zip Code: %s\n", employees[i].address.zip_code);
    }
    fclose(fptr);

    return 0;
}
