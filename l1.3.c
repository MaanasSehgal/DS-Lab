#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct st
{
    int id;
    char name[100];
    char designation[100];
    float basicSalary;
    float hra;
    float da;
    float grossSalary;
};

void calculateGrossSalary(struct st *employee)
{
    employee->grossSalary = employee->basicSalary + (employee->basicSalary * (employee->hra / 100)) + (employee->basicSalary * (employee->da / 100));
}

int main()
{
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    getchar();

    struct st employees[n];

    for (int i = 0; i < n; i++)
    {
        printf("\n");
        printf("Enter employee %d information:\n", i + 1);
        printf("Name: ");
        fgets(employees[i].name, sizeof(employees[i].name), stdin);
        employees[i].name[strcspn(employees[i].name, "\n")] = 0;

        printf("Designation: ");
        fgets(employees[i].designation, sizeof(employees[i].designation), stdin);
        employees[i].designation[strcspn(employees[i].designation, "\n")] = 0;

        printf("Basic Salary: ");
        scanf("%f", &employees[i].basicSalary);
        printf("HRA %%: ");
        scanf("%f", &employees[i].hra);
        printf("DA %%: ");
        scanf("%f", &employees[i].da);
        getchar();

        calculateGrossSalary(&employees[i]);
    }

    printf("\nEmployee Information:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Name: %s\n", employees[i].name);
        printf("Designation: %s\n", employees[i].designation);
        printf("Basic Salary: %.2f\n", employees[i].basicSalary);
        printf("HRA %%: %.2f\n", employees[i].hra);
        printf("DA %%: %.2f\n", employees[i].da);
        printf("Gross Salary: %.2f\n\n", employees[i].grossSalary);
    }

    return 0;
}
