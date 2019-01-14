////////////////////////////////////////////////////////////////////////////////////////////////
//
//	2. Write a program which accept file name from user and print its 
//	last ten characters by using library functions. 
//
/////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
//#include<string.h>

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:		PrintLastTenChar
//
//		Input			:		File name
//
//		Returns			:		void
//
//		Description		:		This function accept file name and print last ten
//								characters from that file.
//
//////////////////////////////////////////////////////////////////////////////////////////////////
void PrintLastTenChar( char *cPtr)
{
	//create FILE pointer
	FILE *fp=NULL;
	char ch;

	//open file by using fopen()
	fp=fopen(cPtr,"r");
	
	//check whether file is open or not.
	if(fp == NULL)
	{
		printf("\n Can not open file.\n");
		exit(1);
	}

	
	//here we are using fseek(),to reach at the req.offset.
	// we can also write => fseek(fp,-10,2); because SEEK_END macro has value 2.
	// here we can use lseek system call.
	
	//check whether fseek() function is execute successfully or not.
	//on success fseek() function returns 0 , otherwise returns -1.
	if(fseek(fp,-10,SEEK_END) == -1)
	{
		printf("\nThere is no enough charactes in the file to seek from end.\n");
		exit(1);
	}
	
	printf("\n Last ten characters are => ");
	
	while((ch=fgetc(fp))!=EOF)
	{
		printf("%c",ch);
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

	//calling function for printing last ten characters of file.
	PrintLastTenChar(fname);

	return 0;
}
////////////////////////////////////////////////////////////////////////////////
//
//		Input	:	Enter file name with extension => prasad.txt
//
//		Output	:	Last ten characters are => ad kamble.
//
////////////////////////////////////////////////////////////////////////////////