#include<stdlib.h>
#include<stdio.h>

typedef struct Node
{
	int data;
	struct Node *next;
}Node;

void read_backwards(Node *head)
{
	if(head == NULL)
	{
		return;
	}
	else
	{
		read_backwards(head->next);
		printf("%d	", head->data);
	}
	
	printf("\n");
}

void insert(Node **head, int data)
{
	Node *temp = *head;
	
	if(*head == NULL)
	{
		*head = malloc(sizeof(Node));
		(*head)->data = data;
		(*head)->next = NULL;
	}
	
	else
	{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		
		Node *curr = malloc(sizeof(Node));
		curr->data = data;
		temp->next = curr;
		curr->next = NULL;
	}
}


int main(void)
{
	Node *head = NULL;
	
	insert(&head, 1);
	insert(&head, 2);
	insert(&head, 3);
	insert(&head, 4);
	insert(&head, 5);
	
	read_backwards(head);
	return 0;	
}
