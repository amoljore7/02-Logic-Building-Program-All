/////////////////////////////////////////////////////////////////////////////////////////
//
//		16.Write a program which accept N numbers from user and print second
//		minimum number from that numbers.  
//
/////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
/////////////////////////////////////////////////////////////////////////////////////////
//
//		Function name	:	PrintSecondLastMinNum
//
//		Paramters		:	address of array , integer
//
//		Returns			:	void
//
//		Description		:	This function prints second last min number from N numbers.
//
//////////////////////////////////////////////////////////////////////////////////////////
void PrintSecondLastMinNum(int *ptr , int N)
{
	register int i;
	int SecLastMin=0;
	int iMin=*ptr;

	ptr++;

	for( i=1 ; i < N ; i++ )
	{
		if( iMin > *ptr)
		{
			SecLastMin=iMin;
			iMin=*ptr;
		}
		else if(SecLastMin > *ptr ||  SecLastMin < iMin)
		{
			SecLastMin=*ptr;
		}
		ptr++;
	}
	printf("\n Second minimum from 7 numbers is => %d",SecLastMin);

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

	PrintSecondLastMinNum(arr,N);

	return 0;
}

/////////////////////////////////////////////////////////////////////////////////
//
//		Input		: Enter the value of N => 7
//						
//					  Enter the 7 numbers => 4 7 2 1 5 3 8 
//
//		Output		: Second minimum from 7 numbers is => 2
//
/////////////////////////////////////////////////////////////////////////////////
