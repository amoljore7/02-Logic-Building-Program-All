///////////////////////////////////////////////////////////////////////////////////////////////
//
//	30.Write a program which sets first N characters in string to a specific character.
//	(Implement strnset()).    
//
///////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>


//////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:	MyStrNSet
//
//		Parameters		:	Address of string ,integer, character
//
//		returns			:	Address of string
//
//		Description		:	This function sets first N characters in the string to a specific character.
//
////////////////////////////////////////////////////////////////////////////////////////////////
char* MyStrNSet(char *ptr1,int iNo,char ch)
{
	char *ptr2=ptr1;	
	
	while(*ptr1 != '\0' && iNo > 0)
	{
		*ptr1=ch;
		ptr1++;
		iNo--;
	}

	return ptr2;
}

int main()
{
	char string[30]={'\0'};
	char ch;
	int iNum=0;

	//accept string from user
	printf("\n Enter string => ");
	gets(string);

	printf("\n Enter character => ");
	scanf("%c",&ch);

	printf("\n Enter value of N => ");
	scanf("%d",&iNum);

	printf("%s",MyStrNSet(string,iNum,ch));
	
	return 0;
}
///////////////////////////////////////////////////////////////////////////////
//
//		Input	:	Enter string => level 
//					Enter character => a
//					Enter value of N => 4   
//					
//		Output	:	aaaal
//
///////////////////////////////////////////////////////////////////////////////