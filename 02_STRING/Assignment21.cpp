///////////////////////////////////////////////////////////////////////////////////////////////////
//
//	21.Write a program which accept two strings from user and compare two strings
//	without case sensitivity. If both strings are equal then return 0 otherwise return
//	difference between first mismatch character (Implement stricmp()).
//
//////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>


//MACRO definition
#define AND &&
#define OR ||

//Function Prototype
int MyStrICmp(char *,char *);
int CountChar(char *);

int main()
{
	char Source[20]	={'\0'};
	char Dest[20]	={'\0'};
	int iRes = 0;

	//Accept strings.
	puts("\nEnter the first string => ");
	gets(Source);
	
	puts("\nEnter the second string => ");
	gets(Dest);
	
	//call to function
	iRes=MyStrICmp(Source,Dest);
	if(iRes == 0)
	{
		printf("\nBoth string are equal\n");
	}
	else
	{
		printf("\nBoth string are not equal.\nDifference is => %d\n",iRes);
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
//			Description			: This Function accepts two string and compare both string without 
//								  case sensivity if difference between both string print difference.
//
/////////////////////////////////////////////////////////////////////////////////////////////

int MyStrICmp(
					char* cSource,
					char* cDest
			)
{
	
	if(cSource == NULL || cDest == NULL || CountChar(cSource)!=CountChar(cDest))
	{ 
		return -1;
	}

	//following while is used to reach the end of first string
	while(*cSource != '\0' AND *cDest != '\0')
	{
		if( (*cSource == *cDest) OR (*cSource - *cDest == 32) OR (*cSource - *cDest == -32) )
		{
			cSource++;
			cDest++;
		}
		else
		{
			return *cDest - *cSource;
		}
	}
	
	return 0;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//			Input		:		String

//			Return		:		Integer

//			description	:		Accept string and count character in that string.
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int CountChar(char *cStr)
{
	int iCount = 0;

	if(*cStr == NULL)
	{
		return iCount;
	}
	
	while(*cStr != '\0')
	{
		iCount++;
		cStr++;
	}
	return iCount;
}


////////////////////////////////////////////////////////////////////////////////////////////
//
//			Input	:	rohan
//						ROHAN
//						
//
//			Output	:Both String Are Equal 
//
////////////////////////////////////////////////////////////////////////////////////////////