#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
    int id;
    char name[50];
    float salary;
};

struct Employee *emp[MAX_EMPLOYEES];   // Array of pointers to Employee
int count = 0;                         // Number of employees

void addEmployee() {
    if (count >= MAX_EMPLOYEES) {
        printf("Employee list is full!\n");
        return;
    }

    struct Employee *e = (struct Employee *)malloc(sizeof(struct Employee));

    printf("Enter ID: ");
    scanf("%d", &e->id);

    printf("Enter Name: ");
    scanf("%s", e->name);

    printf("Enter Salary: ");
    scanf("%f", &e->salary);

    emp[count] = e;
    count++;

    printf("Employee added!\n\n");
}

void displayEmployees() {
    if (count == 0) {
        printf("No employees to show.\n\n");
        return;
    }

    printf("\nID\tName\t\tSalary\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%.2f\n",
               emp[i]->id,
               emp[i]->name,
               emp[i]->salary);
    }
    printf("\n");
}

void searchEmployee() {
    int id;

    printf("Enter ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (emp[i]->id == id) {
            printf("Found: %s, Salary: %.2f\n\n",
                   emp[i]->name,
                   emp[i]->salary);
            return;
        }
    }

    printf("Employee not found.\n\n");
}

void deleteEmployee() {
    int id;

    printf("Enter ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (emp[i]->id == id) {
            free(emp[i]);              // Free allocated memory
            emp[i] = emp[count - 1];   // Replace with last employee
            count--;

            printf("Employee deleted.\n\n");
            return;
        }
    }

    printf("Employee not found.\n\n");
}

void freeAll() {
    for (int i = 0; i < count; i++) {
        free(emp[i]);
    }
    count = 0;
}

int main() {
    int choice;

    do {
        printf("1. Add\n");
        printf("2. Display\n");
        printf("3. Search\n");
        printf("4. Delete\n");
        printf("5. Exit\n");
        printf("Choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;

            case 2:
                displayEmployees();
                break;

            case 3:
                searchEmployee();
                break;

            case 4:
                deleteEmployee();
                break;

            case 5:
                freeAll();
                printf("Bye!\n");
                break;

            default:
                printf("Invalid choice.\n\n");
        }

    } while (choice != 5);

    return 0;
}