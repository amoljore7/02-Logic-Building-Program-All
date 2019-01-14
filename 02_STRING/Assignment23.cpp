//////////////////////////////////////////////////////////////////////////////////////////////////
//
// 23.Write a program which accept string from user and then reverse the string till
// first N characters without taking another string.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<conio.h>

// Function prototype
char* MyStrNRev(char *,int);

int main()
{
	//Declaring array for string
	char cSource[30]={'\0'};
	int iNum = 0;

	// Accept string prom user
	printf("\nEnter String => ");
	scanf("%[^\n]",cSource);

	printf("\n Enter number => ");
	scanf("%d",&iNum);
	
	printf("\nReverse string is => %s\n",MyStrNRev(cSource,iNum));
	
	getch();
	return 0;
}

int StringLen(char *ptr)
{
	char *ptr1=ptr;

	while(*ptr!='\0')
	{
		ptr++;
	}

	return ptr-ptr1;
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:	MyStrNRev
//
//		Input			:	Address of String 
//
//		Returns			:	Address of reverse string
//
//		Description		:	Accept string and reverse the first N characters of string without using 
//							another string.
//
//////////////////////////////////////////////////////////////////////////////////////////////////

char* MyStrNRev(
				char *cPtr1,
				int iNo
			)
{
	// Creating local pointers
	char *cPtr2,*cPtr3;

	//this variable is use to hold temporary character
	char temp;

	if(cPtr1 == NULL || StringLen(cPtr1) < iNo)
	{
		printf("\n Wrong input.");
		return NULL;
	}
	//Assign cPtr pointer to *cPtr1 and *cPtr2
	cPtr2=cPtr1+(--iNo);
	cPtr3=cPtr1;

	while(cPtr1 <= cPtr2 )
	{
		temp = *cPtr2;
		*cPtr2 = *cPtr1;
		*cPtr1 = temp;

		cPtr1++;
		cPtr2--;
	
	}
	return cPtr3;
}

//////////////////////////////////////////////////////////
// 
//			Input		:		Prasad Rohan 6
// 
//			OutPut		:		dasarP Rohan
//
//////////////////////////////////////////////////////////