//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// 24.Write a program which accept number from user and print the reverse
// number.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

//Function Protptype
void PrintReverseNum(long int);

int main()
{
	long int iNum=0;

	printf("\nEnter Number => ");
	scanf("%d",&iNum);
	
	printf("Reverse Number is => \n");
	
	// Function call
	PrintReverseNum(iNum);

	printf("\n");
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:	PrintReverseNum
//
//		Input			:	Integer
//
//		Returns			:	Integer
//
//		Description		:	This function accept number from user and print Reverse number using recursion.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PrintReverseNum(long int iNo)
{
	int iCnt=0;
	if(iNo > 0)
	{
		iCnt=iNo%10;
		iNo=iNo / 10;
		printf("%d",iCnt);
		PrintReverseNum(iNo);		
	}
}
/////////////////////////////////////////////////////////////////////////////////////////
//
//			Input		:	Enter Number => 10782922
//
//			output		:	Rerverse number is => 22928701							
//
////////////////////////////////////////////////////////////////////////////////////////////