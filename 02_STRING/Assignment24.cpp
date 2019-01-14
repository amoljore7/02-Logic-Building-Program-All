///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// 24.Write a program which accept string from user and then reverse the string till
// last N characters without taking another string.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<conio.h>

// Function prototype
char* MyLastNRev(char *,int);
int StringLen(char*);

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

	printf("\nReverse string is => %s\n",MyLastNRev(cSource,iNum));

	getch();
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:	MyLastNRev
//
//		Input			:	Address of String 
//
//		Return			:	Address of reverse string
//
//		Description		:	This function accept string and reverse last N character without using another string.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

char* MyLastNRev(
				char *cPtr1,
				int iNo
			)
{
	// Creating local pointer 
	char *cPtr2,*cPtr3;

	//this variable is use to hold temporary character
	char temp;

	if(cPtr1 == NULL || StringLen(cPtr1) < iNo)
	{
		printf("\n Wrong input.");
		return NULL;
	}

	//Assign pointer
	cPtr3=cPtr1;
	cPtr2=cPtr1+(StringLen(cPtr1)-1);//end of the string
	cPtr1=cPtr2-(--iNo);//desired location 
	

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