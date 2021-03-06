//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		81.Write a program which copies contents of source doubly linear linked list whose addition of digits is 
//		prime number to destination doubly linear linked list. 
//		Function Prototype :  int LLCopyEx(struct node **Src  struct node **Dest); 
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
//////////////////////////////////////////////////////////////////////////////////////////////////// 
 //
 //		Function Name   :	LLCopyEx
 //
 //		Parameters		:	1. struct node **Src  => Holds pointer of source list.
 //							2. struct Node **Dest => Holds pointer of destination list.
 //
 //		Description     :	This function will copy those elements of source list into destination list,
 //							whose digits sum is prime number.
 //
 //		Returns         :	int => 1 if function succeeds, otherowise return 0.
 //
 /////////////////////////////////////////////////////////////////////////////////////////////////////

 int LLCopyEx(  struct Node *Src , struct Node **Dest )
 {
	struct Node *temp1=*Dest;
	struct Node *newnode=NULL;
	int count=0,num=0,div=2;
	
	//If source linked list is empty.
	if(Src == NULL )
	{
		return 0;
	}

	
	//Following loop is used to copy content from src list to dest list.
	while(Src!=NULL)
	{
		//Prime logic to check whether addition of digits is prime or not.
		num=Src->data;
		while(div!=num/2)
		{
			if(num % div ==0)
			{
				count++;
			}
			div++;
		}
		//if number is prime then add.
		if(count == 0)
		{
			//Allocate memory for node.
			newnode=(struct Node *)malloc(sizeof(struct Node));

			//check whether memory is allocated or not.
			if(newnode == NULL)
			{
				return 0;
			}

			//Assigning data
			newnode->next=newnode->prev=NULL;
			newnode->data=Src->data;

			//Add node in the linked list
			if(*Dest == NULL)
			{
				*Dest=temp1=newnode;
			}
			else
			{
				temp1->next=newnode;
				newnode->prev=temp1;
				temp1=newnode;
			}
	
		}
		//if number is not prime then go for next node.
		Src=Src->next;
		div=2;count=0;
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
	InsertFirst(&first,22);
	InsertFirst(&first,33);
	InsertFirst(&first,43);
	InsertFirst(&first,55);
	InsertFirst(&first,19);
	InsertFirst(&first,21);

	printf("\n\n The first linked list is => ");
	DisplayList(first);

	
	LLCopyEx(first,&second);
	printf("\n\n After copy the destination linked list is => ");
	DisplayList(second);


	getch();
	return 0;
 }
 
 /////////////////////////////////////////////////////////////////////////////////////////////
 //
 //		Dest linked list	:	empty
 //
 //		Source linked list	:	21 19 55 43 33 22 10
 //
 //		Output				:   19 43
 //
 /////////////////////////////////////////////////////////////////////////////////////////////