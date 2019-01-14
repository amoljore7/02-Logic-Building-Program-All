///////////////////////////////////////////////////////////////////////////////////////////////
//
//	31.Write a program which sets last N characters in string to a specific character.
//	(Implement strnset()).    
//
///////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

int StringLen(char*);

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
	char *ptr2;
	ptr2=ptr1;	

	if(ptr1 == NULL || iNo > StringLen(ptr1))
	{
		printf("\n Wrong input.");
		return NULL;
	}
	
	ptr1=ptr1+(StringLen(ptr1)-iNo);

	while(*ptr1 != '\0' && iNo > 0)
	{
		*ptr1=ch;
		ptr1++;
		iNo--;
	}

	return ptr2;
}

int StringLen(char *ptr)
{
	char *ptr1=ptr;

	while(*ptr != '\0')
	{
		ptr++;
	}
	return ptr-ptr1;
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
//		Output	:	laaaa
//
///////////////////////////////////////////////////////////////////////////////