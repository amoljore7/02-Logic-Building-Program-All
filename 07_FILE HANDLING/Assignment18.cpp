////////////////////////////////////////////////////////////////////////////////////////////////
//
//	18.Write a program which accept file name from user and create one new file and copy 
//	alternate lines from source file in that new file by using library functions. 
//
/////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:		CopyAltLines
//
//		Input			:		File name 
//
//		Returns			:		void
//
//		Description		:		This function accept file name and create one new file and copy 
//								alternate lines from source file in that new file by using library functions.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CopyAltLines( char *cPtr1 )
{
	//create FILE pointer
	FILE *fp1=NULL;
	FILE *fp2=NULL;

	char ch='\0';

	//open 1st file 
	fp1=fopen(cPtr1,"r");
	
	//open 2nd file
	fp2=fopen("Demo.txt","w");

	//check whether file is open or not.
	if(fp1 == NULL || fp2 == NULL)
	{
		printf("\n Problem in reading or writing a file.\n");
		exit(1);
	}
	
	while( ( ch = fgetc(fp1) ) != EOF )
	{
		fputc(ch,fp2);
	
		//if new line character found then we are going to skip next line,for this while loop is used to find next newline character.
		if(ch=='\n')
		{
			ch=fgetc(fp1);
			while(ch != '\n' && ch != EOF)
			{
				ch=fgetc(fp1);
			}
		}
	}
	printf("\n File copied successfully..");
	fcloseall();
}
	
int main()
{
	//create char array to store file name
	char fname1[20]={'\0'};
	
	//accept file names from user
	printf("\n Enter file name with extension => ");
	scanf("%s",fname1);

	CopyAltLines(fname1);

	return 0;
}
////////////////////////////////////////////////////////////////////////////////
//
//		Input	:	Enter file name with extension => prasad.txt
//
//		Output	:	File copied successfully..
//
////////////////////////////////////////////////////////////////////////////////