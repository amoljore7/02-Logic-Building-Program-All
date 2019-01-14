//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	97.Write a program which accept two doubly circular linked list from user and concat source linked 
//	list after destination linked list. 
//	Function Prototype :  int ConcatList(struct node **SrcHead,struct node **SrcTail,struct node **DestHead,struct node **DestTail); 
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
///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	ConcatList
//
//	Description				:	This function concats two doubly circular linked list.
//
//	Prarmeters				:	1.struct Node **Srchead -> starting address of 1st list.
//								2.struct Node **Srctail -> ending address of 1st list.
//								3.struct Node **Desthead-> starting address of 2nd list.
//								4.struct Node **Desttail-> ending address of 2nd list.
//
//	Returns					:	int -> 1 on success , otherwise return 0
//							
//
///////////////////////////////////////////////////////////////////////////////////////////

int ConcatList(struct Node **Srchead,struct Node **Srctail,struct Node **Desthead,struct Node **Desttail)
{

	if(*Srchead == NULL || *Desthead ==  NULL)
	{
		return 0;
	}

	
	//assign starting address of 2nd list to the tail pointer of first linked list,and
	//assign ending address of the 1st list to the first pointer of 2nd linked list.
	(*Srctail)->next=*Desthead;
	(*Desthead)->prev=*Srctail;

	//assign starting address of 1st linked list to tail pointer of 2nd linked list,and
	//assign ending address of 2nd linked list to starting pointer of 1st linked list.
	(*Desttail)->next=*Srchead;
	(*Srchead)->prev=*Desttail;

	//following assignment is very imp for traversing list after concat operation.
	*Srctail=*Desttail;

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

	InsertLast(&first1,&last1,10);
	InsertLast(&first1,&last1,20);
	InsertLast(&first1,&last1,30);
	InsertLast(&first1,&last1,40);
	InsertLast(&first1,&last1,50);
	
	
	InsertLast(&first2,&last2,60);
	InsertLast(&first2,&last2,70);
	InsertLast(&first2,&last2,80);
	InsertLast(&first2,&last2,90);

	printf("\n\n The first linked list is => ");
	Display(first1,last1);

	printf("\n\n The second linked list is => ");
	Display(first2,last2);

	ConcatList(&first1,&last1,&first2,&last2);

	printf("\n\n After concatination linked list is =>");
	Display(first1,last1);

	getch();
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////
//
//		1st linked list	:	10 20 30 40 50 
//
//		2nd linked list	:	60 70 80 90
//
//		Output			:	10 20 30 40 50 60 70 80 90
//
////////////////////////////////////////////////////////////////////////////////////