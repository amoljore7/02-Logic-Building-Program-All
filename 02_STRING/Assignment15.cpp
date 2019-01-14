////////////////////////////////////////////////////////////////////////////////////////
//
//		15.Write a program which accepts string from user and copy N characters into
//		some another string.(Implement strncpy())
//
///////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

//MACRO definition
#define AND &&

//Function Prototype
char* MyStrNCpy(char *,char *,int);

int main()
{
	char Source[20]={'\0'};
	char Dest[20]={'\0'};
	
	int iNum=0;

	//Accept source string.
	puts("Enter the source string => ");
	gets(Source);
	
	printf("\n Enter number to copy characters => ");
	scanf("%d",&iNum);

	printf("%s",MyStrNCpy(Dest,Source,iNum));

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////
//
//			Function Name		: MyStrNCpy
//
//			Input				: Address of sring,Address of string,integer
//
//			Returns				: Address of Destination string
//
//			Description			: This Function accepts two string and copy N characters
//								  of second string into first string.
//
//////////////////////////////////////////////////////////////////////////////////////////

char* MyStrNCpy(char* cDest,char* cSource,int iNo)
{
	//Assigning address of dest string to pointer for returing purpose.
	char *cDest1=cDest;
	
	if(*cSource == NULL)
	{
		return NULL;
	}

	while(*cSource!='\0' AND iNo>0)
	{
		//Copy string source to sring destination.
		*cDest=*cSource;

		//Incrementing pointer to the next character
		cSource++;cDest++;
		iNo--;
	}
	
	//writing \0 at the end of destination string it is very imp.
	*cDest='\0';

	//returing the base address of destination string.
	return cDest1;
}



/////////////////////////////////////////////////////////////////////////////////////////////
//
//			Input	:My Name Is Prasad. 7
//
//			Output	:Destination string is => My Name
//
////////////////////////////////////////////////////////////////////////////////////////////