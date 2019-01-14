////////////////////////////////////////////////////////////////////////////////////
//
//	26.Write a program which counts number of nodes in singly linear linked in
//	recursive manner.
//
////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};
/////////////////////////////////////////////////////////////////////////////////
//
//	Function Name	:	InsertAtLast
//
//	Parameters		:	address of linked list , integer
//
//	Returns			:	integer
//
//	Description		:	This function insert node at the end of linked list.
//
/////////////////////////////////////////////////////////////////////////////////
int InsertAtLast(struct Node **head,int No)
{
	struct Node *newnode=NULL;
	struct Node *temp=*head;


	//allocate memory for newnode
	newnode=(struct Node *)malloc(sizeof(struct Node));

	//check whehter memory is allocated or not.
	if(newnode == NULL)
	{
		return 0;
	}

	newnode->next=NULL;
	newnode->data=No;

	if(*head == NULL)
	{
		*head=newnode;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
	return 1;
}

/////////////////////////////////////////////////////////////////////////////////
//
//	Function Name	:	Display
//
//	Parameters		:	address of linked list 
//
//	Returns			:	void
//
//	Description		:	This function display the linked list.
//
/////////////////////////////////////////////////////////////////////////////////
void Display(struct Node *head)
{
	if(head == NULL)
	{
		return;
	}

	while(head)
	{
		printf("|%d|->",head->data);
		head=head->next;
	}
}
/////////////////////////////////////////////////////////////////////////////////
//
//	Function Name	:	CountNode
//
//	Parameters		:	address of linked list
//
//	Returns			:	integer
//
//	Description		:	This function count number of node in the linked list.
//
/////////////////////////////////////////////////////////////////////////////////

int CountNode(struct Node *head)
{
	static	int count=0;

	if(head == NULL)
	{
		return 0;
	}
	else
	{
		count++;
		CountNode(head->next);
	}
	return count;
}

int main()
{
	struct Node *first=NULL;
	int count=0;

	InsertAtLast(&first,10);
	InsertAtLast(&first,20);
	InsertAtLast(&first,30);
	InsertAtLast(&first,40);
	InsertAtLast(&first,50);
	InsertAtLast(&first,60);

	printf("\n The linked list is => ");
	Display(first);

	count=CountNode(first);
	printf("\n The number of node in the linked list is => %d\n",count);
	
	return 0;
}