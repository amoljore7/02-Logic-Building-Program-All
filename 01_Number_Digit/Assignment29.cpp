/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		29.Write a program to reverse the number.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>

//function prototype
int ReverseNum(int);

int main()
{
	//local variable
	int iNum=0;
	int iReverse=0;

	//accept number from user to find its reverse
	printf("\n Enter the number => ");
	scanf("%d",&iNum);
	
	iReverse=ReverseNum(iNum);
	//print the reverse of given number
	printf("\n The reverse of %d is %d.",iNum,iReverse);

	return 0;
}

/////////////////////////////////////////////////////////////////////////////////
//
//			Function Name		:	ReverseNum
//
//			Input				:	integer
//
//			Returns				:	integer
//
//			Description			:	This function accept number from user and
//									print reverse of given number.
//
/////////////////////////////////////////////////////////////////////////////////

int ReverseNum(
					int iNo		
			  )
{
	//local variable
	int iReverse=0;
	int iDigit=0;

	//while loop is used to calculate reverse of given number
	while(iNo>0)
	{	
		iDigit=iNo%10;
		iNo=iNo/10;
		iReverse=iReverse*10+iDigit;
	}
	return iReverse;
}
/////////////////////////////////////////////////////////////////////////////////
//
//		Input		: Enter the number => 1535
//
//		Output		: The reverse of 1535 is 5351.
//
/////////////////////////////////////////////////////////////////////////////////
