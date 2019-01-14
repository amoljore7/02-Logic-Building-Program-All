//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		74.Write a program which accepts two doubly linear linked list from user and also accept range 
//		and concat elements of source singly linear linked list from that range after doubly linear destination linked list. 
//		Function Prototype :  int ConcatListRange(  struct node **Src  struct node **Dest, int start , int end); 
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int data;	//holds data of the node.
	Node *next; //holds address of next node in the linked list.
	Node *prev; //holds address of previous node in the linked list.
};


 //////////////////////////////////////////////////////////////////////////////////////////// 
 //
 //		Function Name   :	InsertFirst 
 //
 //		Parameters		:	1. struct node **head => Holds head pointer of list.
 //							2. int no			  => Holds data which is to be insert.
 //
 //		Description     :	This function inserts node at first position in doubly linked list.  
 //
 //		Returns         :	int => 1 if function succeeds, otherowise return 0.
 //
 /////////////////////////////////////////////////////////////////////////////////////////////

 int InsertFirst( struct Node **head,  int no )
 {
	struct Node *newnode=NULL;

	//allocate memory for node
	newnode=(struct Node *)malloc(sizeof(struct Node));

	//check whether memory is allocated or not.
	if(newnode == NULL)
	{
		return -1;
	}

	//fill node with the data.
	newnode->next=newnode->prev=NULL;
	newnode->data=no;

	//Add node at first position.

	//If list is empty.
	if(*head == NULL)
	{
		*head=newnode;
	}

	//if linked list contains at least one node.
	else
	{
		newnode->next=*head;
		(*head)->prev=newnode;
		*head=newnode;
	}
 }
 //////////////////////////////////////////////////////////////////////////////////////
 //
 //		Function name	:	ConcatListRange
 //
 //		Parameters		:	1. struct Node **Dest -> Address of destination linked list.
 //							2. struct Node **Src  -> Address of source linked list.
 //							3. int start -> starting of range.
 //							4. int end	 -> ending of range. 
 //
 //		Description		:	This function concats the elements of source linked 
 //							list after destination linked list in given range.
 //
 //		Returns			:	int -> 1 on success , otherwise return 0
 //
 //////////////////////////////////////////////////////////////////////////////////////

 int ConcatListRange(struct Node **Dest,struct Node **Src,int start,int end)
 {
	struct Node *temp1=*Dest;
	struct Node *temp2=*Src;

	struct Node *newnode=NULL;

	if(*Dest == NULL || *Src == NULL)
	{
		return 0;
	}

	//following while loop is used to reach at the end of dest linked list.
	while(temp1->next!=NULL)
	{
		temp1=temp1->next;
	}

	while(start-1 > 0 && temp2!=NULL)
	{
		temp2=temp2->next;
		start--;
		end--;
	}

	//following while loop is used to concat N element after dest linked list.
	while(end > 0 && temp2!=NULL )
	{
		newnode=(struct Node *)malloc(sizeof(struct Node));

		if(newnode == NULL)
		{
			return 0;
		}

		//fill the newnode with data.
		newnode->next=newnode->prev=NULL;
		newnode->data=temp2->data;

		//add newnode at the end of dest linked list.
		temp1->next=newnode;
		newnode->prev=temp1;

		temp1=temp1->next;
		temp2=temp2->next;
		end--;
	}

	return 1;
 }
 ///////////////////////////////////////////////////////////////////////////////////////////// 
 //
 //		Function Name  :	DisplayList 
 //
 //		Parameters	   :	1.struct node *first => Holds head pointer of list. 
 // 
 //		Description    :	This function displays linked list. 
 // 
 //		Returns		   :	void 
 // 
 ///////////////////////////////////////////////////////////////////////////////////////////// 
 
 void DisplayList(struct Node *head)
 {
	if(head)
	{
		while(head)
		{
			printf("|%d|->",head->data);
			head=head->next;
		}
	}
	else
	{
		printf("\n Linked list is empty.");
	}
 }
 
 
 int main()
 {
	//create pointer which holds starting address of whole linked list.
	struct Node *first=NULL;
	struct Node *second=NULL;

	//call the function to add node at first position.
	InsertFirst(&first,10);
	InsertFirst(&first,20);
	InsertFirst(&first,30);
	InsertFirst(&first,40);
	InsertFirst(&first,50);
	InsertFirst(&first,20);

	InsertFirst(&second,100);
	InsertFirst(&second,200);
	InsertFirst(&second,300);
	InsertFirst(&second,400);
	InsertFirst(&second,500);

	printf("\n\n The first linked list is => ");
	DisplayList(first);

	printf("\n\n The second linked list is => ");
	DisplayList(second);

	ConcatListRange(&first,&second,2,4);
	printf("\n\n After concatination  the linked list is => ");
	DisplayList(first);


	getch();
	return 0;
 }
 
 /////////////////////////////////////////////////////////////////////////////////////////////
 //
 //		Dest linked list	:	20 50 40 30 20 10
 //
 //		Source linked list	:	500 400 300 200 100
 //
 //		start range			:	2		,	ending range	:	4
 //
 //		Output				:   20 50 40 30 20 10  400 300 200
 //
 /////////////////////////////////////////////////////////////////////////////////////////////