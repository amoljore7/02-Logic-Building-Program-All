//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// 10.Write a program which accept range from user and print all prime
// numbers in that range in recursive manner.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

//Function Protptype
void PrintPrimeInRange(int,int);

int main()
{
	//declaring integer
	int iNum1=0;
	int iNum2=0;

	printf("\nEnter starting range => ");
	scanf("%d",&iNum1);

	
	printf("\nEnter ending range => ");
	scanf("%d",&iNum2);

	printf("\nPrime Numbers are => \n");
	
	// Function call
	PrintPrimeInRange(iNum1,iNum2);

	printf("\n");
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:	PrintPrimeInRange
//
//		Input			:	Integer , Integer
//
//		Returns			:	void
//
//		Description		:	This function accept number from user and print all prime number in that range using recursion.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PrintPrimeInRange(int iNo1,int iNo2)
{
	int iNum=2,iPrime=0;
	if(iNo1 <= iNo2)
	{
		while(iNum < iNo1)
		{
			if((iNo1 % iNum) != 0)
			{
				iNum++;
				iPrime = iNum;
			}
			else
			{
				iNum=0;
				iPrime=0;
				break;
			}
		}
		iNo1++;
		if(iPrime != 0)
		{
			printf("%d\t",iPrime);
		}
		PrintPrimeInRange(iNo1,iNo2);
	}
}
/////////////////////////////////////////////////////////////////////////////////////////
//
//			Input		:	Enter starting range => 10
//							Enter ending range => 20
//
//			output		:	Prime Numbers are =>
//							11 13 17 19
//
////////////////////////////////////////////////////////////////////////////////////////////