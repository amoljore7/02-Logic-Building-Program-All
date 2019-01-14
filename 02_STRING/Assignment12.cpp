////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		12.Write a program which toggles the case of a string.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>

//MACRO definition
# define AND &&

//Function protype
char* MyStrToggle(char *);

int main()
{
	//create array to store string.
	char cString[20]={'\0'};

	//accept string from user.
	printf("\n Enter the string => ");
	scanf("%[^\n]",&cString);
	
	//call to function
	printf(" %s\n",MyStrToggle(cString));	
	
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////
//
//			Function Name		:	MyStrToggle
//
//			Input				:	Address of string
//
//			Returns				:	Address of string
//
//			Description			:	This function accepts address of string
//									and Toggle the string .
//
/////////////////////////////////////////////////////////////////////////////////////////

char* MyStrToggle(
					char *cPtr1
				 )
{
	//local variable
	char *cPtr=cPtr1;

	while(*cPtr1!='\0')
	{
		if(*cPtr1 >= 'a' AND *cPtr1 <= 'z')
		{
			*cPtr1=*cPtr1 - 32;
		}
		else if(*cPtr1 >= 'A' AND *cPtr1 <= 'Z')
		{
			*cPtr1 = *cPtr1 + 32;
		}

		cPtr1++;
	}
	return cPtr; 
}

/////////////////////////////////////////////////////////////////////////////////
//
//		Input		: roHAn PRasad
//
//		Output		: ROhaN prASAD
//
/////////////////////////////////////////////////////////////////////////////////
