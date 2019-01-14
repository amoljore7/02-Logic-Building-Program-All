//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		9.Write a program which accept sentence from user and position from user 
//		and print the word at that position.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

#define AND &&

// Function prototyp
void PrintPosWord(char *,int);

int main()
{
	//create character array to store string.
	char cString[30]={'\0'};
	
	int iPos=0;

	//Accept string from user.
	printf("\nEnter string =>");
	scanf("%[^\n]",cString);

	// Accept position to print word
	printf("\nEnter Position =>");
	scanf("%d",&iPos);
	
	// Function call.
	PrintPosWord(cString,iPos);

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
//									and print specific word.
//
/////////////////////////////////////////////////////////////////////////////////////////

void PrintPosWord(char *cPtr,int Pos)
{
	int iCount=1;

	// character pointer is empty
	if(*cPtr == NULL)
	{
		return;
	}

	while( *cPtr != '\0' )
	{
		if(*cPtr == 32)
		{
			iCount++;
		}
		else if(iCount == Pos)
		{
			while(*cPtr != 32 && *cPtr != '\0')
			{
				printf("%c",*cPtr);
				cPtr++;
			}
			break;

		}
		cPtr++;
	}

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Input		: is my he she 3 
//
//		Output		: he
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////