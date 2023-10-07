//Queue using linke list

// Queue using linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
} *front, *rear;

void enqueue()
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    if (new == NULL)
    {
        printf("Queue overflow\n");
    }
    else
    {
        printf("Enter Value: ");
        scanf("%d", &new->value);
        if (rear == NULL)
        {
            new->next = NULL;
            front = rear = new;
        }
        else
        {
            new->next = NULL;
            rear->next = new;
            rear = new;
        }
        printf("Value Successfully Added...\n");
    }
}

void dequeue()
{
    struct node *temp = front;
    if (front == NULL)
    {
        printf("Empty Queue\n");
    }
    else
    {
        front = front->next;
        free(temp);
        if (front == NULL)
        {
            rear == NULL;
        }
        printf("Successfully Deleted\n");
    }
}

void display()
{
    struct node *temp = front;
    if (front == NULL)
    {
        printf("Empty Queue\n");
    }
    else
    {
        printf("Displaying Queue: \n");
        while (temp != NULL)
        {
            printf("%d\n", temp->value);
            temp = temp->next;
        }
    }
}

int main()
{
    int n = 0;
    printf("\n***Queue Operation using Linked List***\n");
    while (n != 4)
    {
        printf("\n1. Add value\n2. Delete Value\n3. Display\n4. Exit\n\n");
        printf("Enter Choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exit");
            system("cls");
            return 0;
        default:
            printf("Please enter valid number\n");
            break;
        }
    }
    return 0;
}
