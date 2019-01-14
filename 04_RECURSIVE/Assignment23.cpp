//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// 23.Write a program which accept n numbers from user and print minimum
// number from that numbers in recursive manner.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

//Function Protptype
int PrintMin(int,int);

int main()
{
	int iCnt=0;
	int iNum=0;

	printf("Enter Number => ");
	scanf("%d",&iCnt);

	printf("\nEnter %d numbers => \n",iCnt);
	scanf("%d",&iNum);
	
	printf("\nMinimum Number Is => %d\n",PrintMin(iCnt,iNum));
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:		PrintMin
//
//		Input			:		Integer
//
//		Returns			:		Integer
//
//		Description		:		Accept N number and print Minimum number using recursion.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int PrintMin(int iCount,int iNum)
{
	static int iMini=iNum;
	int iNum1=0;
	if((iCount-1) > 0)
	{
		scanf("%d",&iNum1);
		if(iNum1 < iMini)
		{
			iMini=iNum1;
		}
		iCount--;
		PrintMin(iCount,iNum);
	}
	return iMini;
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//			Input		:	Enter Number of N => 7
//
//							Enter 7 Number =>
//							0
//							4
//							5
//							6
//							-1
//							4
//							8
//
//		Output			:	Minimum Number is => -1
//
////////////////////////////////////////////////////////////////////////////////////////////