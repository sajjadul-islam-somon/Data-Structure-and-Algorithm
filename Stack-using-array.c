//Stack using array

#include <stdio.h>
#include <stdlib.h>
int top = -1;
void push(int n, int stack[])
{
    top++;
    if (top >= n)
    {
        printf("Stack overflow! Unable to insert new value\n");
        top--;
    }
    else
    {
        printf("Insert value in stack\n");
        scanf("%d", &stack[top]);
    }
}
void pop()
{
    if (top < 0)
    {
        printf("Stack is empty. Unable to delete value from stack\n");
    }
    else
    {
        top--;
    }
}
void display(int stack[])
{
    printf("Display stack\n");
    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}
int main()
{
    int n, choice = 0;
    printf("Enter stack size:\n");
    scanf("%d", &n);
    int stack[n];
    printf("1. Insert an element in stack\n");
    printf("2. Delete an element from stack\n");
    printf("3. Display the values in stack\n");
    printf("4. Exit operation\n");
    while (choice != 4)
    {
        printf("Enter choice you want to perform\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push(n, stack);
            break;
        case 2:
            pop();
            break;
        case 3:
            display(stack);
            break;
        case 4:
            break;
        default:
            printf("Enter right choice in between 1 to 4\n");
            break;
        }
    }
}
