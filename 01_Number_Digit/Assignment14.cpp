/////////////////////////////////////////////////////////////////////////////////////////
//
//		14.Write a program which accept N numbers from user and print minimum number 
//		from that numbers.  
//
/////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
/////////////////////////////////////////////////////////////////////////////////////////
//
//		Function name	:	PrintMinNum
//
//		Paramters		:	integer , integer
//
//		Returns			:	void
//
//		Description		:	This function prints minimum number from N numbers.
//
//////////////////////////////////////////////////////////////////////////////////////////
void PrintMinNum(int *ptr , int N)
{
	
	int iMin=*ptr;
	
	register int i;
	
	ptr++;

	for( i=1 ; i < N ; i++ )
	{
		if(iMin > *ptr)
		{
			iMin = *ptr;
		}
		ptr++;
	}
	
	//print min number
	printf("\n Minimum from %d numbers is => %d",N,iMin);

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

	PrintMinNum(arr,N);

	return 0;
}

/////////////////////////////////////////////////////////////////////////////////
//
//		Input		: Enter the value of N => 7
//						
//					  Enter the 7 numbers => 4 7 2 1 5 3 8 
//
//		Output		: Minimum from 7 numbers is => 1
//
/////////////////////////////////////////////////////////////////////////////////
