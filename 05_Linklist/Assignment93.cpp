/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	93.Write a program which search first occurrence of particular element from singly linear linked list. 
//	Function should return position at which element is found. 
//	Function Prototype :  int SearchFirstOcc( struct node *Head,struct node *Tail, int no ); 
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
//	Function Name			:	InsertLast
//
//	Description				:	This function adds node to Doubly Circular Linked List,
//								at last position.
//
//	Prarmeters				:	1.struct Node **head -> starting address of list.
//								2.struct Node **tail -> ending address of list.
//								3.int no	->	element to insert.
//
//	Returns					:	int -> 1 on success , otherwise return 0
//							
//
///////////////////////////////////////////////////////////////////////////////////////////
int InsertLast (
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
		(*tail)->next=newnode;
		newnode->prev=*tail;
		*tail=newnode;
		(*tail)->next=*head;
		(*head)->prev=*tail;
	}

	return 1;
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	SearchFirstOcc
//
//	Description				:	This function finds first occ of an element in the
//								Doubly Circular Linked List,
//
//	Prarmeters				:	1.struct Node *head -> starting address of list.
//								2.struct Node *tail -> ending address of list.
//								3.int no	->	element to search first occ.
//
//	Returns					:	int -> 1 on success , otherwise return 0
//							
//
///////////////////////////////////////////////////////////////////////////////////////////

int SearchFirstOcc(struct Node *head , struct Node *tail , int no)
{
	int pos=0;

	if(head == NULL)
	{
		return 0;
	}

	do
	{
		pos++;
		if(head -> data == no)
		{
			return pos;
		}
		head=head->next;
	}while(head!=tail->next);

	return 0;
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

	InsertLast(&first,&last,10);
	InsertLast(&first,&last,20);
	InsertLast(&first,&last,30);
	InsertLast(&first,&last,40);
	InsertLast(&first,&last,50);
	InsertLast(&first,&last,60);
	InsertLast(&first,&last,70);
	InsertLast(&first,&last,80);

	printf("\n\n The linked list is => ");
	Display(first,last);

	int pos=SearchFirstOcc(first,last,70);

	if(pos)
	{
		printf("\n\n The element is found at %d position",pos);
	}
	else
	{
		printf("\n\n The element is not found in the list.");
	}	

	getch();
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////
//
//		Linked list	:	10 20 30 40 50 60 70 80	
//
//		Input		:	60
//
//		Output		:   The element is found at 6 position.
//
////////////////////////////////////////////////////////////////////////////////////