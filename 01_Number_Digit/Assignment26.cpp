/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		26.Write a program to find power of given number.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>

//function prototype
int FindPower(int,int);

int main()
{
	//local variable
	int iNum=0,iPow=0;

	//accept numbers from user to find power
	printf("\n Enter the number => ");
	scanf("%d",&iNum);
	printf("\n Enter the power of given number => ");
	scanf("%d",&iPow);

	//print the power of given number
	printf("\n The power of %d with %d is => %d",iNum,iPow,FindPower(iNum,iPow));

	return 0;
}

/////////////////////////////////////////////////////////////////////////////////
//
//			Function Name		:	FindPower
//
//			Input				:	integer,integer
//
//			Returns				:	int
//
//			Description			:	This function accept number from user and
//									print its power.
//
/////////////////////////////////////////////////////////////////////////////////

int FindPower(
					int iNo,		
					int iPower
				   )
{
	//local variable
	int iTemp=1;
	
	//for loop is used to calculate power of given number
	while(iPower>0)
	{	
		iTemp=iTemp*iNo;
		iPower--;
	}
	return iTemp;
}
/////////////////////////////////////////////////////////////////////////////////
//
//		Input		: Enter the number => 2 
//					  Enter the power of given number => 4
//
//		Output		: The power of 2 with 4 is => 16
//
/////////////////////////////////////////////////////////////////////////////////
