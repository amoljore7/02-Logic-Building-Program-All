////////////////////////////////////////////////////////////////////////////////////////////////
//
//	5. Write a program which accept file name from user and count number of occurrences of 
//	vowels (a, e, i, o, u) by using library functions.  
//
/////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:		CountVowels
//
//		Input			:		File name 
//
//		Returns			:		int
//
//		Description		:		This function accept file name and count number of occurrences
//								of vowels by using lib.functions.
//
//////////////////////////////////////////////////////////////////////////////////////////////////
int CountVowels( char *cPtr)
{
	//create FILE pointer
	FILE *fp=NULL;
	int count=0;
	char ch;

	//open file by using fopen()
	fp=fopen(cPtr,"r");
	
	//check whether file is open or not.
	if(fp == NULL)
	{
		printf("\n Can not open file.\n");
		exit(1);
	}

	while((ch=fgetc(fp)) != EOF)
	{
		if( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
		{
			count++;
		}
	}
	printf("\n");
	fclose(fp);

	return count;
}
int main()
{
	//create char array to store file name
	char fname[20]={'\0'};
	int count=0;
	
	//accept file name from user
	printf("\n Enter file name with extension => ");
	scanf("%s",fname);


	//calling function for countiong number of vowels in the file.
	count=CountVowels(fname);
	if(count)
	{
		printf("\n Number of vowels is => %d\n",count);
	}
	else
	{
		printf("\n vowels are not found in the file.\n");
	}
	return 0;
}
////////////////////////////////////////////////////////////////////////////////
//
//		Input	:	Enter file name with extension => prasad.txt
//
//		Output	:	Number of vowels is => 5 
//
////////////////////////////////////////////////////////////////////////////////