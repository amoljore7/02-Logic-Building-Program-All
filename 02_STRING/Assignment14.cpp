////////////////////////////////////////////////////////////////////////////////////////
//
//		14.Write a program which accepts string from user and copy that string into
//		some another string.(Implement strcpy())
//
///////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

//Function Prototype
char* MyStrCpy(char *,char *);

int main()
{
	char Source[30]={'\0'};
	char Dest[30]={'\0'};
	
	//Accept source string.
	puts("Enter the source string => ");
	gets(Source);
	
	printf("Destination string is => %s\n",MyStrCpy(Dest,Source));

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////
//
//			Function Name		: MyStrCpy
//
//			Input				: Address of sring,Address of string
//
//			Returns				: Address of Destination string
//
//			Description			: This Function accepts two string and copy second 
//								  string into first string
//
//////////////////////////////////////////////////////////////////////////////////////////

char* MyStrCpy(char* cDest,char* cSource)
{
	//Assigning address of dest string to pointer for returing purpose.
	char *cDest1=cDest;
	
	while(*cSource!='\0')
	{
			//Copy source string to destination string .
			*cDest=*cSource;

			//Incrementing pointer to the next character
			cSource++;cDest++;
	}

	cDest='\0';

	//returing the base address of destination string.
	return cDest1;
}

/////////////////////////////////////////////////////////////////////////////////////////////
//
//			Input	:My Name Is Prasad.
//
//			Output	:Destination string is => My Name Is Prasad.
//
////////////////////////////////////////////////////////////////////////////////////////////