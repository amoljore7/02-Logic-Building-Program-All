/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		28.Write a program to find sum of digits of given number.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>

//function prototype
int FindSumOfDigits(int);

int main()
{
	//local variable
	int iNum=0;
	int iSum=0;

	//accept number from user to find its sum of digits
	printf("\n Enter the number => ");
	scanf("%d",&iNum);
	
	iSum=FindSumOfDigits(iNum);
	//print the sum of digits of given number.
	printf("\n The sum of digits of %d is %d.",iNum,iSum);

	return 0;
}

/////////////////////////////////////////////////////////////////////////////////
//
//			Function Name		:	FindSumOfDigits
//
//			Input				:	integer
//
//			Returns				:	int
//
//			Description			:	This function accept number from user and
//									print sum of its all digits.
//
/////////////////////////////////////////////////////////////////////////////////

int FindSumOfDigits(
					int iNo		
			  )
{
	//local variable
	int iSum=0;
	int i;

	//while loop is used to calculate sum of digits of given number
	while(iNo>0)
	{	
		i=iNo%10;
		iSum=iSum+i;
		iNo=iNo/10;
	}
	return iSum;
}
/////////////////////////////////////////////////////////////////////////////////
//
//		Input		: Enter the number => 1535
//
//		Output		: The sum of digits of 1535 is 14
//
/////////////////////////////////////////////////////////////////////////////////
