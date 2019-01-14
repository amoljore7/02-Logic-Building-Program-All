//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// 5. Write a program which accept n numbers from user and return addition of
// that numbers in recursive manner. Value of n is accepted from user.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

// Function Protptype
int AdditionOfNNum(int);

int main()
{
	int iNum=0;
	int iRes=0;
	printf("\nEnter Number => ");
	scanf("%d",&iNum);
	
	printf("\nNumbers are => \n");
	//Fuction Call
	iRes=AdditionOfNNum(iNum);

	printf("Addition of %d number is => %d\n",iNum,iRes);
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:		AdditionOfNNum
//
//		parameter		:		Integer
//
//		Return			:		Integer
//
//		Description		:		This fuction returns Addition of N number by using recursion.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int AdditionOfNNum(int iNo)
{
	static int iSum=0;
	int iNum=0;
	if(iNo > 0)
	{
		scanf("%d",&iNum);
		iSum+=iNum;
		iNo--;
		AdditionOfNNum(iNo);
	}
	return iSum;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Input	:	Enter Number => 5
//
//					Numbers are =>
//					10
//					5
//					34
//					6
//					15
//		Output	:	Addition of 5 number is => 70
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////