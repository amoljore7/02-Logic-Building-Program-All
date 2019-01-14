////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		10.Write a program to convert the string from upper case to lower case.
//		(Implement strlwr())
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>

//MACRO definition
# define AND &&

//Function protype
char* MyStrLwr(char *);

int main()
{
	//create array to store string.
	char cString[20]={'\0'};

	//accept string from user.
	printf("\n Enter the string =>");
	scanf("%[^\n]",cString);
	
	//call to function
	printf("%s",MyStrLwr(cString));	
	
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////
//
//			Function Name		:	MyStrLwr
//
//			Input				:	Address of string
//
//			Returns				:	Address of string
//
//			Description			:	This function accepts address of upper case string
//									and convert the string into lower case.
//
/////////////////////////////////////////////////////////////////////////////////////////

char* MyStrLwr(
				char *cPtr1
			)
{
	//local variable
	char *cPtr2=cPtr1;

	while(*cPtr1!='\0')
	{
		if(*cPtr1>=65 AND *cPtr1<=90)
		{
			*cPtr1=*cPtr1+32;
		}

		cPtr1++;
	}
	return cPtr2; 
}

/////////////////////////////////////////////////////////////////////////////////
//
//		Input		: MY NAME IS PRASAD.
//
//		Output		: my name is prasad.
//
/////////////////////////////////////////////////////////////////////////////////
