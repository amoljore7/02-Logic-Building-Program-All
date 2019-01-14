//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		82.Write a program which accept source doubly linear linked list and destination doubly linear linked list
//		and check whether source list is sub list of destination list. Function returns first position at which sub list found. 
//		Function Prototype :  int SubList(struct node *Src  , struct node *Dest);  
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
 //		Function Name   :	SubList
 //
 //		Parameters		:	1. struct node *Src  => Holds pointer of source list.
 //							2. struct Node *Dest => Holds pointer of destination list.
 //
 //		Description     :	This function will check whether source list is sub list of dest list
 //							or not. If yes then it return position of sublist.
 //
 //		Returns         :	int => position of sublist if function succeeds, otherowise return 0.
 //
 /////////////////////////////////////////////////////////////////////////////////////////////////////

 int SubList(  struct Node *Dest , struct Node *Src )
 {
	struct Node *temp1=Dest;
	struct Node *temp2=Src;
	int pos=1;
	
	//If source linked list is empty.
	if(Src == NULL || Dest == NULL)
	{
		return 0;
	}

	while(temp1!=NULL  && temp2!=NULL)
	{
		if(temp1->data == temp2->data)
		{
			temp2=temp2->next;
			temp1=temp1->next;
		}
		else if(temp2 == Src)
		{
			pos++;
			temp1=temp1->next;
		}
		else
		{
			pos++;
			temp2=Src;
		}
	}
	if(temp2 == NULL)
	{
		return pos;
	}
	else
	{
		return 0;
	}
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
	int pos=0;

	//call the function to add node at first position.
	InsertFirst(&first,10);
	InsertFirst(&first,22);
	InsertFirst(&first,33);
	InsertFirst(&first,43);
	InsertFirst(&first,55);
	InsertFirst(&first,19);
	InsertFirst(&first,21);

	printf("\n\n The destination linked list is => ");
	DisplayList(first);

	InsertFirst(&second,33);
	InsertFirst(&second,43);
	InsertFirst(&second,55);
	InsertFirst(&second,19);
	
	printf("\n\n The source linked list is => ");
	DisplayList(second);


	pos=SubList(first,second);

	if(pos)
	{
		printf("\n\n The first sublist is found at %d position.",pos);
	}
	else
	{
		printf("\n\n Sublist not found.");
	}


	getch();
	return 0;
 }
 
 /////////////////////////////////////////////////////////////////////////////////////////////
 //
 //		source linked list	:	19 55 43 33
 //
 //		dest linked list	:	21 19 55 43 33 22 10
 //
 //		Output				:   The first sublist is found at 2 position..
 //
 /////////////////////////////////////////////////////////////////////////////////////////////