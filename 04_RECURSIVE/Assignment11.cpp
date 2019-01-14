//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// 11.Write a program which accept range from user and print all perfect
// numbers in that range in recursive manner.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

//Function Protptype
void PrintPerfectInRange(int,int);

int main()
{
	//declaring integer
	int iNum1=0;
	int iNum2=0;

	printf("\nEnter starting range => ");
	scanf("%d",&iNum1);

	printf("\nEnter ending range => ");
	scanf("%d",&iNum2);

	printf("\nPerfect Numbers are => \n");
	
	// Function call
	PrintPerfectInRange(iNum1,iNum2);

	printf("\n");
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:	PrintPerfectInRange
//
//		Input			:	Integer , Integer
//
//		Returns			:	void
//
//		Description		:	This function accept number from user and print all perfect number in given range using recursion.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PrintPerfectInRange(int iNo1,int iNo2)
{
	int iSum=0;
	int iNum=1;
	if(iNo1 <= iNo2)
	{
		while(iNum <= (iNo1/2))
		{
			if((iNo1 % iNum) == 0)
			{
				
				iSum+= iNum;
				iNum++;
			}
			else
			{
				iNum++;
			}
		}
	
		if(iNo1 == iSum)
		{
			printf("%d\t",iSum);
		}
		iNo1++;
		PrintPerfectInRange(iNo1,iNo2);
	}
}
/////////////////////////////////////////////////////////////////////////////////////////
//
//			Input		:	Enter starting range => 1
//							Enter ending range	=>	20
//
//			output		:	Perfect Numbers are =>
//							6
//
////////////////////////////////////////////////////////////////////////////////////////////