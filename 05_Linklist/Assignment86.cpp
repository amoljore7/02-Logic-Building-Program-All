///////////////////////////////////////////////////////////////////////////////////////////////
//
//	86.Write a program which add new node in doubly circular linked list at first position. 
//	Function Prototype :  int InsertFirst( struct node **Head, struct node **Tail,  int no ); 
//
///////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct Node
{
	int		data;
	struct Node	*next,*prev;
};


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertFirst
//
//	Description				:	This function adds node to Doubly Circular Linked List.
//
//	Prarmeters				:	1.struct Node **head -> starting address of list.
//								2.struct Node **tail -> ending address of list.
//								3.int no	->	element to insert.
//
//	Returns					:	int -> 1 on success , otherwise return 0
//							
//
///////////////////////////////////////////////////////////////////////////////////////////
int InsertFirst (
				struct Node **head,
				struct Node **tail,
				int no
			)
{
	struct Node *newnode = NULL;

	//	Allocate new node.
	
	newnode = (struct Node *)malloc(sizeof(struct Node));
	if (NULL == newnode)
	{
		return 0;
	}

	//
	//	Fill the node with data.
	//
	newnode->next =newnode->prev= NULL;
	newnode->data = no;

	//	Prepend
	if (NULL == *head && *tail == NULL)
	{
		*head=*tail=newnode;
		(*tail) -> next = *head;
		(*head)->prev=*tail;
	}
	else
	{
		newnode -> next = *head;
		(*head) ->prev=newnode;
		*head = newnode;
		(*tail) ->next = *head;
		(*head) ->prev=*tail;
		
	}

	return 1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	Display
//
//	Description			:	This function displays Doubly Circular Linked List.
//
//	Returns				:	void
//
///////////////////////////////////////////////////////////////////////////////////////////

void Display(
				struct Node *head,
				struct Node *tail
			)
{
	do
	{
		printf("|%d| -> ",head -> data);
		head = head -> next;
	}while(head != tail->next);
}

int main()
{
	struct Node *first=NULL;
	struct Node *last=NULL;

	InsertFirst(&first,&last,50);
	InsertFirst(&first,&last,40);
	InsertFirst(&first,&last,30);
	InsertFirst(&first,&last,20);
	InsertFirst(&first,&last,10);

	printf("\n\n The linked list is => ");
	Display(first,last);

	InsertFirst(&first,&last,5);
	InsertFirst(&first,&last,4);

	printf("\n\n After adding node at first position , the list is => ");
	Display(first,last);

	getch();
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////
//
//		Linked list	:	10 20 30 40 50	
//
//		Input		:	5
//
//		Output		:   5 10 20 30 40 50
//
////////////////////////////////////////////////////////////////////////////////////