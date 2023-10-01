// Linked list by position.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char name[30];
    int id;
    char address[40];
    struct node *next;
} *head;

int count()
{
    struct node *temp = head;
    int n = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        n++;
    }
    return n;
}

void insert()
{
    struct node *new, *temp = head;
    new = malloc(sizeof(struct node));
    int p, n = count();
    printf("Position for Insertion: ");
    scanf("%d", &p);                                              getchar();
    printf("Name        : ");       scanf(" %[^\n]", new->name);
    printf("ID          : ");       scanf("%d", &new->id);        getchar();
    printf("Address     : ");       scanf(" %[^\n]", new->address);
    if (n == 0)
    {
        new->next = NULL;
        head = new;
    }
    else if (p == 1)
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
        new->next = NULL;
        temp->next = new;
    }
    else
    {
        for (int i = 0; i < p-2; i++)
        {
            temp = temp->next;
        }
        new->next = temp->next;
        temp->next = new;
    }
}

void delete()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        int p;
        printf("Enter Postion to delete: ");
        scanf("%d", &p);
        int n = count();
        if (p == 1)                         //delete first element
        {
            head = head->next;
            free(temp);
        }
        else                               //delete other element
        {
            for (int i = 0; i < p-2; i++)
            {
                temp = temp->next;
            }
            temp->next = temp->next->next;
        }
    }
}

void display()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        printf("\nDisplaying Linked-list...\n");
        while (temp != NULL)
        {
            printf("Name        : %s\n", temp->name);
            printf("Id          : %d\n", temp->id);
            printf("Address     : %s\n", temp->address);
            temp = temp->next;
        }
    }
}

void reverse(struct node *head)
{
    if (head == NULL)
    {
        return;
    }
    printf("Reverse Linked-List:\n");
    reverse(head->next);
    printf("Name        : %s\n", head->name);
    printf("Id          : %d\n", head->id);
    printf("Address     : %s\n", head->address);
}

int main()
{
    printf("\n\tLinked-List\n");
    int choice = 0;
    while (choice != 5)
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Reverse Display\n5. Exit\n\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            reverse(head);
            break;
        case 5:
            printf("exit");
            system("cls");
            return 0;
        default:
            printf("Please enter valid number...\n");
            break;
        }
    }
    return 0;
}
