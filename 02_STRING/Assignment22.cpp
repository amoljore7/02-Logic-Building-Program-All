////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	 22.Write a program which accept string from user and then reverse the string
//	without taking another string (Implement strrev()).
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

// Function prototype
char* MyRevStr(char *);

int main()
{
	//Declaring array for string
	char cSource[30]={'\0'};

	// Accept string prom user
	printf("\nEnter string => ");
	scanf("%[^\n]",cSource);

	printf("Reverse string is => %s\n",MyRevStr(cSource));

	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Input		:		Address of String
//
//		return		:		Address of reverse string
//
//		Description	:		Accept string and reverse that string without using 
//							another string.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

char* MyRevStr(
				char *cPtr1
			)
{
	// Creating local pointer 
	char *cPtr2,*cPtr3;

	//this variable is use to hold temporary character
	char temp;

	if(cPtr1 == NULL)
	{
		return NULL;
	}

	//Assign cPtr pointer to *cPtr1 and *cPtr2
	cPtr2=cPtr3=cPtr1;

	while(*cPtr2 != '\0')
	{
		cPtr2++;
	}
	cPtr2--;

	while(cPtr1 <= cPtr2)
	{
		temp = *cPtr2;
		*cPtr2 = *cPtr1;
		*cPtr1 = temp;

		cPtr1++;
		cPtr2--;
	}
	return cPtr3;
}

//////////////////////////////////////////////////////
//
//		Input		:		Prasad Rohan
//		
//		OutPut		:		nahoR dasarP
//
//////////////////////////////////////////////////////