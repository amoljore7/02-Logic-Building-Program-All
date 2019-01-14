///////////////////////////////////////////////////////////////////////////////////////
//
//	20.Write a program to check given number is prime number or not.
//
//////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

//funcation prototype
int CheckPrimeNumber(int);

int main()
{
	// Local Variable
	int iNumber=0;   

	//accept number from user.
	printf("\n Enter The Number => ");
	scanf("%d",&iNumber);	

	// return value of function taken in to iPrime variable.
	int iPrime=CheckPrimeNumber(iNumber);   

	// Here iPrime value check with 2 because prime number have only two factors i.e. 1 and that number itself.
	if(iPrime==2)   
	{
		printf("%d is prime number ",iNumber);  
	}
	else
	{
		printf("%d is not prime number  ",iNumber);
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//			Funcation Name	:	CheckPrimeNumber
//
//			Input			:	integer
//
//			Returns			:	integer
//
//			Descripation	:	This funcation aceept number from user and check the number is prime or not.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

	// returning the value of factor to the main.
	return factor;		
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//				Input:	Enter The Number => 5
//
//				Output:	5 is prime number.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////
