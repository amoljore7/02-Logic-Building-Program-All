////////////////////////////////////////////////////////////////////////////////////////
//
//		16.Write a program which accepts string from user and copy last N characters into
//		some another string.(Implement strncpy())
//
///////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>


//MACRO definition
#define AND &&

//Function Prototype
char* CopyLastNChar(char *,char *,int);
int StringLen(char *);

int main()
{
	char Source[20]={'\0'};
	char Dest[20]={'\0'};
	int iNum=0;

	//Accept source string.
	puts("Enter the source string => ");
	gets(Source);
	
	printf("\n Enter number to copy last N characters => ");
	scanf("%d",&iNum);

	printf("\n %s",CopyLastNChar(Dest,Source,iNum));
	
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////
//
//			Function Name		: CopyLastNChar
//
//			Input				: Address of sring,Address of string,integer
//
//			Returns				: Address of Destination string
//
//			Description			: This Function accepts two string and copy last N characters
//								  of second string into first string.
//
//////////////////////////////////////////////////////////////////////////////////////////

char* CopyLastNChar(char* cDest,char* cSource,int iNo)
{
	//Assigning address of dest string to pointer for returing purpose.
	char *cDest1=cDest;

	if(cSource == NULL || iNo > StringLen(cSource))
	{
		return NULL;
	}
	
	//Moving pointer to the required address.
	cSource=cSource+(StringLen(cSource)-iNo);

	while(*cSource!='\0')
	{
			//Copy string source to sring destination.
			*cDest=*cSource;

			//Incrementing pointer to the next character
			cSource++;cDest++;
	}
	
	//writing \0 at the end of destination string it is very imp.
	*cDest='\0';

	//returing the base address of destination string.
	return cDest1;
}

int StringLen(char *ptr)
{
	char *ptr1=ptr;
	while(*ptr != '\0')
	{
		*ptr++;
	}
	return ptr-ptr1;
}
/////////////////////////////////////////////////////////////////////////////////////////////
//
//			Input	:rohan prasad 6
//
//			Output	:Destination string is => prasad
//
////////////////////////////////////////////////////////////////////////////////////////////
