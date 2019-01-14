////////////////////////////////////////////////////////////////////////////////////////
//
//		18.Write a program which accepts string from user and append N characters of
//		second string after first string.(Implement strncat())
//
///////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

//MACRO definition
#define AND &&

//Function Prototype
char* MyStrNCat(char *,char *,int);
int CountChar(char *);


int main()
{
	char Source[40]={'\0'};
	char Dest[40]={'\0'};
	int iNum = 0;

	//Accept strings.
	puts("Enter the first string => ");
	gets(Source);
	
	puts("Enter the second string => ");
	gets(Dest);

	printf("Enter the value of N => ");	
	scanf("%d",&iNum);

	printf("Source string is => %s\n",MyStrNCat(Source,Dest,iNum));
	
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////
//
//			Function Name		: MyStrNCat
//
//			Input				: Address of sring,Address of string,integer
//
//			Returns				: Address of Source string
//
//			Description			: This Function accepts two string and append N characters
//								  of the second string after first string.
//
/////////////////////////////////////////////////////////////////////////////////////////////

char* MyStrNCat(char* cSource,char* cDest,int iNo)
{
	//Assigning address of dest string to pointer for returing purpose.
	char *cSource1=cSource;
	

	if(cSource == NULL || cDest == NULL)
	{
		return NULL;
	}

	//following while is used to reach the end of first string
	while(*cSource!='\0')
	{
		cSource++;
	}

	//following while loop is used to append the second string after first string
	while(*cDest!='\0' AND iNo>0)
	{
		//append the contents of second string after first string.
		*cSource=*cDest;
		
		//incrementing pointer to the next address.
		*cSource++;*cDest++;
		iNo--;
	}
	
	//writing \0 at the end of source string it is very imp.
	*cSource='\0';

	//returing the base address of destination string.
	return cSource1;
}

/////////////////////////////////////////////////////////////////////////////////////////////
//
//			Input	:Prasad Kamble 3
//
//			Output	:Source string is => PrasadKam 
//
////////////////////////////////////////////////////////////////////////////////////////////