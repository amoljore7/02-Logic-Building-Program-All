//////////////////////////////////////////////////////////////////////////////////////
//
//		5.write a program which accept three numbers and print its multiplication.
//
//////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>

void PrintMultOfNum(int,int,int);

int main()
{
	//Local variable
	int iNum1=0,iNum2=0,iNum3=0;

	//accept the numbers
	printf("\n Enter the three numbers => ");
	scanf("%d %d %d",&iNum1,&iNum2,&iNum3);

	//call the fuction 
	PrintMultOfNum(iNum1,iNum2,iNum3);

	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name:		PrintMultOfNum
//
//		Input		 :		integer,integer,integer
//
//		Returns		 :		void
//
//		Description	 :		This function accepts three integer numbers and print the
//							multiplication of these three numbers.
//
///////////////////////////////////////////////////////////////////////////////////////


void PrintMultOfNum(
						int no1,	//first number
						int no2,	//second number
						int no3		//third number
					)
{
		int answer=0;

		//calculate the multiplication
		answer=(no1 * no2 * no3);

		//print the final answer
		printf("\n The multiplication of three numbers is => %d",answer);

}		
/////////////////////////////////////////////////////////////////////////////////////////
//
//		Input		: Enter the three numbers => 5 4 7
//
//		Output		: The multiplication of three numbers is => 140
//
////////////////////////////////////////////////////////////////////////////////////////
