////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	22.Write a program to check whether a number is strong number or not.
//      
//////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

 // function protoype
int CheckStrongNum(int); 

int main()
{
	int iNumber=0;
	int result=0;

	//accept number from uset
	printf("\n Enter The Number => ");
	scanf("%d",&iNumber);

	result=CheckStrongNum(iNumber);
	
	if(result == iNumber)
	{
		printf("\n %d number is strong number.",iNumber);
	}
	else
	{
		printf("\n %d number is not strong number.",iNumber);
	}
	
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Funcation name :	CheckStrongNum
//
//		Input          :	integer
//
//		Returns		   :	void
//		
//		Descripation   :	This funcation aceept number from user and to check whether a number 
//							is strong number or not
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

int CheckStrongNum(int iNum)
{
	 int fact_num=0;
	 int factorial=0;
	 int Strong_Sum=0;
	 register int iCount=0;


	while(iNum>0)
	{
		
		fact_num=iNum%10;
		factorial=1;

		// this loop to calculate the factorial of number.
		for(iCount=fact_num;iCount>0;iCount--)		
		{
			factorial=factorial*iCount;   
		}
		Strong_Sum=Strong_Sum+factorial;
		iNum=iNum/10;
	}
	return Strong_Sum;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//			Input : Enter The Number => 145
//
//			Output : 145 is strong number.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////