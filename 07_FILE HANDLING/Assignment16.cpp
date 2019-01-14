////////////////////////////////////////////////////////////////////////////////////////////////
//
//	16.Write a program which accepts two file names from user and copy contents of one file
//	at the end of second file by using library functions.  
//
/////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:		CopyFile
//
//		Input			:		File name 1 , File name 2
//
//		Returns			:		void
//
//		Description		:		This function accept two file names  and copy the contents at the 
//								end of another file by using library functions.
//
//////////////////////////////////////////////////////////////////////////////////////////////////
void CopyFile( char *cPtr1 , char *cPtr2 )
{
	//create FILE pointer
	FILE *fp1=NULL;
	FILE *fp2=NULL;

	char ch='\0';

	//open file by using fopen()
	fp1=fopen(cPtr1,"r");
	
	//create new file for writing contents.
	fp2=fopen(cPtr2,"a");

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
	char fname1[20]={'\0'};
	char fname2[20]={'\0'};

	//accept file names from user
	printf("\n Enter first file name with extension => ");
	scanf("%s",fname1);

	printf("\n Enter second file name with extension => ");
	scanf("%s",fname2);

	CopyFile(fname1,fname2);

	return 0;
}
////////////////////////////////////////////////////////////////////////////////
//
//		Input	:	Enter first file name with extension => demo1.txt
//					Enter second file name with extension => demo2.txt
//
//		Output	:	File copied successfully.  
//
////////////////////////////////////////////////////////////////////////////////