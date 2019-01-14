////////////////////////////////////////////////////////////////////////////////////////////////
//
//	7. Write a program which accept file name from user and count number of white spaces, 
//	tabs, new lines by using library functions.  
//
/////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>


///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:		Count
//
//		Input			:		File name
//
//		Returns			:		void
//
//		Description		:		This function accept file name and and count number of white spaces, 
//								tabs, new lines by using library functions.  
//
///////////////////////////////////////////////////////////////////////////////////////////////////////
void Count( char *cPtr)
{
	//create FILE pointer
	FILE *fp=NULL;
	
	char ch;

	//create local variables to count occurrences of white spaces,tabs,newlines.
	int whitespaces=0;
	int tabs=0;
	int newlines=0;


	//open file by using fopen()
	fp=fopen(cPtr,"r");
	
	//check whether file is open or not.
	if(fp == NULL)
	{
		printf("\n Can not open file.\n");
		exit(1);
	}

	while( ( ch = fgetc(fp) ) != EOF )
	{
		if( ch == ' ' )
		{
			whitespaces++;
		}
		if( ch == '\t' )
		{
			tabs++;
		}
		if( ch == '\n' )
		{
			newlines++;
		}
	}
	printf("\n");
	fclose(fp);

	printf("\nNumber of white spaces are => %d\n",whitespaces);
	printf("\nNumber of tabs are => %d\n",tabs);
	printf("\nNumber of new lines are => %d\n",newlines);
}
int main()
{
	//create char array to store file name
	char fname[20]={'\0'};

	//accept file name from user
	printf("\n Enter file name with extension => ");
	scanf("%s",fname);

	//strcat(fname,".txt");

	//calling function for printing number of white spaces,tabs,newlines in the file.
	Count(fname);

	return 0;
}
////////////////////////////////////////////////////////////////////////////////
//
//		Input	:	Enter file name with extension => prasad.txt
//
//		Output	:	Number of white spaces are => 2
//					Number of tabs are => 2
//					Number of new lines are => 0
//	
////////////////////////////////////////////////////////////////////////////////