////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// 6. Write a program which prints following pattern in recursive manner.
// Accept number of rows from user.
//  *
//  * *
//  * * *
//
/////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

// Function Prototype

void PrintPattern(int);

int main()
{
	//declaring integer
	int iRow=0;

	printf("\nEnter Row => ");
	scanf("%d",&iRow);

	// Function call
	PrintPattern(iRow);

	printf("\n");
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:	PrintPattern		
//
//		Input		:	integer
//
//		Returns		:	void
//
//		Description	:	This function accept row from user and print pattern using recursion
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PrintPattern(int iRow)
{
	static int iNum=1;
	if(iRow >0)
	{
		for(int iCol=1;iCol <= iNum;iCol++)
		{
			printf("*\t");
		}
		printf("\n");
		iNum++;
		iRow--;
		PrintPattern(iRow);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Input	:	Enter Row => 6
//	
//		Output	:	*
//				*       *
//				*       *       *
//				*       *       *       *
//				*       *       *       *       *
//				*       *       *       *       *       *
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////