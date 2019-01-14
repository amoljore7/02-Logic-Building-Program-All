///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// 25.Write a program which accept string from user and then accept range and reverse the string in that 
//	range without taking another string.  
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<conio.h>

// Function prototype
char* MyStrRevRange(char *,int,int);
int StringLen(char*);

int main()
{
	//Declaring array for string
	char cSource[30]={'\0'};

	int iStart = 0;
	int iEnd = 0;

	// Accept string prom user
	printf("\nEnter String => ");
	scanf("%[^\n]",cSource);
	
	
	
	printf("\n Enter starting range => ");
	scanf("%d",&iStart);

	printf("\n Enter ending range");
	scanf("%d",&iEnd);

	printf("\nReverse string is => %s\n",MyStrRevRange(cSource,iStart,iEnd));

	getch();
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:	MyStrRevRange
//
//		Input			:	Address of String 
//
//		Return			:	Address of reverse string
//
//		Description		:	This function accept string and range , and reverse the string in given range without using another string.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

char* MyStrRevRange(
				char *cPtr1,
				int iStart,
				int iEnd
			)
{
	// Creating local pointer 
	char *cPtr2,*cPtr3;

	//this variable is use to hold temporary character
	char temp;

	if(cPtr1 == NULL || StringLen(cPtr1) < iStart || StringLen(cPtr1) < iEnd || iStart > iEnd)
	{
		printf("\n Wrong input.");
		return NULL;
	}

	//Assign pointer
	cPtr3=cPtr1;

	cPtr2=cPtr1+(iEnd-1);
	
	cPtr1=cPtr1+(iStart-1); 
	

	while(cPtr1 <= cPtr2)
	{
		temp = *cPtr2;
		*cPtr2 = *cPtr1;
		*cPtr1 = temp;

		cPtr1++;
		cPtr2--;
	}
	return cPtr3;
}


int StringLen(char *cStr)
{
	int iCount = 0;

	if(*cStr == NULL)
	{
		return iCount;
	}
	
	while(*cStr != '\0')
	{
		iCount++;
		cStr++;
	}
	return iCount;
}


///////////////////////////////////////////////////////////
//
//		Input		:		Prasad Rohan 5
// 
//		OutPut		:		Prasad nahoR
//
////////////////////////////////////////////////////////////