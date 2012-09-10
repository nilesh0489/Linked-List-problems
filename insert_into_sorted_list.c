#include<stdlib.h>
#include<stdio.h>

typedef struct Node
{
	int data;
	struct Node *next;
}Node;

void insert(Node **head, int data)
{
	Node *newNode;
	
	if(*head == NULL || (*head)->data >=data)
	{
		newNode = malloc(sizeof(Node));
		newNode->next = (*head);
		newNode->data = data;
		(*head) = newNode;
	}
	
	else
	{
		Node *temp = *head;
		newNode = malloc(sizeof(Node));
		while(temp->next != NULL && temp->next->data < data)
		{
				temp = temp->next;
		}
		newNode->next = temp->next;
		newNode->data = data;
		temp->next = newNode;
	}
}

void print(Node *head)
{
	Node *temp = head;
	
	while(temp != NULL)
	{
		printf("%d	", temp->data);
		temp = temp->next;
	}
	
	printf("\n");
}

int main(void)
{
	Node *head = NULL;

	insert(&head, 4);
	insert(&head, 5);
	insert(&head, 2);
	insert(&head, 1);
	
	print(head);
	return 0;
}
