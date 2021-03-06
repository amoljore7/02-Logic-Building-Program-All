///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// 3. Write a program which prints alternate numbers from 1 to 100 in
// recursive manner.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

// Function Prototype
void PrintAltNum();

int main()
{
	// Function call
	PrintAltNum();

	printf("\n");
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function		:	PrintAltNum
//
//		Return			:	void
//
//		Description		:	This function print 1 To 100 Number Alternatively by Using Recursion
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PrintAltNum()
{
	static int iNo=1;
	if(iNo<=100)
	{
		printf("%d\t",iNo);
		iNo+=2;
		PrintAltNum();
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Output		:	1       3       5       7       9       11      13      15      17      19
//						21      23      25      27      29      31      33      35      37      39
//						41      43      45      47      49      51      53      55      57      59
//						61      63      65      67      69      71      73      75      77      79
//						81      83      85      87      89      91      93      95      97      99
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 11 ����..