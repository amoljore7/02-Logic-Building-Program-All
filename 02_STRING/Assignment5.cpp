////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		5.Write a program which accepts sentence from user and print number of white spaces from
//		that sentence.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>

//Function protype
int PrintWhiteSpace(char *);

int main()
{
	//create array to store string.
	char cString[20]={'\0'};

	//accept string from user.
	printf("\n Enter the string => ");
	scanf("%[^\n]",&cString);
	
	//call to function
	printf("\n The number of white spaces in the string are => %d",PrintWhiteSpace(cString));	
	
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////
//
//			Function Name		:	PrintWhiteSpace
//
//			Input				:	Address of string
//
//			Returns				:	integer
//
//			Description			:	This function accepts address of string and
//									print number of white spaces from string.
//
/////////////////////////////////////////////////////////////////////////////////

int PrintWhiteSpace(
						char *cPtr
					)
{
	//local variable
	int iCount=0;

	while(*cPtr!='\0')
	{
		if(*cPtr==32)
		{
			iCount++;
		}
		cPtr++;
	}
	return iCount; 
}

/////////////////////////////////////////////////////////////////////////////////
//
//		Input		: My Name Is Prasad.
//
//		Output		: The number of white spaces in the string is => 3.
//
/////////////////////////////////////////////////////////////////////////////////
