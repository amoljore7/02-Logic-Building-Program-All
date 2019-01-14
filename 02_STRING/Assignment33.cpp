///////////////////////////////////////////////////////////////////////////////////////////////
//
//	33.Write a program which accept string from user and search last occurrence of specific 
//	character in string and return the position at which character is found.
//	(Implement strchr()).      
//
///////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:	MyStrChr
//
//		Parameters		:	Address of string , character
//
//		returns			:	integer
//
//		Description		:	This function search last occurrence of specific character in string.
//							if found then return position.otherwise return 0
//
///////////////////////////////////////////////////////////////////////////////////////////////////////
int MyStrChr(char *ptr1 ,char ch)
{
	int count=0;
	int lastocc=0;

	if(ptr1 == NULL )
	{
		return 0;
	}
	
	while(*ptr1 != '\0' )
	{
		count++;

		if(*ptr1 == ch)
		{
			lastocc=count;
		}
		ptr1++;
	}
	return lastocc;
}

int main()
{
	char string[30]={'\0'};
	char ch;

	//accept string from user
	printf("\n Enter string => ");
	gets(string);

	printf("\n Enter character => ");
	scanf("%c",&ch);

	int result=MyStrChr(string,ch);

	if(result)
	{
		printf("\n Last occurrence of character %c is found at %d position.",ch,result);
	}
	else
	{
		printf("\n Character is not found in the string.");
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////
//
//		Input	:	Enter string => abcd rohan
//					Enter character => a 
//					
//		Output	:	Last occurrence of character a is found at 9 position.
//
///////////////////////////////////////////////////////////////////////////////