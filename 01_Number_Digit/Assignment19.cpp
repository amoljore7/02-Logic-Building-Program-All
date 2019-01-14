//////////////////////////////////////////////////////////////////////////////////////////////
//
//	19.Write a program which accepts range from user and print prime numbers from given range.
//
///////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

//Function Prototype.
void PrintPrimeNumInRange(int,int); 

int main()
{
	//  Local Variable
	int iFirstRange=0;   // starting range
	int iLastRange=0;    // ending  range

	//accept strting range value from user
	printf("\n Enter the first range value => ");  
	scanf("%d",&iFirstRange);			

	  //accept ending range value from user
	printf("\n Enter the last range value => ");  
	scanf("%d",&iLastRange);		 
	
	//calling function
	PrintPrimeNumInRange(iFirstRange,iLastRange);
	
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:	PrintPrimeNumInRange
//
//		Input			:	integer , integer
//
//		Returns			:	Void
//
//		Description		:	This function accepts minimum and maximum range from user and print all
//							prime numbers from that range.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////
void PrintPrimeNumInRange (
							int iStart, // Starting range
							int iEnd // Ending range
					)
{
	// Local variaable.
	int iCount;
	int factor;
	register int iNum=0;		 

	// Validation for check proper range.
	if(iStart>=iEnd)  
	{
		printf("\n Enter Proper Range...");
		return ;
	}

	printf("\n Prime Numbers from range %d to %d are => : ",iStart,iEnd);
	
	//  This loop used to travarse from starting range to ending range.
	for(iNum=iStart;iNum<=iEnd;iNum++)
	{		
		iCount=1;   
		factor=0;
				 
		while(iCount<=iNum)   // This while loop count the no of factors.
		{
			if((iNum%iCount)==0)
			{
				factor++;    // factor counter
			}
			iCount++;
		}
					
		if(factor==2)		// This if condition check factors of a number ,if factors are two then number is prime.
		{	
			printf("%d\t ",iNum);
		}
	}// end of for loop
	
}
///////////////////////////////////////////////////////////////////////////////////////
//
//		Input	:	Enter the first range value => 1
//					Enter the last range value => 10
//
//		Output	:	Prime Numbers from range 1 to 100 are => : 2 3 5 7 
//
///////////////////////////////////////////////////////////////////////////////////////
