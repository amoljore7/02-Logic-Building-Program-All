/////////////////////////////////////////////////////////////////////////////////////////
//
//		15.Write a program which accept N numbers from user and print second
//		maximum number from that numbers.  
//
/////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
/////////////////////////////////////////////////////////////////////////////////////////
//
//		Function name	:	PrintSecondLastMaxNum
//
//		Paramters		:	address of array , integer
//
//		Returns			:	void
//
//		Description		:	This function prints second last max number from N numbers.
//
//////////////////////////////////////////////////////////////////////////////////////////
void PrintSecondLastMaxNum(int *ptr , int N)
{
	register int i;
	int SecLastMax=0;
	int iMax=*ptr;

	ptr++;

	for( i=1 ; i <= N ; i++ )
	{
		if( iMax < *ptr)
		{
			SecLastMax=iMax;
			iMax=*ptr;
		}
		else if( SecLastMax < *ptr)
		{
			SecLastMax=*ptr;
		}
		ptr++;
	}
	printf("\n Second maximum from 7 numbers is => %d",SecLastMax);

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

	PrintSecondLastMaxNum(arr,N);

	return 0;
}

/////////////////////////////////////////////////////////////////////////////////
//
//		Input		: Enter the value of N => 7
//						
//					  Enter the 7 numbers => 4 7 2 1 5 3 8 
//
//		Output		: Second maximum from 7 numbers is => 7
//
/////////////////////////////////////////////////////////////////////////////////
