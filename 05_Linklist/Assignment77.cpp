//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		77.Write a program which copies last N contents of doubly linear source linked list to destination doubly 
//		linear linked list. 
//		Function Prototype :   int LLINCopy(struct node **Src  struct node **Dest int no); 
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
 //		Function name	:	LLINCopy
 //
 //		Parameters		:	1. struct Node **Dest -> Address of destination linked list.
 //							2. struct Node **Src  -> Address of source linked list.
 //							3. int no -> number of element want to copy.
 //
 //		Description		:	This function copies last N elements of source linked 
 //							list into dest list. 
 //							
 //		Returns			:	int -> 1 on success , otherwise return 0
 //
 //////////////////////////////////////////////////////////////////////////////////////

 int LLINCopy(struct Node **Src,struct Node **Dest,int no)
 {
	struct Node *temp1=*Src;
	struct Node *temp2=*Src;
	struct Node *temp3=*Dest;

	struct Node *newnode=NULL;

	if(*Src == NULL)
	{
		return 0;
	}

	while(no > 0 && temp1!=NULL)
	{
		temp1=temp1->next;
		no--;
	}

	while(temp1!=NULL)
	{
		temp1=temp1->next;
		temp2=temp2->next;
	}

	while(temp2!=NULL)
	{
		newnode=(struct Node *)malloc(sizeof(struct Node));

		if(newnode == NULL)
		{
			return 0;
		}

		newnode->next=newnode->prev=NULL;
		newnode->data=temp2->data;

		if(*Dest == NULL)
		{
			*Dest=temp3=newnode;
		}
		else
		{
			temp3->next=newnode;
			newnode->prev=temp3;
			temp3=newnode;
		}
		temp2=temp2->next;
		no--;
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

	printf("\n\n The first linked list is => ");
	DisplayList(first);

	
	LLINCopy(&first,&second,4);
	printf("\n\n After copy the destination linked list is => ");
	DisplayList(second);


	getch();
	return 0;
 }
 
 /////////////////////////////////////////////////////////////////////////////////////////////
 //
 //		Dest linked list	:	empty
 //
 //		Source linked list	:	20 50 40 30 20 10
 //
 //		Output				:   40 30 20 10
 //
 /////////////////////////////////////////////////////////////////////////////////////////////