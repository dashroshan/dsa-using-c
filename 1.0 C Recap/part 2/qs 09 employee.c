/*
Create an employee structure in C to store the details of five employees
*/

#include <stdio.h>
#define MAX_CHARS 100
#define TOTAL 5

typedef struct employee
{
    char name[MAX_CHARS];
    int id;
    double salary;
} Employee;

void main()
{
    Employee emp[TOTAL];
    printf("Enter id, salary, and name of %d employees:\n", TOTAL);
    for (int i = 0; i < TOTAL; i++)
        scanf("%d %lf %[^\n]%*c", &emp[i].id, &emp[i].salary, emp[i].name);
    printf("\nStored employees: ");
    for (int i = 0; i < TOTAL; i++)
    {
        printf("%s", emp[i].name);
        if (i != TOTAL - 1)
            printf(", ");
    }
}

/*
Enter id, salary, and name of 5 employees:
1 150000 Name 1
2 160000 Name 2
3 170000 Name 3
4 180000 Name 4
5 150000 Name 5

Stored employees: Name 1, Name 2, Name 3, Name 4, Name 5
*/