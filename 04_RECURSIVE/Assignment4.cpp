///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
///4. Write a program which prints characters from 'A' to 'Z' in recursive
// manner.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

// Function Prototype
void PrintChar();

int main()
{
	// Function call
	PrintChar();
	printf("\n");

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:	PrintChar
//
//
//		Returns			:	void
//
//		Description		:	This function print 'A' To 'Z' characters by Using Recursion
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PrintChar()
{
	static char cChar='A';
	if(cChar<= 'Z')
	{
		printf("%c\t",cChar);
		cChar++;
		PrintChar();
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Output		:	A       B       C       D       E       F       G       H       I       J
//						K       L       M       N       O       P       Q       R       S       T
//						U       V       W       X       Y       Z
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////