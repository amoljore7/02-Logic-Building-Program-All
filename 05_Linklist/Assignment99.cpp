//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	99.Write a program which accept doubly circular linked list from and check whether linked list is pallindrom or not. 
//	Function Prototype :  int ListPallindrom( struct node *First, struct node *Tail); ; 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	ListPallindrom
//
//	Description				:	This function checks whether linked list pallindrom or not.
//
//	Prarmeters				:	1.struct Node *head -> starting address of 1st list.
//								2.struct Node *tail -> ending address of 1st list.
//
//	Returns					:	int -> 1 on success , otherwise return 0
//							
/////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

int ListPallindrom(
					struct Node *head,
					struct Node *tail
				)
{	
	if(head == NULL )
	{
		return 0;
	}

	do
	{
		if(head->data != tail->data)
		{
			return 0;
		}
		head=head->next;
		tail=tail->prev;

	}while( head!=tail->next && head!=tail);
	

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
	struct Node *first1=NULL;
	struct Node *last1=NULL;

	struct Node *first2=NULL;
	struct Node *last2=NULL;
	
	int result=0;

	InsertLast(&first1,&last1,10);
	InsertLast(&first1,&last1,20);
	InsertLast(&first1,&last1,30);
	InsertLast(&first1,&last1,20);
	InsertLast(&first1,&last1,10);

	
	InsertLast(&first2,&last2,10);
	InsertLast(&first2,&last2,20);
	InsertLast(&first2,&last2,30);
	InsertLast(&first2,&last2,40);
	InsertLast(&first2,&last2,20);
	InsertLast(&first2,&last2,10);
	
	
	printf("\n\n The first linked list is => ");
	Display(first1,last1);

	
	result=ListPallindrom(first1,last1);

	if(result)
	{
		printf("\n\n Linked list is pallindrom.");
	}
	else
	{
		printf("\n\n Linked list not pallindrom.");
	}
	
	
	printf("\n\n The second linked list is => ");
	Display(first2,last2);
	
	result=ListPallindrom(first2,last2);

	if(result)
	{
		printf("\n\n Linked list is pallindrom.");
	}
	else
	{
		printf("\n\n Linked list not pallindrom.");
	}


	getch();
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////
//
//		1st linked list	:	10 20 30 20 10 
//
//		Output			:	Linked list is pallindrom.
//
//		2nd linked list :   10 20 30 40 20 10
//
//		Output			:	Linked list not pallindrom.
//
////////////////////////////////////////////////////////////////////////////////////