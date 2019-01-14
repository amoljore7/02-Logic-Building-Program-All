/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		21.Write a program to check whether given number is Armstrong number or not.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>

//function prototype
void CheckArmstrongNum(int);

int main()
{
	//local variable
	int iNum=0;

	//accept number
	printf("\n Enter the number => ");
	scanf("%d",&iNum);

	//call function
	CheckArmstrongNum(iNum);

	return 0;
}

/////////////////////////////////////////////////////////////////////////////////
//
//		Function Name		: CheckArmstrongNum
//
//		Input				: integer
//
//		Returns				: void
//
//		Description			: This function accept integer number and check 
//							  whether given number is armstong or not.
//
/////////////////////////////////////////////////////////////////////////////////

void CheckArmstrongNum	(
							int iNo		
						)
{
	//local variable
	int lstdig=0,iSum=0;

	//Assigning value of iNo to iNo1 for further checking
	int iNo1=iNo;				

	//while loop is used to calculate cube of each number of original number.
	while(iNo>0)
	{
		lstdig=iNo%10;				//to get last number from original number	
		
		iSum=iSum+(lstdig*lstdig*lstdig);		//sum of cube of each number from original number
		
		iNo=iNo/10;
	}
	
	//check whether number is armstrong or not
	if(iSum==iNo1)
	{
		printf("\n %d is Armstrong number",iNo1);
	}
	else
	{
		printf("\n %d is not Armstrong number",iNo1);
	}
}

/////////////////////////////////////////////////////////////////////////////////
//
//		Input		: Enter the number => 153 
//
//		Output		: 153 is Armstrong number
//
/////////////////////////////////////////////////////////////////////////////////
