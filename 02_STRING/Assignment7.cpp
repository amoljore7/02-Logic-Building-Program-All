//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	 7.Write a program which accept sentence from user and print number of words
//   of even and odd length from that sentence.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

//Function Prototype
void CountEvenOdd(char *);

int main()
{
	//create character array to store string.
	char cString[50]={'\0'};

	//Accept String from user.
	printf("\n Enter string => ");
	scanf("%[^\n]",cString);

	// Function call
	CountEvenOdd(cString);
	
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//			Function Name		:	CountEvenOdd
//
//			Input				:	Address of string
//
//			Returns				:	Nothing
//
//			Description			:	This function accepts address of string and
//									count number of even words and odd words from string.
//
/////////////////////////////////////////////////////////////////////////////////

void CountEvenOdd(
					char *cPtr
				)
{
	//Create local variables for counting Even and odd words.

	int iCount=0,iECount=0,iOCount=0;

	while(*cPtr != '\0')
	{
		while(*cPtr != ' ' && *cPtr != '\0')
		{
			iCount++;
			cPtr++;
		}

		if((iCount % 2) == 0)
		{
			iECount++;
			iCount = 0;
		}
		
		if((iCount % 2) != 0)
		{
			iOCount++;
			iCount = 0;
		}
		cPtr++;
	}
	printf(" \n Even length words are => %d\n Odd length words are => %d",iECount,iOCount);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	
//		Input		 : In my company 
//
//		Output		 : Even length words are => 2 
//					   Odd length words are => 1
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////