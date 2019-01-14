////////////////////////////////////////////////////////////////////////////////////////////////
//
//	15.Write a program which accept file name from user and copy the contents in 
//	some other file in reverse order.
//
/////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:		CopyFile
//
//		Input			:		File name
//
//		Returns			:		void
//
//		Description		:		This function accept file name and and create one new file and copy 
//								the contents in that new file in reverse order using library functions.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////
void CopyFile( char *cPtr )
{
	//create FILE pointer
	FILE *fp1=NULL;
	FILE *fp2=NULL;

	//open file by using fopen()
	fp1=fopen(cPtr,"r+");
	
	//create new file for writing contents.
	fp2=fopen("demo.txt","w");

	//check whether file is open or not.
	if(fp1 == NULL || fp2 == NULL)
	{
		printf("\n Problem in reading or writing a file.\n");
		exit(1);
	}

	if(fseek(fp1,-3,SEEK_END) == -1)
	{
		printf("\n Unable to continue.");
		fcloseall();
		exit(2);
	}


	fpos_t pos;
	fgetpos(fp1,&pos);
	
	while(pos >= 0)
	{
		fputc(fgetc(fp1),fp2);
		pos=pos-1;
		fsetpos(fp1,&pos);
	}
	
	printf("\nFile copied successfully...\n");
	
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
//					contents of prasad.txt file => my name is prasad.
//					contents of demo.txt file => .dasarp si eman ym
//
////////////////////////////////////////////////////////////////////////////////