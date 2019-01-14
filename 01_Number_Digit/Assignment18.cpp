/////////////////////////////////////////////////////////////////////////////////
//
// 18.Write a program which accepts range from user and print perfect numbers
//
/////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

//Function prototype
void Perfect_Num_Range(int,int);	

int main()
{
	//  Local Variable
	int iFirstRange=0;   // starting range
	int iLastRange=0;    // ending  range

	//accept strting range value from user
	printf("\n Enter The First Range Value => ");  
	scanf("%d",&iFirstRange);			

	//accept ending range value from user
	printf("\n Enter The Last Range value => ");  
	scanf("%d",&iLastRange);		   
	
	Perfect_Num_Range(iFirstRange,iLastRange);
	
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	 : Perfect_Num_Range
//
//		Input			 : integer , integer
//
//		Returns			 : Void
//
//		Description		 : This function accepts minimum and maximum range from user and print all
//						   perfect numbers from that range.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////


void Perfect_Num_Range (
						int iStart, // Starting range
						int iEnd // Ending range
					)
{
	// Local Variable
	int iNum=0;
	int iSum=0;
	register int iDivisor=0;
		
	// validation for check proper range.
	if(iStart>=iEnd)	
	{
		printf("\n Please Enter Corect range.. ");
		return;
	}
		
	printf("\n Perfect numbers are : ");
	for(iNum=iStart;iNum<=iEnd;iNum++)		// This loop travarse elements in given range.
	{
		iDivisor=1;	
		iSum=0;
			
		while(iDivisor<iNum)		// This loop find out the factors of integer number.
		{
			if(iNum%iDivisor==0)
			{	
				iSum=iSum+iDivisor;  //This statement calculate sum of factors .
			}
			iDivisor++;
		}// end while loop

		//print the perfect number if iSum is equal to iNum.
		if(iNum==iSum)				
		{
			printf("%d\t",iNum);
		}
	}// Ending of for loop
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//		Input	: Enter the first range value => 1 
//				  Enter the last range value => 100
//
//		Output  : Perfect numbers are : 6  28
//
///////////////////////////////////////////////////////////////////////////////////////////
