////////////////////////////////////////////////////////////////////////////////////////
//
//		17.Write a program which accepts string from user and append
//		second string after first string.(Implement strcat())
//
///////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

//Function Prototype
char* MyStrCat(char *,char *);

int main()
{
	char Source[40]={'\0'};
	char Dest[40]={'\0'};

	//Accept strings.
	puts("\n Enter the first string => ");
	gets(Source);

	puts("\n Enter the second string");
	gets(Dest);
	
	//call to function
	printf("\n After concatination source string is => %s\n",MyStrCat(Source,Dest));

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////
//
//			Function Name		: MyStrcat
//
//			Input				: Address of sring,Address of string
//
//			Returns				: Address of Source string
//
//			Description			: This Function accepts two string and append the 
//								  second string after first string.
//
//////////////////////////////////////////////////////////////////////////////////////////

char* MyStrCat(char* cSource,char* cDest)
{
	//Assigning address of dest string to pointer for returing purpose.
	char *cSource1=cSource;
	
	if(*cDest == NULL || *cSource == NULL)
	{
		return NULL;
	}
	//following while is used to reach the end of first string
	while(*cSource!='\0')
	{
		cSource++;
	}
	*cSource=32;
	cSource++;

	//following while loop is used to append the second string after first string
	while(*cDest!='\0')
	{
		//append the contents of second string after first string.
		*cSource=*cDest;
		
		//incrementing pointer to the next address.
		*cSource++;*cDest++;
	}
	
	//writing \0 at the end of source string it is very imp.
	*cSource='\0';

	//returing the base address of destination string.
	return cSource1;
}

/////////////////////////////////////////////////////////////////////////////////////////////
//
//			Input	:Prasad Kamble
//
//			Output	:Source string is => PrasadKamble 
//
////////////////////////////////////////////////////////////////////////////////////////////