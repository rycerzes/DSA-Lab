#include <stdlib.h>
#include <stdio.h>

struct employee {
    int id;
    char name[50];
    char designation[50];
    float basic;
    float hrapercent;
    float dapercent;
};

float grosssalary(struct employee e1) {
    float hra = (e1.hrapercent / 100) * e1.basic;
    float da = (e1.dapercent / 100) * e1.basic;
    return e1.basic + hra + da;
}

int main() {
    int n;

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    struct employee *employees = (struct employee *)malloc(n * sizeof(struct employee));

    if (employees == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for employee %d:\n", i + 1);
        printf("employee ID: ");
        scanf("%d", &employees[i].id);

        printf("Name: ");
        scanf("%s", employees[i].name);

        printf("Designation: ");
        scanf("%s", employees[i].designation);

        printf("Basic Salary: ");
        scanf("%f", &employees[i].basic);

        printf("HRA Percentage: ");
        scanf("%f", &employees[i].hrapercent);

        printf("DA Percentage: ");
        scanf("%f", &employees[i].dapercent);
    }

    printf("\nemployee Information with Gross Salary:\n");
    for (int i = 0; i < n; i++) {
        float grossSalary = grosssalary(employees[i]);
        printf("\nemployee ID: %d\n", employees[i].id);
        printf("Name: %s\n", employees[i].name);
        printf("Designation: %s\n", employees[i].designation);
        printf("Gross Salary: %.2f\n", grossSalary);
    }

    free(employees);

    return 0;
}