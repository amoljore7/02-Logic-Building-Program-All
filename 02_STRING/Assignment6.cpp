////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		6.Write a program which accepts sentence from user and print number of words from
//		that sentence.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>

//Function protype
int PrintNumOfWords(char *);

int main()
{
	//create array to store string.
	char cString[30]={'\0'};

	//accept string from user.
	printf("\n Enter the string => ");
	scanf("%[^\n]",&cString);
	
	//call to function
	printf("\n The number of words in the string is => %d",PrintNumOfWords(cString));	
	
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////
//
//			Function Name		:	PrintNumOfWords
//
//			Input				:	Address of string
//
//			Returns				:	integer
//
//			Description			:	This function accepts address of string and
//									print number of words from string.
//
/////////////////////////////////////////////////////////////////////////////////

int PrintNumOfWords(
						char *cPtr
					)
{
	//local variable
	int iCount=0;

	while(*cPtr!='\0')
	{
		if(*cPtr == 32)
		{
			iCount++;
		}
	}
	return iCount+1; 
}

/////////////////////////////////////////////////////////////////////////////////
//
//		Input		: My Name Is Prasad.
//
//		Output		: The number of words in the string is => 4.
//
/////////////////////////////////////////////////////////////////////////////////
