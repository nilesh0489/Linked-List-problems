#include<stdlib.h>
#include<stdio.h>

typedef struct Node
{
	int value;
	struct Node *next;
}Node;

void insert(Node **head, int data)
{
	Node *temp = *head;
	
	if(*head == NULL)
	{
		*head = malloc(sizeof(Node));
		(*head)->next = NULL;
		(*head)->value = data;
	}
	
	else
	{
		while(temp->next != NULL)
		{
			temp = temp->next;	
		}
		Node *curr;
		curr = malloc(sizeof(Node));
		temp->next = curr;
		curr->value = data;
		curr->next = NULL;
	}
}

void print(Node *head)
{
	Node *temp = head;
	
	while(temp != NULL)
	{
		printf("%d	", temp->value);
		temp = temp->next;
	}
	printf("\n");
}

void sort(Node *head)
{
	Node *temp_head = head;
	if(temp_head->next != NULL)
	{
		Node *curr_temp = temp_head;
		
		while(curr_temp != NULL)
		{
			if(temp_head->value > curr_temp->value)
			{
				int temp;
				temp = temp_head->value;
				temp_head->value = curr_temp->value;
				curr_temp->value = temp;
			}
			curr_temp = curr_temp->next;
		}
		sort(temp_head->next);	
	}
}

int main(void)
{
	Node *head = NULL;
	
	insert(&head, 03);
	insert(&head, 26);
	insert(&head, -32);
	insert(&head, 46);
	insert(&head, -4);
	
	print(head);
	sort(head);
	print(head);
	return 0;
}
