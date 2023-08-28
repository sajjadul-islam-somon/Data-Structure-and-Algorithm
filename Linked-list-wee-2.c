//linked list insertion & deletion

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int id;
    float cgpa;
    char name[30], sec, dept[10];
    struct Student *next;
}*st;

void createList(int n)
{
    struct Student *temp, *newSt;
    st = (struct Student *)malloc(sizeof(struct Student));
    
    printf("Student-1:\n");
    printf("ID          : ");       scanf("%d", &st->id);               getchar();
    printf("Name        : ");       scanf(" %[^\n]", st->name);
    printf("Section     : ");       scanf(" %c", &st->sec);             getchar();
    printf("Department  : ");       scanf(" %[^\n]", &st->dept);
    printf("CGPA        : ");       scanf("%f", &st->cgpa);
    st->next = NULL;
    temp = st;

    for (int i = 1; i < n; i++)
    {
        newSt = (struct Student *)malloc(sizeof(struct Student));

        printf("Student-%d\n",i+1);
        printf("ID          : ");       scanf("%d", &newSt->id);        getchar();
        printf("Name        : ");       scanf(" %[^\n]", newSt->name);
        printf("Section     : ");       scanf(" %c", &newSt->sec);      getchar();
        printf("Department  : ");       scanf(" %[^\n]", newSt->dept);
        printf("CGPA        : ");       scanf("%f", &newSt->cgpa);

        newSt->next = NULL;
        temp->next = newSt;
        temp = newSt;
    } 
}

void display()
{
    struct Student * temp = st;
    int i=1;

    printf("\n\n--------Info of Students-------\n");
    while(temp != NULL)
    {
        printf("\nStudent-%d\n",i++);
        printf("Name        :%s\n", temp->name);
        printf("ID          :%d\n", temp->id);
        printf("Section     :%c\n", temp->sec);
        printf("Department  :%s\n", temp->dept);
        printf("CGPA        :%.2f\n", temp->cgpa);

        temp = temp->next;
    }
}

void search()
{
    struct Student * temp = st;
    int ID;

    printf("\nSearch Student 'ID': ");
    scanf("%d", &ID);
    while (temp != NULL)
    {
        if (ID == temp->id)
        {
            printf("Searched Student is Found...:)\n");
            break;
        }
        else
        {
            temp = temp->next;
        }
    }
    if (temp == NULL)
    {
        printf("Oops! NOT Found . . . :(\n");
    }
}

void insertBegin()
{
    struct Student *newSt = (struct Student *)malloc(sizeof(struct Student));

    printf("\nAdd info in the Begining of the list:\n");
    printf("\nStudent-1 (NEW)\n");
    printf("ID          : ");       scanf("%d", &newSt->id);            getchar();
    printf("Name        : ");       scanf(" %[^\n]", newSt->name);
    printf("Section     : ");       scanf(" %c", &newSt->sec);          getchar();
    printf("Department  : ");       scanf(" %[^\n]", newSt->dept);
    printf("CGPA        : ");       scanf("%f", &newSt->cgpa);

    newSt->next = st;
    st = newSt;
}

void insertEnd(int n)
{
    struct Student *newSt, *temp = st;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    newSt = (struct Student *)malloc(sizeof(struct Student));

    printf("\nAdd info in the End of the list:\n");
    printf("\nStudent-%d (NEW)\n",n+1);
    printf("ID          : ");       scanf("%d", &newSt->id);            getchar();
    printf("Name        : ");       scanf(" %[^\n]", newSt->name);
    printf("Section     : ");       scanf(" %c", &newSt->sec);          getchar();
    printf("Department  : ");       scanf(" %[^\n]", newSt->dept);
    printf("CGPA        : ");       scanf("%f", &newSt->cgpa);
    temp->next = newSt;
    newSt->next = NULL;
}

void insertMiddle()
{
    int n;
    struct Student *newSt, *temp = st;
    newSt = malloc(sizeof(struct Student));

    printf("Enter index to input Data: ");
    scanf("%d", &n);

    for (int i = 1; i < n-1; i++)
    {
        temp = temp->next;
    }
    printf("\nStudent-%d (NEW)\n",n);
    printf("ID          : ");       scanf("%d", &newSt->id);            getchar();
    printf("Name        : ");       scanf(" %[^\n]", newSt->name);
    printf("Section     : ");       scanf(" %c", &newSt->sec);          getchar();
    printf("Department  : ");       scanf(" %[^\n]", newSt->dept);
    printf("CGPA        : ");       scanf("%f", &newSt->cgpa);
    newSt->next = temp->next;
    temp->next = newSt;
}

void deleteBegin()
{
    struct Student *temp = st;

    printf("First info is being deleted . . .\n");
    st = st->next;
    free(temp);
}

void deleteEnd()
{
    struct Student *temp = st;

    printf("Last info is being deleted . . .\n");
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    free(temp->next);
}

void deleteMiddle()
{
    struct Student *temp = st;
    int n;
    printf("Please enter ID you want to delete: ");
    scanf("%d", &n);
    for (int i = 1; i < n-1; i++)
    {
        temp = temp->next;
    }
    temp->next = temp->next->next;
    free(temp->next->next);
    printf("Info %d has been deleted . . .\n", n);
}

int main()
{
    int n;
    printf("Enter number of Students: ");
    scanf("%d", &n);
    
    createList(n);
    search(st);
    insertBegin();
    insertEnd(n);
    insertMiddle();
    deleteBegin();
    deleteEnd();
    deleteMiddle();

    display(st);
    return 0;
}
