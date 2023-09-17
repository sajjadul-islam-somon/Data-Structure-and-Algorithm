//stack using linked list

#include <stdio.h>  
#include <stdlib.h>

void push();
void pop();
void display();

struct node
{
	int value;
	struct node* next;
}* head;

void main()
{
	int choice = 0;
	printf("\n***Stack operations using linked list***\n");
	printf("\n----------------------------------------\n");
	while (choice != 4)
	{
		printf("\n\nChose one from the below options...\n");
		printf("\n\t1.Push\n\t2.Pop\n\t3.Show\n\t4.Exit");
		printf("\n Enter your choice: \n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
		{
			push();
			break;
		}
		case 2:
		{
			pop();
			break;
		}
		case 3:
		{
			display();
			break;
		}
		case 4:
		{
			printf("Exit....");
			break;
		}
		default:
		{
			printf("Please Enter valid choice: ");
		}
		};
	}
}
void push()
{
	int value;
	struct node* ptr = (struct node*)malloc(sizeof(struct node));
	if (ptr == NULL)
	{
		printf("not able to push the element");
	}
	else
	{
		printf("Enter the value: ");
		scanf("%d", &value);
		if (head == NULL)
		{
			ptr->value = value;
			ptr->next = NULL;
			head = ptr;
		}
		else
		{
			ptr->value = value;
			ptr->next = head;
			head = ptr;
		}
		printf("Item pushed");
	}
}

void pop()
{
	int item;
	struct node* ptr;
	if (head == NULL)
	{
		printf("Underflow");
	}
	else
	{
		item = head->value;
		ptr = head;
		head = head->next;
		free(ptr);
		printf("Item popped");

	}
}
void display()
{
	int i;
	struct node* ptr;
	ptr = head;
	if (ptr == NULL)
	{
		printf("Stack is empty\n");
	}
	else
	{
		printf("Printing Stack elements \n");
		while (ptr != NULL)
		{
			printf("%d\n", ptr->value);
			ptr = ptr->next;
		}
	}
}
