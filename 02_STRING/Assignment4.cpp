////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		4.Write a program which accepts sentence from user and print the length of that sentence.
//		(Implement strlen())
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>

//Function protype
int MyStrLen(char *);

int main()
{
	//create array to store string.
	char cString[20]={'\0'};

	//accept number from user.
	printf("\n Enter the string => ");
	scanf("%[^\n]",&cString);
	
	//call to function
	printf("\n The length of string is => %d",MyStrLen(cString));	
	
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////
//
//			Function Name		:	MyStrLen
//
//			Input				:	Address of string
//
//			Returns				:	integer
//
//			Description			:	This function accepts address of string and
//									returns the length of string.
//
/////////////////////////////////////////////////////////////////////////////////

int MyStrLen(
				char *cPtr1
			)
{
	//local variable
	char *cPtr=cPtr1;

	while(*cPtr1!='\0')
	{
		cPtr1++;
	}
	return cPtr1-cPtr; 
}

/////////////////////////////////////////////////////////////////////////////////
//
//		Input		: My Name Is Prasad.
//
//		Output		: The length of string is => 17.
//
/////////////////////////////////////////////////////////////////////////////////
