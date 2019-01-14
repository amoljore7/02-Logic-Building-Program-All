/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	96.Write a program which searches all occurrence of particular element from doubly circular linked list.
//	Function should return number of occurance of that element. 
//	Function Prototype :  int SearchAll( struct node *Head,struct node *Tail,  int no ); 
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
//	Function Name			:	SearchAll
//
//	Description				:	This function finds last occ of an element in the
//								Doubly Circular Linked List,
//
//	Prarmeters				:	1.struct Node *head -> starting address of list.
//								2.struct Node *tail -> ending address of list.
//								3.int no	->	element to search last occ.
//
//	Returns					:	int -> 1 on success , otherwise return 0
//							
//
///////////////////////////////////////////////////////////////////////////////////////////

int SearchAll(struct Node *head , struct Node *tail , int no)
{
	int count=0;

	if(head == NULL)
	{
		return 0;
	}

	do
	{
		if(head -> data == no)
		{
			count++;
		}
		head=head->next;
	}while(head!=tail->next);

	return count;
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
	InsertLast(&first,&last,50);
	InsertLast(&first,&last,90);

	printf("\n\n The linked list is => ");
	Display(first,last);

	int pos=SearchAll(first,last,50);

	if(pos)
	{
		printf("\n\n The element is found %d times in the linked list.",pos);
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
//		Linked list	:	10 20 30 40 50 60 70 80	50 90
//
//		Input		:	50
//
//		Output		:   The last occurrence of an element is found at 9 position.
//
////////////////////////////////////////////////////////////////////////////////////