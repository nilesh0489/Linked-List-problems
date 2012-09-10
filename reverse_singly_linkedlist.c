#include<stdlib.h>
#include<stdio.h>

typedef struct Node
{
	int value;
	struct Node *next;
}Node;

void insert(Node **head, int data)
{
	Node *temp;
	temp = *head;
	if(*head == NULL)
	{
		*head = malloc (sizeof(Node));
		(*head)->value = data;
		(*head)->next = NULL;
	}
	
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		
		Node *curr = malloc(sizeof(Node));
		
		temp->next = curr;
		curr->value = data;
		curr->next = NULL;
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

void reverse(Node **head)
{
	Node *curr, *temp, *prev;
	curr = *head;
	temp = curr->next;
	prev = NULL;	
	
	while(temp != NULL)
	{
		curr->next = prev;
		prev = curr;
		curr = temp;
		temp = temp->next;
	}
	
	if(temp == NULL)
	{
		curr->next = prev;
		*head = curr;
	}
}
int main(void)
{
	Node *head;
	
	insert(&head, 5);
	insert(&head, 9);
	insert(&head, 3);
	insert(&head, 11);
	
	printf("Original List: ");
	print_list(head);
	printf("\n");	

	reverse(&head);
	
	printf("Reversed List: ");
	print_list(head);
	printf("\n");	
	
	return 1;
}
