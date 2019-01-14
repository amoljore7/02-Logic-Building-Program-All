//////////////////////////////////////////////////////////////////////////////////////
//
//		10.Write a program which accept N from user and print number-line for N.
//
//////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>

//Function prototype
void PrintNumLine(int);

int main()
{
	//local variable
	int iNum=0;

	//accept number from user
	printf("\n Enter value of N => ");
	scanf("%d",&iNum);

	//call to fuction 
	PrintNumLine(iNum);

	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name:		PrintNumLine
//
//		Input		 :		integer
//
//		Returns		 :		void
//
//		Description	 :		This function accepts integer number and print the
//							number-line for N.
//
///////////////////////////////////////////////////////////////////////////////////////

void PrintNumLine(
					int N	//value of N
				 )
{
	//local variable
	register int i=-N;

	printf("\n Number line for %d is => :",N);
	while(i<=N)
	{
		printf("%d \t",i);
		i++;
	}

}	
/////////////////////////////////////////////////////////////////////////////////
//
//		Input		:	Enter value of N => 4
//
//		Output		:	Number line for %d is => :-4 -3 -2 -1 0 1 2 3 4
//
/////////////////////////////////////////////////////////////////////////////////