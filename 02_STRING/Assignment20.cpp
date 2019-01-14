/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		20.Write a program which accept two strings from user and compare only first N
//		characters of two strings. If both strings are equal till first N characters then
//		return 0 otherwise return difference between first mismatch character
//		(Implement strncmp()).
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

//MACRO definition
#define AND &&
#define OR ||

//Function Prototype
int MyStrNCmp(char *,char *,int);


int main()
{
	char Source[20]	={'\0'};
	char Dest[20]	={'\0'};
	int iRes = 0;
	int iNum = 0;

	//Accept strings.
	puts("\nEnter the first string => ");
	gets(Source);
	
	puts("\nEnter the second string => ");
	gets(Dest);
	
	printf("\nEnter number to compare =>");
	scanf("%d",&iNum);
	
	iRes=MyStrNCmp(Source,Dest,iNum);
	if(iRes == 0)
	{
		printf("\nBoth string are equal\n");
	}
	else
	{
		printf("\nBoth string are not equal.\nDifference is =>%d\n",iRes);
	}


	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////
//
//			Function Name		: MyStrCmp
//
//			Input				: Two string 

//			Returns				: integer
//
//			Description			: This Function accepts two string and compare both N number
//								  string if difference between both string print difference.
//
/////////////////////////////////////////////////////////////////////////////////////////////

int MyStrNCmp(
					char* cSource,
					char* cDest,
					int iNo
			)
{

	if(cSource == NULL || cDest == NULL )
	{
		return -1;
	}
	
	
	//following while is used to reach the end of first string
	while((*cSource != '\0' OR *cDest != '\0') AND iNo > 0)
	{
		if(*cSource != *cDest)
		{
			return *cDest - *cSource;
		}
		cSource++;
		cDest++;
		iNo--;
	}

	//returing the base address of destination string.
	return 0;
}


/////////////////////////////////////////////////////////////////////////////////////////////
//
//			Input	:	Prasad 
//						Prasa
//						4
//
//			Output	:Both String Are Equal 
//
////////////////////////////////////////////////////////////////////////////////////////////