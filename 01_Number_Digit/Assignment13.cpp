/////////////////////////////////////////////////////////////////////////////////////////
//
//		13.Write a program which accept N numbers from user and print maximum number 
//		from that numbers.  
//
/////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
/////////////////////////////////////////////////////////////////////////////////////////
//
//		Function name	:	PrintMaxNum
//
//		Paramters		:	integer , integer
//
//		Returns			:	void
//
//		Description		:	This function prints max number from N numbers.
//
//////////////////////////////////////////////////////////////////////////////////////////
void PrintMaxNum(int *ptr , int N)
{
	//calculate the addition of N numbers.
	int iMax=*ptr;
	register int i;
	ptr++;

	for( i=1 ; i <= N ; i++ )
	{
		if(iMax < *ptr)
		{
			iMax = *ptr;
		}
		ptr++;
	}
	
	//print max number
	printf("\n Maximum from %d numbers is => %d",N,iMax);

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

	PrintMaxNum(arr,N);

	return 0;
}

/////////////////////////////////////////////////////////////////////////////////
//
//		Input		: Enter the value of N => 7
//						
//					  Enter the 7 numbers => 4 7 2 1 5 3 8 
//
//		Output		: Maximum from 7 numbers is => 8
//
/////////////////////////////////////////////////////////////////////////////////
