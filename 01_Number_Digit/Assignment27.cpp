/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		27.Write a program to find number of digits of given number.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>

//function prototype
int FindDigits(int);

int main()
{
	//local variable
	int iNum;

	//accept number from user to find its digits
	printf("\n Enter the number => ");
	scanf("%d",&iNum);
	
	//print the digits of given number
	printf("\n The digits of %d is %d.",iNum,FindDigits(iNum));

	return 0;
}

/////////////////////////////////////////////////////////////////////////////////
//
//			Function Name		:	FindDigits
//
//			Input				:	integer
//
//			Returns				:	int
//
//			Description			:	This function accept number from user and
//									print its digits.
//
/////////////////////////////////////////////////////////////////////////////////

int FindDigits(
					int iNo		
			  )
{
	//local variable
	int iDigit=0;
	int i;

	//while loop is used to calculate digits of given number
	while(iNo>0)
	{	
		iDigit++;	
		i=iNo%10;
		iNo=iNo/10;
	}
	return iDigit;
}
/////////////////////////////////////////////////////////////////////////////////
//
//		Input		: Enter the number => 1535
//
//		Output		: The digits of 1535 is 4.
//
/////////////////////////////////////////////////////////////////////////////////
