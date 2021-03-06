//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// 20.Write a program which accept number from user and print 5 multiples of
// that number.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

//Function Protptype
void PrintFiveMultiples(int);

int main()
{
	int iNum=0;

	printf("\nEnter Number => ");
	scanf("%d",&iNum);

	printf("\nMultiples are => \n");
	
	// Function call
	PrintFiveMultiples(iNum);

	printf("\n");
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:	PrintFiveMultiples
//
//		Input			:	Integer
//
//		Returns			:	void
//
//		Description		:	This function accept number and print 5 multiples of that number using recursion.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PrintFiveMultiples(int iNo)
{
	static int iCnt=1;

	if(iCnt<=5)
	{
		printf("%d\t",iNo*iCnt);
		iCnt++;
		PrintFiveMultiples(iNo);
	}
}
/////////////////////////////////////////////////////////////////////////////////////////
//
//			Input		:	Enter Number => 6
//
//			output		:	Multiples are =>
//							6		12      18       24       30
//
////////////////////////////////////////////////////////////////////////////////////////////