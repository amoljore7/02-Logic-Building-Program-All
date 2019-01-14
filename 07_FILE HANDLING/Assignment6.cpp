////////////////////////////////////////////////////////////////////////////////////////////////
//
//	6. Write a program which accept file name from user and count number of occurrences of 
//	characters in small case and in capital case by using library functions.  
//
/////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>


/////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:		CountOccurOfChar
//
//		Input			:		File name 
//
//		Returns			:		void
//
//		Description		:		This function accept file name and count number of occurrences
//								of characters in small case and in capital case by using lib.
//								functions.
//
//////////////////////////////////////////////////////////////////////////////////////////////////
void CountOccurOfChar( char *cPtr)
{
	//create FILE pointer
	FILE *fp=NULL;
	
	int SmallChar=0;
	int CapChar=0;

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
		if( ch >= 65 && ch <= 90)
		{
			CapChar++;
		}
		else if( ch >= 97 && ch <= 122 )
		{
			SmallChar++;
		}
	}
	printf("\n");
	fclose(fp);

	printf("\n Small characters => %d , Capital characters => %d \n",SmallChar,CapChar);
}
int main()
{
	//create char array to store file name
	char fname[20]={'\0'};

	//accept file name from user
	printf("\n Enter file name with extension => ");
	scanf("%s",fname);


	//calling function.
	CountOccurOfChar(fname);
	
	return 0;
}
////////////////////////////////////////////////////////////////////////////////
//
//		Input	:	Enter file name with extension => prasad.txt
//
//		Output	:	Small characters => 14 , Captial characters => 6 
//
////////////////////////////////////////////////////////////////////////////////