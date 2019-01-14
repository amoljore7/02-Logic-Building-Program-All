///////////////////////////////////////////////////////////////////////////////////////////////
//
//	28.Write a program which accept string from user and check whether string is palindrome 
//	or not.   
//
///////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<conio.h>

typedef int BOOL;

#define TRUE 1
#define FALSE 0



//////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:	CheckPalindrome
//
//		Parameters		:	Address of string
//
//		returns			:	integer
//
//		Description		:	This function check whether the string is palindrome or not.
//
////////////////////////////////////////////////////////////////////////////////////////////////
BOOL CheckPalindrome(char *ptr1)
{
	char *ptr2;

	if(ptr1 == NULL)
	{
		return FALSE;
	}
	ptr2=ptr1;

	while(*ptr2 != '\0')
	{
		ptr2++;
	}
	ptr2--;

	while(ptr1 <= ptr2)
	{
		if(*ptr1 != *ptr2)
		{
			return FALSE;
		}
		ptr1++;
		ptr2--;
	}


	return TRUE;
}

int main()
{
	char string[30]={'\0'};

	//accept string from user
	printf("\n Enter string => ");
	gets(string);

	int result=CheckPalindrome(string);

	if(result)
	{
		printf("\n String is palindrome.");
	}
	else
	{
		printf("\n String is not palindrome.");
	}

	getch();
	return 0;
}
///////////////////////////////////////////////////////////////////////////////
//
//		Input	:	level
//
//		Output	:	String is palindrome.
//
///////////////////////////////////////////////////////////////////////////////