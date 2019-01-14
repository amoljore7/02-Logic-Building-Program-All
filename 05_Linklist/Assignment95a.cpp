////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		95.Write a program which search second last occurrence of particular element from doubly circular 
//		linked list. Function should return position at which element is found. 
//		Function Prototype :  int SearchSecLastOcc(struct node *Head,struct node *Tail,int no ); 
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

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
//	Function Name			:	SearchLastOcc
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
 ///////////////////////////////////////////////////////////////////////////////////////////// 
 //
 //		Function Name   :	SearchSecLastOcc 
 //
 //		Parameters		:	1. struct Node *head => Holds head pointer of list.
 //							2. struct Node *tail => Holds last node address of list.
 //							3. int no			 => Holds data which is to be insert.
 //
 //		Description     :	This function seaches second last occ of data in the list and if found , 
 //							then return position.
 //
 //		Returns         :	int => position if function succeeds, otherowise return 0.
 //
 /////////////////////////////////////////////////////////////////////////////////////////////

 int SearchSecLastOcc(struct Node *head,struct Node *tail,int no)
 {
	int pos1=0;
	int pos2=0;
	int pos3=0;
	
	if(head == NULL)
	{
		return 0;
	}

	do
	{
		++pos1;
		if(head->data == no)
		{
			pos3=pos2;
			pos2=pos1;
		}
		head=head->next;
	}while(head!=tail->next);
	
	return pos3;
 }

 
 
 int main()
 {
	//create pointer which holds starting address of whole linked list.
	struct Node *first=NULL;
	struct Node *last=NULL;
	int pos=0;

	//call the function to add node at first position.
	InsertLast(&first,&last,10);
	InsertLast(&first,&last,20);
	InsertLast(&first,&last,30);
	InsertLast(&first,&last,40);
	InsertLast(&first,&last,50);
	InsertLast(&first,&last,60);
	InsertLast(&first,&last,70);
	InsertLast(&first,&last,40);
	InsertLast(&first,&last,30);
	InsertLast(&first,&last,80);

	
	printf("\n Linked list is => ");

	//call to DisplayList function to display linked list.
	Display(first,last);

	pos=SearchSecLastOcc(first,last,40);
	if(pos)
	{
		printf("\n\n The second last occ of an element is found at %d position in the linked list",pos);
	}
	else
	{
		printf("\n\n Second last occ or element is not found in the linked list.");
	}

    pos=SearchSecLastOcc(first,last,90);
	if(pos)
	{
		printf("\n\n The second last occ of an element is found at %d position in the linked list",pos);
	}
	else
	{
		printf("\n\n Second last occ or element is not found in the linked list.");
	}

	getch();
	return 0;
 }
 
 /////////////////////////////////////////////////////////////////////////////////////////////
 //
 //		Input Linked List :		10 20 30 40 50 60 70 40 30 80   no = 40
 //
 //		Output			  :	    The second last occ of an element is found at 4 position in the linked list
 //
 //		Input LinkedList  :		10 20 30 40 50 60 70 40 30 80   no = 90
 //
 //		Output			  :		Second last occ or element is not found in the linked list.
 //
 /////////////////////////////////////////////////////////////////////////////////////////////