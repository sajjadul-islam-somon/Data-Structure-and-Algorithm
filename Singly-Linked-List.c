//Singly Linked List

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int Data;
    struct node *next;
} *head;

void display(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->Data);
        ptr = ptr->next;
    }
}

int main()
{
    struct node *head2, *head3;
    head = malloc(sizeof(struct node));
    head2 = malloc(sizeof(struct node));
    head3 = malloc(sizeof(struct node));

    head->Data = 1;
    head->next = head2;

    head2->Data = 2;
    head2->next = head3;

    head3->Data = 3;
    head3->next = NULL;

    display(head);
    return 0;
}
