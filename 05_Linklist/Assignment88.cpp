///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	88.Write a program which add new node in singly circular linked list at specified position. 
//	Function Prototype :  int InsertAtPosition( struct node **Head, struct node **Tail,  int no, int pos ); 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

int Count(struct Node *head,struct Node *tail)
{
	int count=0;

	do
	{
		count++;
		head=head->next;
	}while(head!=tail->next);

	return count;
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertAtPosition
//
//	Description				:	This function adds node to Doubly Circular Linked List,
//								at specific position.
//
//	Prarmeters				:	1.struct Node **head -> starting address of list.
//								2.struct Node **tail -> ending address of list.
//								3.int no	->	element to insert.
//								4.int pos   -> pos at which node will be insert.
//
//	Returns					:	int -> 1 on success , otherwise return 0
//							
//
///////////////////////////////////////////////////////////////////////////////////////////

int InsertAtPosition(
						struct Node **head,
						struct Node **tail,
						int no,
						int pos
					)
{
	struct Node *newnode=NULL;
	struct Node *temp=*head;

	if(*head == NULL || pos < 1 || pos > Count(*head,*tail)+1)
	{
		return 0;
	}

	//allocate memory for newnode
	newnode=(struct Node *)malloc(sizeof(struct Node));

	if(newnode == NULL)
	{
		return 0;
	}

	//fill newnode with data.
	newnode->data=no;
	newnode->next=newnode->prev=NULL;

	if(pos == 1)
	{
		newnode->next=*head;
		(*head)->prev=newnode;
		*head=newnode;
		(*tail)->next=*head;
		(*head)->prev=*tail;
	}
	else
	{
		while(pos - 2 != 0)
		{
			temp=temp->next;
			pos--;
		}

		newnode->next=temp->next;
		temp->next->prev=newnode;
		temp->next=newnode;
		newnode->prev=temp;

		//if condition is used to check whether node is insert at last pos or not,if node is 
		//insert at last position then we have to modify our tail pointer.
		//if node is insert at last position and if we are not modify tail pointer then problem is
		//that our node gets added in list but when we tries to traverse the list at that time this newly added to is not accessible.
		if(newnode->next == *head)
		{
			*tail=newnode;
		}
	}

	
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
	struct Node *first=NULL;
	struct Node *last=NULL;

	InsertLast(&first,&last,10);
	InsertLast(&first,&last,20);
	InsertLast(&first,&last,30);
	InsertLast(&first,&last,40);
	InsertLast(&first,&last,50);

	printf("\n\n The linked list is => ");
	Display(first,last);

	InsertAtPosition(&first,&last,35,4); //this node will add at 4th position.
	InsertAtPosition(&first,&last,5,1);  //this node will add at first position.
	InsertAtPosition(&first,&last,60,8); //this node will add at last position.

	InsertAtPosition(&first,&last,70,15);//this node will not add in our list because of wrong position.

	printf("\n\n After adding node at last position , the list is => ");
	Display(first,last);

	getch();
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////
//
//		Linked list	:	10 20 30 40 50	
//
//		Input		:	no(pos) => 1 -> 35(4) , 2 -> 5(1) , 3 -> 60(8) , 4 -> 70(15) 
//
//		Output		:   5 10 20 30 35 40 50 60
//
////////////////////////////////////////////////////////////////////////////////////