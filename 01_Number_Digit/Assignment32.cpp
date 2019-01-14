////////////////////////////////////////////////////////////////////////////////////////////
//
//		32.Write a program which accept range from user
//		and print all numbers from that range whose addition of digits of that number is prime number.   
//		Input : 20 30 Output : 20 21 23 25 29 30 
//
////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

//function prototype
void PrintPrimeInRange(int,int);
int CheckPrimeNumber(int);

int main()
{
	int iNo1=0;
	int iNo2=0;
	
	//accept starting range from user
	printf("\n Enter the Start range => ");
	scanf("%d",&iNo1);

	//accept ending range from user
	printf("\n Enter the  End ragne => ");
	scanf("%d",&iNo2);

	//calling function
	PrintPrimeInRange(iNo1,iNo2);

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:	PrintPrimeInRange
//
//		Parameters		:	integer
//
//		Returns			:	void
//
//		Description		:	This function prints all number in range whose sum of digts is prime.
//
/////////////////////////////////////////////////////////////////////////////////////////////////

void PrintPrimeInRange(int iSource,int iDest)
{

	//   Local variable
	int i=0;		
	int iNum=0;
	int iSum=0;
	int digit=0;

	for(i=iSource; i<=iDest ;i++)
	{
			iNum=i;
			iSum=0;	

			//This loop is used to find sum of number.
			while(iNum>0)
			{
				digit=iNum%10;
				iSum=iSum+digit;
				iNum=iNum/10;
			}

			// Calling function to check whether sum of digits is prime number or not.
			//for this we take help of helper function instead of writing code for prime logic in this function.  
			
			if((CheckPrimeNumber(iSum)) == 2)
			{
				printf("%d\t",i);
			}

	}
	return ;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:	CheckPrimeNumber
//
//		Parameters		:	integer
//
//		Returns			:	int
//
//		Description		:	This function  check number  is prime or not and print the prime number.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

int CheckPrimeNumber(int iNum)
{
	// local variable
	int factor=0;
	int iCount=1;
			 
	// This loop is to count factors of given number.
	while(iCount<=iNum)	
	{
		if((iNum%iCount)==0)    
		{
			factor++;  //factor counter
		}
		iCount++;
	}					

	// returning the value of factor to the PrintPrimeInRange.
	return factor;		
}


///////////////////////////////////////////////////////////////////////////////////
//
//		Input	:
//                 Enter the Start range => 50
//				   Enter the  End ragne => 75
//		Output  :	
//				   50      52      56      58      61      65      67      70      74
//
//////////////////////////////////////////////////////////////////////////////////