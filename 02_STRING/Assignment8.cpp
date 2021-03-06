//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	8.Write a program which accept sentence from user and print last word from that sentence.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

// Function prototyp
void PrintLastWord(char *);

int main()
{
	//create character array to store string.
	char cString[50]={'\0'};

	//Accept string from user.
	printf("\nEnter String => ");
	scanf("%[^\n]",cString);
	
	// Function call.
	PrintLastWord(cString);

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////
//
//			Function Name		:	PrintLastWord
//
//			Input				:	Address of string
//
//			Returns				:	void
//
//			Description			:	This function accepts address of string
//									and print last word.
//
/////////////////////////////////////////////////////////////////////////////////////////

void PrintLastWord(char *cPtr)
{
	char *cPtr1=cPtr;

	// if string is empty 
	if(*cPtr == NULL)
	{
		return;
	}

	while(*cPtr != '\0')
	{
		if(*cPtr == 32)
		{
			cPtr1=cPtr;
		}
		cPtr++;
	}

	printf("\n Last word from string is => ");
	while(*cPtr1!= '\0' )
	{
		printf("%c",*cPtr1);
		cPtr1++;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Input		: In my company 
//
//		Output		: company
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////