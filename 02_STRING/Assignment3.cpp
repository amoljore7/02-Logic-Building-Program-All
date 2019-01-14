////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		3.Write a program which accepts sentence from user and print number of small letters,
//		capital letters and digits from that sentence.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>


//MACRO definition
#define AND &&

//Function prototype
void CountLetters(char *);

int main()
{
	//create array to store string.
	char cString[20]={'\0'};

	//accept sting from user.
	printf("\n Enter the string => ");
	scanf("%[^\n]",&cString);
	
	//call function
	CountLetters(cString);

	return 0;
}
/////////////////////////////////////////////////////////////////////////////////
//
//			Function Name	:	CountLetters
//
//			Input			:	address of string
//
//			Returns			:	void
//
//			Description		:	This function accept string from user and print
//								the number of small letters,capital letters and
//								number of digits in the given string.
//
/////////////////////////////////////////////////////////////////////////////////

void CountLetters(
					char *cPtr
				 )
{
	//Local variable
	int iSmall=0;
	int iCapital=0;
	int iDigit=0;

	//while loop is used to count small,capital letters and digits.
	while(*cPtr!='\0')
	{
		if(*cPtr>=97 AND *cPtr<=122)
		{
			iSmall++;
		}
		if(*cPtr>=65 AND *cPtr<=90)
		{
			iCapital++;
		}
		if(*cPtr>=48 AND *cPtr<=57)
		{
			iDigit++;
		}
		*cPtr++;
	}
	printf("\n Small letters = => %d\n  Capital letters => %d\n  Digits => %d",iSmall,iCapital,iDigit);
}
/////////////////////////////////////////////////////////////////////////////////
//
//		Input		: abcDE 5Glm1 O
//
//		Output		: Small letters => 5
//					  Capital letters = => 4
//					  Digits => 2
//
/////////////////////////////////////////////////////////////////////////////////
