////////////////////////////////////////////////////////////////////////////////////////
//
// 19.Write a program which accept two strings from user and compare two
// strings. If both strings are equal then return 0 otherwise return difference
// between first mismatch character (Implement strcmp()).
//
///////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

//MACRO definition
#define AND &&

//Function Prototype
int MyStrCmp(char *,char *);

int main()
{
	char Source[40]={'\0'};
	char Dest[40]={'\0'};

	int iRes = 0;
	
	//Accept strings.
	puts("Enter the first string => ");
	gets(Source);
	
	puts("Enter the second string => ");
	gets(Dest);
	
	//call to function
	iRes=MyStrCmp(Source,Dest);
	if(iRes == 0)
	{
		printf("\nBoth string are equal\n");
	}
	else
	{
		printf("Both string are not equal.\nDifference is => %d\n",iRes);
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
//			Description			: This Function accepts two string and compare both
//								  string if difference between both string print difference.
//
/////////////////////////////////////////////////////////////////////////////////////////////

int MyStrCmp(
					char* cSource,
					char* cDest
			)
{
	if(cSource == NULL || cDest == NULL)
	{
		return -1;
	}
	
	//following while is used to reach the end of first string
	while(*cSource != '\0' || *cDest != '\0')
	{
		if(*cSource != *cDest)
		{
			return *cDest - *cSource;
		}
		cSource++;
		cDest++;
	}

	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////
//
//			Input	:	Prasad 
//						Prasad
//
//			Output	:Both String Are Equal 
//
////////////////////////////////////////////////////////////////////////////////////////////