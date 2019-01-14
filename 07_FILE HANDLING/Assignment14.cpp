////////////////////////////////////////////////////////////////////////////////////////////////
//
//	14.Write a program which accept file name from user and create one new file and copy the 
//	contents in that new file by using library functions. 
//
/////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:		CopyFile
//
//		Input			:		File name
//
//		Returns			:		void
//
//		Description		:		This function accept file name and and create one new file and copy 
//								the contents in that new file by using library functions.
//
//////////////////////////////////////////////////////////////////////////////////////////////////
void CopyFile( char *cPtr )
{
	//create FILE pointer
	FILE *fp1=NULL;
	FILE *fp2=NULL;

	char ch='\0';

	//open file by using fopen()
	fp1=fopen(cPtr,"r");
	
	//create new file for writing contents.
	fp2=fopen("Demo.txt","w");

	//check whether file is open or not.
	if(fp1 == NULL || fp2 == NULL)
	{
		printf("\n Problem in reading or writing a file.\n");
		exit(1);
	}

	//copy code
	while( ( ch = fgetc(fp1) ) != EOF )
	{
		fputc(ch,fp2);
	}

	
	printf("\n File copied successfully.\n");

	fcloseall();
	
}
int main()
{
	//create char array to store file name
	char fname[20]={'\0'};

	//accept file name from user
	printf("\n Enter file name with extension => ");
	scanf("%s",fname);

	CopyFile(fname);

	return 0;
}
////////////////////////////////////////////////////////////////////////////////
//
//		Input	:	Enter file name with extension => prasad.txt
//
//		Output	:	File copied successfully.  
//
////////////////////////////////////////////////////////////////////////////////