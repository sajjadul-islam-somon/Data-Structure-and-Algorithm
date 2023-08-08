// Linked List of number of students using struct
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int id;
    float cgpa;
    char name[30], sec, dept[10];
    struct Student *next;
}*St;

void creatList(int n)
{
    struct Student *newSt, *temp;
    St = malloc(sizeof(struct Student));

    printf("Enter info of student-1: \n");
    printf("ID          : ");       scanf("%d", &St->id);       getchar();
    printf("Name        : ");       scanf(" %[^\n]", St->name);
    printf("Section     : ");       scanf(" %c", &St->sec);     getchar();
    printf("Department  : ");       scanf(" %[^\n]", St->dept);
    printf("CGPA        : ");       scanf("%f", &St->cgpa);
    St->next = NULL;
    temp = St;

    for (int i = 2; i <= n; i++)
    {
        newSt = malloc(sizeof(struct Student));
        printf("\nEnter info of student-%d: \n", i);
        printf("ID          : ");        scanf("%d", &newSt->id);       getchar();
        printf("Name        : ");        scanf(" %[^\n]", newSt->name);
        printf("Section     : ");        scanf(" %c", &newSt->sec);     getchar();
        printf("Department  : ");        scanf(" %[^\n]", newSt->dept);
        printf("CGPA        : ");        scanf("%f", &newSt->cgpa);
        newSt->next = NULL;
        temp->next = newSt;
        temp = newSt;
    }
}

void display(struct Student *ptr)
{
    int c = 0;
    printf("\n\n--------Student info---------\n\n");
    while (ptr != NULL)
    {
        c++;
        printf("Student-------%d \n", c);
        printf("ID          : %d\n", ptr->id);
        printf("Name        : %s\n", ptr->name);
        printf("Section     : %c\n", ptr->sec);
        printf("Department  : %s\n", ptr->dept);
        printf("CGPA        : %.2f\n\n", ptr->cgpa);
        ptr = ptr->next;
    }
}

int main()
{
    int n;
again:
    printf("\nPlease, Enter number of Students: ");
    scanf("%d", &n);
    if (n < 1)
    {
        getchar();
        goto again;
    }
    creatList(n);
    display(St);
    return 0;
}
