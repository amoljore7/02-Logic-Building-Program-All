////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		33.Write a program which accepts number from user and print addition of digits which are 
//		divisible by 3.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>

//function prototype
int AddOfDigitsDivBy3(int);

int main()
{
	//local variable
	int iNum;

	//accept number from user.
	printf("\n Enter the number => ");
	scanf("%d",&iNum);
	
	//print addition of digits which are div.by 3
	printf("%d",AddOfDigitsDivBy3(iNum));

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////
//
//			Function Name	    :	AddOfDigitsDivBy3
//
//			Input				:	integer
//
//			Returns				:	integer
//
//			Description			:	This function accept number from user and print 
//									the addition of digits which are divisible by 3.
//
//////////////////////////////////////////////////////////////////////////////////////

int AddOfDigitsDivBy3(
							int iNo		
					 )
{
	//local variable
	int iDigit=0;
	int iAdd=0;

	//while loop is used to calculate addition of digits 
	while(iNo>0)
	{	
		iDigit=iNo%10;
		
		//check whether number is divisible by 3 or not
		if(iDigit%3==0)
		{
			iAdd=iAdd+iDigit;
		}
		iNo=iNo/10;
	}
	return iAdd;
}
/////////////////////////////////////////////////////////////////////////////////
//
//		Input		: Enter the number => 295367542
//
//		Output		: 18
//
/////////////////////////////////////////////////////////////////////////////////
