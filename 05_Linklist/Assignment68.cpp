//////////////////////////////////////////////////////////////////////////////////////////////
// 
//	68.Write a program which search last occurrence of particular element from doubly linear 
//	linked list.
//	Function should return position at which element is found. 
//	Function Prototype :  int SearchLastOcc( struct node *Head  int no )
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
 ///////////////////////////////////////////////////////////////////////////////////////////// 
 //
 //		Function Name  :	SearchLastOcc 
 //
 //		Parameters	   :	1.struct Node *head => Holds head pointer of list. 
 //							2.int no => element to find first occ. 
 //
 //		Description    :	This function search last occ of an element in list and if found
 //							return the position at which occ is fount. 
 // 
 //		Returns		   :	position if success otherwise return 0
 // 
 ///////////////////////////////////////////////////////////////////////////////////////////// 

 int SearchLastOcc(struct Node *head , int no)
 {
	int pos1=0;
	int pos2=0;
	int pos3=0;
	
	while(head)
	{
		++pos1;
		if(head->data == no)
		{
			pos3=pos2;
			pos2=pos1;
		}
		head=head->next;
	}
	return pos3;
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
	int result=0;

	InsertLast(&first,&last,10);
	InsertLast(&first,&last,20);
	InsertLast(&first,&last,30);
	InsertLast(&first,&last,40);
	InsertLast(&first,&last,50);
	InsertLast(&first,&last,40);
	InsertLast(&first,&last,60);
	InsertLast(&first,&last,70);
 
	printf("\n\n The linked list is => ");
	DisplayList(first);

	result=SearchLastOcc(first,40);

	if(result)
	{
		printf("\n\n The second last occ of an element is found at %d position",result);
	}
	else
	{
		printf("\n\n The second last occ or element is not found in the linked list.");
	}

	getch();
	return 0;
 }

 ///////////////////////////////////////////////////////////////////////
 //
 //		Input	:	10 20 30 40 50 40 60 70
 //
 //		int no	:	40
 //	
 //		Output	:	The last occ of an element is found at 6 position.
 //
 ////////////////////////////////////////////////////////////////////////