//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// 14.Write a program which accepts number from user and check whether
//	number is Armstrong number or not in recursive manner.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

//Function Protptype
int CheckArmstrong(long int);
int countDigit(int);
long int Pow(int,int);

int main()
{
	//declaring integer
	long int iNum=0;
	long int iTemp=0;

	printf("\nEnter Number => ");
	scanf("%d",&iNum);

	// Function call
	iTemp=CheckArmstrong(iNum);
	if(iTemp == iNum)
	{
		printf("%d number is armstrong.\n",iNum);
	}
	else
	{
		printf("\n%d Number is not armstrong\n",iNum);
	}
	printf("\n");
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:	CheckArmstrong
//
//		Input			:	Integer
//
//		Returns			:	Integer(sum)
//
//		Description		:	This function accept number from user and check whether num is armstrong or not using recursion.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int CheckArmstrong(long int iNo)
{
	static int iSum=0;
	static int iDigit=countDigit(iNo);
	int iTemp=0;
	if(iNo > 0)
	{
		iTemp=iNo % 10;
		iSum=iSum+Pow(iTemp,iDigit);
		iNo=iNo/10;
		CheckArmstrong(iNo);
	}
		return iSum;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:	CountDigit
//
//		Input			:	Integer
//
//		Returns			:	Integer
//
//		Description		:	Accept number and count number of digit of that number.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 int countDigit(int iNum)
 {
	 int iCnt=0;
	 while(iNum > 0)
	{
		
		iNum=iNum / 10;
		iCnt++;		
	}
	return iCnt;
 }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:	Pow
//
//		Input			:	Integer
//
//		Returns			:	Integer(count)
//
//		Description		:	Accept number and count power of that number.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 long int Pow(int iNumber,int iDig)
 {
	 int iPower=1;
	 while(iDig > 0)
	 {
		 iPower=iPower*iNumber;
		 iDig--;
	 }

	 return iPower;
 }
/////////////////////////////////////////////////////////////////////////////////////////
//
//			Input		:	Enter Number => 153
//
//			Output		:	153 number is armstrong.
//
////////////////////////////////////////////////////////////////////////////////////////////