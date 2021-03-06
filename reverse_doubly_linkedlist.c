#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int value;
	struct Node *next;
	struct Node *prev;
}Node;

void insert(Node **head, int data)
{
	Node *temp = *head;
	if(*head == NULL)
	{
		*head = malloc(sizeof(Node));
		(*head)->next = NULL;
		(*head)->prev = NULL;
		(*head)->value = data;
	}

	else
	{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		Node *curr = malloc(sizeof(Node));
		curr->next = NULL;
		curr->prev = temp;
		temp->next = curr;
		curr->value = data;
	}	
}

void reverse(Node **head)
{
	Node *temp, *curr;
	curr = *head;
	
	while(curr->next != NULL)
	{
		temp = curr->next;
		curr->next = curr->prev;
		curr->prev = temp; 	
		curr = temp;	
	}
	
	if(curr->next == NULL)
	{
		*head = curr;
		(*head)->next = curr ->prev;
		(*head)->prev = NULL;
	}
}

void print_list(Node *head)
{
	Node *temp = head;
	
	while(temp != NULL)
	{
		printf("%d	", temp->value);
		temp = temp->next;
	}
}
int main(void)
{
	Node *head = NULL;
	
	insert(&head, 1);
	insert(&head, 2);
	insert(&head, 3);
	insert(&head, 4);
	
	printf("Original List: ");
	print_list(head);
	printf("\n");
	
	reverse(&head);
	printf("Reversed List: ");
	print_list(head);
	printf("\n");	
	return 0;
}
