//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	91.Write a program which remove node from singly circular linked list which is at specified position. 
//	Function Prototype :  int DeleteAtPosition(  struct node **Head, struct node **Tail, int pos ); 
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

	if(head)
	{
		do
		{
			count++;
			head=head->next;
		}while(head!=tail->next);
	}
	else
	{
		return 0;
	}
	return count;
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteFirst
//
//	Description				:	This function delete first node of the Doubly Circular 
//								Linked List.
//
//	Prarmeters				:	1.struct Node **head -> starting address of list.
//								2.struct Node **tail -> ending address of list.
//
//	Returns					:	int -> 1 on success , otherwise return 0
//							
//
///////////////////////////////////////////////////////////////////////////////////////////
int DeleteFirst(struct Node **head , struct Node **tail)
{
	struct Node *temp=*head;

	//if linked list empty then return.
	if(*head == NULL)
	{
		return 0;
	}
	//if linked list contains only one node.
	else if( *head == *tail )
	{
		free(temp);
		*head=*tail=NULL;
	}

	//if list contains more than one node .
	else
	{
		*head=(*head)->next;
		(*tail)->next=*head;
		(*head)->prev=*tail;
		free(temp);
	}
	return 1;
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteLast
//
//	Description				:	This function delete last node of the Doubly Circular 
//								Linked List.
//
//	Prarmeters				:	1.struct Node **head -> starting address of list.
//								2.struct Node **tail -> ending address of list.
//
//	Returns					:	int -> 1 on success , otherwise return 0
//							
//
///////////////////////////////////////////////////////////////////////////////////////////
int DeleteLast(struct Node **head , struct Node **tail)
{
	struct Node *temp=NULL;

	//if linked list empty then return.
	if(*head == NULL)
	{
		return 0;
	}
	//if linked list contains only one node.
	else if( *head == *tail )
	{
		free(temp);
		*head=*tail=NULL;
	}

	//if list contains more than one node .
	else
	{
		temp=*tail;
		
		*tail=(*tail)->prev;
		(*tail)->next=temp->next;
		(*head)->prev=*tail;
		
		free(temp);
	}
	return 1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteAtPosition
//
//	Description				:	This function delete specific node of the Doubly Circular 
//								Linked List.
//
//	Prarmeters				:	1.struct Node **head -> starting address of list.
//								2.struct Node **tail -> ending address of list.
//								3.int pos -> pos to delete node.
//
//	Returns					:	int -> 1 on success , otherwise return 0
//							
//
///////////////////////////////////////////////////////////////////////////////////////////
int DeleteAtPosition(struct Node **head , struct Node **tail,int pos)
{
	struct Node *temp1=*head;
	struct Node *temp2=NULL;

	//if linked list empty then return.
	if(*head == NULL || pos < 1 || pos > Count(*head,*tail))
	{
		return 0;
	}
	
	if(pos == 1)
	{
		DeleteFirst(head,tail);
	}
	else if(pos == Count(*head,*tail))
	{
		DeleteLast(head,tail);
	}
	else
	{
		while(pos - 2 != 0 )
		{
			temp1=temp1->next;
			pos--;
		}
		temp2=temp1->next;

		temp1->next=temp2->next;
		temp2->next->prev=temp1;

		free(temp2);


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
	
	if(head)
	{
		do
		{
			printf("|%d| -> ",head -> data);
			head = head -> next;
		}while(head != tail->next);
	}
	else
	{
		printf("\n\n Linked list empty.");
	}
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

	DeleteAtPosition(&first,&last,4);
	//DeleteAtPosition(&first,&last,1);
	//DeleteAtPosition(&first,&last,3);

	//DeleteAtPosition(&first,&last,14);


	printf("\n\n After deleting node at first position , the list is => ");
	Display(first,last);

	getch();
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////
//
//		Linked list	:	10 20 30 40 50	
//
//
//		Output		:   10 20 30 50 
//
////////////////////////////////////////////////////////////////////////////////////