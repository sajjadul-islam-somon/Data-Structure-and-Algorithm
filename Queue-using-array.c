//Queue using array

#include <stdio.h>
#include <stdlib.h>

int front = -1, rear = -1;

void enqueue(int n, int queue[])
{
    rear++;
    if (rear == n)
    {
        printf("Queue overflow! Unable to insert new value\n");
    }
    else
    {
        if (front == -1)
        {
            front++;
        }
        printf("Enter the value u wanna insert: ");
        scanf("%d", &queue[rear]);
    }
}

void dequeue(int queue[])
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty. Unable to delete value from queue\n");
    }
    else
    {
        printf("Deleted element: %d\n", queue[front]);
        front++;
        if (front > rear)
        {
            front = rear = -1;
        }
    }
}

void display(int queue[])
{
    if (front != -1)
    {
        printf("Display queue\n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d  ", queue[i]);
        }
        printf("\n");
    }
    else
    {
        printf("---------Emptyj---------\n");
    }
}

int main()
{
    int n, choice = 0;
    printf("Enter queue size:\n");
    scanf("%d", &n);
    int queue[n];

    printf("1. Insert an element in queue\n");
    printf("2. Delete an element from queue\n");
    printf("3. Display the values in queue\n");
    printf("4. Exit operation\n");

    while (choice != 4)
    {
        printf("Enter choice you want to perform\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue(n, queue);
            break;
        case 2:
            dequeue(queue);
            break;
        case 3:
            display(queue);
            break;
        case 4:
            break;
        default:
            printf("Enter right choice in between 1 to 4\n");
            break;
        }
    }
}
