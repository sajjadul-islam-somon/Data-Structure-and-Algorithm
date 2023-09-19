//full actions for a linked list (insertion/deletion anywhere of the list)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int id;
    char name[30], sec, dept[10];
    struct student * next;
}*head;

void createlist(int n)
{
    struct student *new, *temp;
    head = (struct student *)malloc(sizeof(struct student));
    printf("\n------Creating Linked List------\n");
    printf("Student-1: \n");
    printf("ID          : ");               scanf("%d", &head->id);         getchar();
    printf("Name        : ");               scanf(" %[^\n]", head->name);
    printf("Section     : ");               scanf(" %c", &head->sec);        getchar();
    printf("Department  : ");               scanf(" %[^\n]", &head->dept);
    head->next = NULL;
    temp = head;
    for (int i = 1; i < n; i++)
    {
        new = (struct student *)malloc(sizeof(struct student));
        printf("Student-%d: \n",i+1);
        printf("ID          : ");               scanf("%d", &new->id);         getchar();
        printf("Name        : ");               scanf(" %[^\n]", new->name);
        printf("Section     : ");               scanf(" %c", &new->sec);       getchar();
        printf("Department  : ");               scanf(" %[^\n]", &new->dept);
        new->next = NULL;
        temp->next = new;
        temp = new;
    }
}

int count()
{
    struct student *temp = head;
    int n = 0;
    while (temp != NULL)
    {
        n++;
        temp = temp->next;
    }
    return n;
}

void insert()
{
    struct student *new, *temp = head;
    new = (struct student *)malloc(sizeof(struct student));

    int n = count();

    printf("\n");
    int p;
    printf("Enter position to insert: ");
    scanf("%d", &p);

    printf("Student-%d: [new]\n",p);
    printf("ID          : ");               scanf("%d", &new->id);         getchar();
    printf("Name        : ");               scanf(" %[^\n]", new->name);
    printf("Section     : ");               scanf(" %c", &new->sec);       getchar();
    printf("Department  : ");               scanf(" %[^\n]", &new->dept);

    if (p == 1)
    {
        new->next = head;
        head = new;
    }
    else if (p == n+1)
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->next = NULL;
    }
    else
    {
        for (int i = 0; i < p-1; i++)
        {
            temp = temp->next;
        }
        new->next = temp->next;
        temp->next = new;
    }
}

void delete()
{
    struct student *temp = head;
    int ID;
    printf("Enter ID u wanna delete: ");
    scanf("%d", &ID);

    int n = count();
    int c = 0;
    if (ID == temp->id) //to delete head node
    {
        printf("\n%d ID is deleted...\n", ID);
        head = temp->next;
        free(temp);
        return;
    }
    else if (ID < n) //to delete in the middle
    {
        for (int i = 0; ID == temp->id; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        free(temp->next->next);
    }
    else //to delete the last node
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        free(temp->next);
    }
}

void search()
{
    struct student *temp = head;
    int ID;
    printf("ID u want to search: ");
    scanf("%d", &ID);
    while (temp != NULL)
    {
        if (ID == temp->id)
        {
            printf("...Search is Found...\n");
            printf("   ...............\n\n");
            break;
        }
        else
        {
            temp = temp->next;
        }
    }
    if (temp == NULL)
    {
        printf("...Search is NOT Fournd...\n");
        printf("   ....................\n\n");
    }
    
}

void display()
{
    struct student *temp = head;
    int i=1;
    printf("\n\tInfo of Students\n");

    while(temp != NULL)
    {
        printf("Student-%d: \n",i++);
        printf("ID          : %d\n", temp->id);
        printf("Name        : %s\n", temp->name);
        printf("Section     : %c\n", temp->sec);
        printf("Department  : %s\n", temp->dept);
        temp = temp->next;
    }
}

int main()
{
    // system("color 4E");
    printf("\e[0;31mThis text is red.\e[0m\n");

    int choice=0,n;
    printf("Please enter the number of students: ");
    scanf("%d", &n);
    createlist(n);    
    while (choice != 5)
    {
        printf("\n\t1. Display\n\t2. Insert\n\t3. Delete\n\t4. Search\n\t5. Exit\n\n");
        printf("Choose: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display();
            break;
        case 2:
            insert();
            break;
        case 3:
            delete();
            break;
        case 4:
            search();
            break;
        case 5:
            break;
        default:
            break;
        }
    }
}
