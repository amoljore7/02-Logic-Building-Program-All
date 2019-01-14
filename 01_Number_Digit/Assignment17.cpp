/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		17.Write a program to check given number is perfect number or not.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>

// Function prototype
void CheckPerfectNumber(int);

int main()
{
	 //local Variable
	int iNumber=0;  

	 //Accepting Number From User
	printf("\n Enter The Number => "); 
	scanf("%d",&iNumber);

	//   Calling Funcation
	CheckPerfectNumber(iNumber);  

	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	: CheckPerfectNumber
//
//		Input			: integer 
//
//		Returns			: Void
//
//		Description		: This function accepts number and checks it is perfect number or not .
//
///////////////////////////////////////////////////////////////////////////////////////////
void CheckPerfectNumber(int Num)
{
	//Local Variable;
	 int iSum=0; 
	register int iDivisor=0;
			
			
	iDivisor++;
	// Loop to find iDivisor of That Nummber
	while(iDivisor<Num)  
	{
		if((Num%iDivisor)==0)
		{
			iSum=iSum+iDivisor;   // Calculate the sum of iDivisor of The Number
		}
			iDivisor++;
	}

	 // it check the number is equal to sum of iDivisor.
	if(Num==iSum)  
	{
		printf("\n %d is Perfect Number.",Num);
	}
	else
	{
		printf("\n %d is not Perfect Number.",Num);
	}
	return ;
}
//////////////////////////////////////////////////////////////////////////////
//
//		Input	: Enter The Number => 6 
//
//		Output	: 6 is Perfect Number.
//
//////////////////////////////////////////////////////////////////////////////