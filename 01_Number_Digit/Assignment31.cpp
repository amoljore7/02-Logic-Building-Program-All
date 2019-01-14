////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		31.Write a program which accepts number from user and check whether number is palindrome or not.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>

//function prototype
void IsPalindrome(int);

int main()
{
	//local variable
	int iNum;

	//accept number from user.
	printf("\n Enter the number => ");
	scanf("%d",&iNum);
	
	//call to function
	IsPalindrome(iNum);

	return 0;
}

/////////////////////////////////////////////////////////////////////////////////
//
//			Function Name	    :	IsPalindrome
//
//			Input				:	integer
//
//			Returns				:	void
//
//			Description			:	This function accept number from user and
//									check whether number is palindrome or not.
//
/////////////////////////////////////////////////////////////////////////////////

void IsPalindrome(
					int iNo		
			  )
{
	//local variable
	int iReverse=0;
	int iDigit=0;

	//Assigning value of iNo to iNo1 for further checking.
	int iNo1=iNo;

	//while loop is used to calculate reverse of given number
	while(iNo>0)
	{	
		iDigit=iNo%10;
		iNo=iNo/10;
		iReverse=iReverse*10+iDigit;
	}
	
	//Here we check whether number is palindrome or not
	if(iNo1 == iReverse)
	{
		printf("%d is palindrome number.",iNo1);
	}
	else
	{
		printf("%d is not palindrome number.",iNo1);
	}
}
/////////////////////////////////////////////////////////////////////////////////
//
//		Input		: Enter the number => 151
//
//		Output		: 151 is palindrome number.
//
/////////////////////////////////////////////////////////////////////////////////
