//////////////////////////////////////////////////////////////////////////////////////////////
// 
//	85.Write a program which accept source doubly linear linked list from user and copy the 
//	contents into destination doubly linear linked in descending order. 
//	Function Prototype :  int CopyDec(struct node **Src  struct node **Dest); 
//
//////////////////////////////////////////////////////////////////////////////////////////////

#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int data;	//holds data of the node.
	Node *next; //holds address of next node in the linked list.
	Node *prev; //holds address of previous node in the linked list.
};


 //////////////////////////////////////////////////////////////////////////////////////////////////// 
 //
 //		Function Name   :	InsertLast 
 //
 //		Parameters		:	1. struct Node **head => Holds head pointer of list.
 //							2. struct Node **tail => Holds last pointer of list
 //							2. int no			  => Holds data which is to be insert.
 //
 //		Description     :	This function inserts node at last position in doubly linked list.  
 //
 //		Returns         :	int => 1 if function succeeds, otherowise return 0.
 //
 /////////////////////////////////////////////////////////////////////////////////////////////////////

 int InsertLast( struct Node **head , struct Node **tail ,  int no )
 {
	struct Node *newnode=NULL;
	
	//allocate memory for node
	newnode=(struct Node *)malloc(sizeof(struct Node));

	//check whether memory is allocated or not.
	if(newnode == NULL)
	{
		return 0;
	}

	//fill node with the data.
	newnode->next=newnode->prev=NULL;
	newnode->data=no;

	//Add node at first position.

	//If list is empty.
	if(*head == NULL)
	{
		*head=*tail=newnode;
	}

	//if linked list contains at least one node.
	else
	{
		(*tail)->next=newnode;
		newnode->prev=*tail;
		*tail=newnode;
	}
	return 1;
 }

 //////////////////////////////////////////////////////////////////////////////////////////////////// 
 //
 //		Function Name   :	CopyDec
 //
 //		Parameters		:	1. struct node *Src  => Holds pointer of source list.
 //							2. struct Node **Dest => Holds pointer of destination list.
 //
 //		Description     :	This function will copy content of source list into the destination
 //							list in descending order.
 //
 //		Returns         :	int => 1 if function succeeds, otherowise return 0.
 //
 /////////////////////////////////////////////////////////////////////////////////////////////////////

 int CopyDec(struct Node *Src,struct Node **Dest)
 {
	struct Node *newnode=NULL;
	struct Node *temp1=NULL;
	struct Node *temp2=NULL;

	if(Src == NULL)
	{
		return 0;
	}
	while(Src!=NULL)
	{
		newnode=(struct Node *)malloc(sizeof(struct Node));

		if(newnode == NULL)
		{
			return 0;
		}

		newnode->data=Src->data;
		newnode->next=newnode->prev=NULL;

		if(*Dest == NULL)
		{
			*Dest=newnode;
		}
		else if(newnode->data > (*Dest)->data)
		{
			newnode->next=*Dest;
			(*Dest)->prev=newnode;
			*Dest=newnode;
		}
		else if(newnode->data < (*Dest)->data)
		{	
			temp1=*Dest;
			while( temp1!=NULL && temp1->data > newnode->data  )
			{
				temp2=temp1;
				temp1=temp1->next;
			}
			
			if(temp1 == NULL)
			{
				temp2->next=newnode;
				newnode->prev=temp2;
			}
			else
			{
				newnode->next=temp1;
				temp1->prev=newnode;
				temp2->next=newnode;
				newnode->prev=temp2;
			}
		}
		Src=Src->next;
	}
	return 1;
 }
 ///////////////////////////////////////////////////////////////////////////////////////////// 
 //
 //		Function Name  :	DisplayList 
 //
 //		Parameters	   :	1.struct node *head => Holds head pointer of list. 
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
	 struct Node *first=NULL;
	 struct Node *last=NULL;

	 struct Node *second=NULL;

	InsertLast(&first,&last,20);
	InsertLast(&first,&last,10);
	InsertLast(&first,&last,40);
	InsertLast(&first,&last,30);
	InsertLast(&first,&last,60);
	InsertLast(&first,&last,50);
 
	printf("\n\n The source linked list is => ");
	DisplayList(first);

	CopyDec(first,&second);

	printf("\n\n The destination linked list is => ");
	DisplayList(second);

	getch();
	return 0;
 }

 ///////////////////////////////////////////////////////////////////////
 //
 //		Input	:	20 10 40 30 60 50
 //
 //		Output	:	60 50 40 30 20 10
 //
 ////////////////////////////////////////////////////////////////////////