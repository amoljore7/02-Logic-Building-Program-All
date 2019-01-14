////////////////////////////////////////////////////////////////////////////////////////////////
//
//		30.Write a program which accept number from user and print all digits from that number 
//		which are at even position. 
//
/////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

//function prototype
void PrintEvenPosDigits(int num);

int main()
{
	int num;

	//accept number from user
	printf("\n Enter the number => ");
	scanf("%d",&num);
	
	//display number
	printf("\n The number is => %d",num);
	
	//calling function to display even positioned digits.
	PrintEvenPosDigits(num);
	
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:	PrintEvenPosDigits
//
//		Parameters		:	integer
//
//		Returns			:	void
//
//		Description		:	This function prints the even positioned digits from number.
//
/////////////////////////////////////////////////////////////////////////////////////////////////
void PrintEvenPosDigits(int num)
{
	int reverse=0;
	int counter=0;
	int digit=0;

	//following loop is used to reverse the number
	while(num!=0)
	{
		digit=num%10;
		num=num/10;
		reverse=reverse*10+digit;
	}


	printf("\n Even positioned digits are => ");
	while(reverse>0)
	{
		counter++;
		num=reverse%10;
		reverse=reverse/10;
		
		if( counter % 2 == 0)
		{
			printf("%d\t",num);
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////
//
//		Input	:	Enter the number =>	375843 
//
//		Output	:	Even positioned digits are => 7 8 3
//
//
////////////////////////////////////////////////////////////////////////////////////////