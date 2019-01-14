////////////////////////////////////////////////////////////////////////////////////////////////
//
//	1. Write a program which accept file name from user and print its 
//	first five characters by using library functions. 
//
/////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
//#include<string.h>

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:		PrintFirstFiveChar
//
//		Input			:		File name
//
//		Returns			:		void
//
//		Description		:		This function accept file name and print first five
//								characters from that file.
//
//////////////////////////////////////////////////////////////////////////////////////////////////
void PrintFirstFiveChar( char *cPtr)
{
	//create FILE pointer
	FILE *fp=NULL;
	int iNo=1;
	char ch;

	//open file by using fopen()
	fp=fopen(cPtr,"r");
	
	//check whether file is open or not.
	if(fp == NULL)
	{
		printf("\n Can not open file.\n");
		exit(1);
	}

	printf("\n First five characters are => ");
	while(iNo <= 5)
	{
		ch=fgetc(fp);

		if(ch == EOF)
		{
			break;
		}
		printf("%c",ch);
		iNo++;
	}
	printf("\n");
	fclose(fp);
}
int main()
{
	//create char array to store file name
	char fname[20]={'\0'};

	//accept file name from user
	printf("\n Enter file name with extension => ");
	scanf("%s",fname);

	//strcat(fname,".txt");

	//calling function for printing first five characters of file.
	PrintFirstFiveChar(fname);

	return 0;
}
////////////////////////////////////////////////////////////////////////////////
//
//		Input	:	Enter file name with extension => prasad.txt
//
//		Output	:	First five characters are => my na
//
////////////////////////////////////////////////////////////////////////////////