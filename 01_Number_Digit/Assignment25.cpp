////////////////////////////////////////////////////////////////////////////////////////////
//
//		25.Write a program to print Fibonacci series accept number of element in series 
//		from user.
//
////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

//function prototype
void PrintFibonacciSeries(int);

int main()
{
	int iNo=0;

	//accept number from user
	printf("\n Enter the number to print series => ");
	scanf("%d",&iNo);

	//calling function
	PrintFibonacciSeries(iNo);

	return 0;

}

//////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:	PrintFibonacciSeries
//
//		Parameters		:	integer
//
//		Returns			:	void
//
//		Description		:	This function prints the fibonacci series.
//
//////////////////////////////////////////////////////////////////////////////////

void PrintFibonacciSeries(int iNum)
{
	int i=0;
	int iNo1=1;
	int iNo2=0;
	int iNo3=0;

	printf("\n The Fibonacci series is => ");
	for(i=1;i<=iNum;i++)
	{
		printf("%d\t",iNo3);
		iNo2=iNo3;
		iNo3=iNo1;
		iNo1=iNo2+iNo3;
	}

	
}

///////////////////////////////////////////////////////////////////////////////////
//
//		Input	:	Enter the number to print series => 6
//
//		Output	:	The Fibonacci series is => 0 1 1 2 3 5
//
//////////////////////////////////////////////////////////////////////////////////