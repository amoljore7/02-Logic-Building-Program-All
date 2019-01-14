////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		11.Write a program to convert the string from Lower case to upper case.
//		(Implement strUpr())
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>

//MACRO definition
# define AND &&

//Function protype
char* MyStrUpr(char *);

int main()
{
	//create array to store string.
	char cString[20]={'\0'};

	//accept string from user.
	printf("\n Enter the string => ");
	scanf("%[^\n]",cString);
	
	//call to function
	printf("%s\n",MyStrUpr(cString));	
	
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////
//
//			Function Name		:	MyStrUpr
//
//			Input				:	Address of string
//
//			Returns				:	Address of string
//
//			Description			:	This function accepts address of lower case string
//									and convert the string into upper case.
//
/////////////////////////////////////////////////////////////////////////////////////////

char* MyStrUpr(
				char *cPtr1
			)
{
	//local variable
	char *cPtr2=cPtr1;

	while(*cPtr1!='\0')
	{
		if(*cPtr1>= 'a' AND *cPtr1<= 'z')
		{
			*cPtr1=*cPtr1 - 32;
		}

		cPtr1++;
	}
	return cPtr2; 
}

/////////////////////////////////////////////////////////////////////////////////
//
//		Input		: rohan Prasad
//
//		Output		: ROHAN PRASAD
//
/////////////////////////////////////////////////////////////////////////////////
