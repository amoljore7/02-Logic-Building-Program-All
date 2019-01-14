/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		23.Write a program to find factorial of given number.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>

//function prototype
void FindFactorial(int);

int main()
{
	//local variable
	int iNum=0;

	//accept number from user to find factorial
	printf("\n Enter the number to calculate factorial => ");
	scanf("%d",&iNum);

	//call to funtion FindFactorial()
	FindFactorial(iNum);

	return 0;
}

/////////////////////////////////////////////////////////////////////////////////
//
//			Function Name		:	FindFactorial
//
//			Input				:	integer
//
//			Returns				:	void
//
//			Description			:	This function accept number from user and
//									print its factorial.
//
/////////////////////////////////////////////////////////////////////////////////

void FindFactorial(
					int iNo
				   )
{
	//local variable of function
	int iFact=1;

	//while loop is used to calculate factorial of given number
	while(iNo>0)
	{
		iFact=iFact*iNo;
		iNo--;
	}

	//print the factorial
	printf("\n The Factorial is => %d",iFact);

}
/////////////////////////////////////////////////////////////////////////////////
//
//		Input		: Enter the number to calculate factorial	=>	7 
//
//		Output		: The Factorial is => 5040
//
/////////////////////////////////////////////////////////////////////////////////
