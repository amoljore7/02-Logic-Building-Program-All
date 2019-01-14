/////////////////////////////////////////////////////////////////////////////////////////
//
//		12.Write a program which accept N from user and print addition of those numbers.
//
/////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
/////////////////////////////////////////////////////////////////////////////////////////
//
//		Function name	:	PrintAddOfNNum
//
//		Paramters		:	integer , integer
//
//		Returns			:	void
//
//		Description		:	This function prints addition of N numbers.
//
//////////////////////////////////////////////////////////////////////////////////////////
void PrintAddOfNNum(int *ptr , int N)
{
	//calculate the addition of N numbers.
	int iAddition=0;
	register int i;

	for( i=0 ; i < N ; i++ )
	{
		iAddition = iAddition + *ptr;
		ptr++;
	}
	
	//print addition
	printf("\n Addition of %d numbers is => %d",N,iAddition);

}
int main()
{
	//declaring array to holds the N numbers.
	int arr[10];
	int N;
	register int i;

	//accepting value of N
	printf("\n Enter the value of N => ");
	scanf("%d",&N);

	//accepting N elements
	printf("\n Enter the %d numbers => ",N);
	for(i=0;i<N;i++)
	{
		scanf("%d",&arr[i]);	
	}

	PrintAddOfNNum(arr,N);

	return 0;
}

/////////////////////////////////////////////////////////////////////////////////
//
//		Input		: Enter the value of N => 7
//						
//					  Enter the 7 numbers => 4 7 2 1 5 3 8 
//
//		Output		: Addition of 7 numbers is => 30
//
/////////////////////////////////////////////////////////////////////////////////
