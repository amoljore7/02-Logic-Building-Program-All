////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//   70.Write a program which searches all occurrence of particular element from doubly linear linked list. 
//   Function should return number of occurance of that element.
//   Function Prototype : int SearchAll( struct node *Head,int no );
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
///////////////////////////////////////////////////////////////////////////////////////////// 
 //
 //		Function Name  :	SearchAll 
 //
 //		Parameters	   :	1.struct node *head => Holds head pointer of list. 
 //							2.int no => Number which we have to find in list. 
 //
 //		Description    :	This function will search all occ of element in the list.
 // 
 //		Returns		   :	number of occ of element in the list.
 // 
 ///////////////////////////////////////////////////////////////////////////////////////////// 

 int SearchAll(struct Node *head,int no)
 {
	int count=0;
	struct Node *temp=head;

	if(head == NULL)
	{
		return 0;
	}

	while(temp!=NULL)
	{
		if(temp->data == no)
		{
			count++;
		}
		temp=temp->next;
	}
	

	return count;
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

	//call the function to add node at first position.
	InsertFirst(&first,10);
	InsertFirst(&first,20);
	InsertFirst(&first,30);
	InsertFirst(&first,40);
	InsertFirst(&first,50);
	InsertFirst(&first,20);

	printf("\n\n The linked list is =>");
	DisplayList(first);

	printf("\n\n The element is found %d times in the linked list.",SearchAll(first,20));

	getch();
	return 0;
 }
 
 /////////////////////////////////////////////////////////////////////////////////////////////
 //
 //		Input	:	20 50 40 30 20 10
 //
 //		Output	:   The element is fount 2 times in the linked list.
 //
 /////////////////////////////////////////////////////////////////////////////////////////////