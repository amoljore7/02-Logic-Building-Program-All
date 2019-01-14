////////////////////////////////////////////////////////////////////////////////////////////////
//
//	17.Write a program which accepts two file names from user and compare contents of 
//	those files by using library functions.
//
/////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:		CompareFiles
//
//		Input			:		File name 1 , File name 2
//
//		Returns			:		integer ,returns 1 if both file are same otherwise return 0
//
//		Description		:		This function accept two file names  and compare by using 
//								library functions.
//
//////////////////////////////////////////////////////////////////////////////////////////////////
int CompareFiles( char *cPtr1 , char *cPtr2 )
{
	//create FILE pointer
	FILE *fp1=NULL;
	FILE *fp2=NULL;

	char ch1='\0';
	char ch2='\0';

	//open 1st file 
	fp1=fopen(cPtr1,"r");
	
	//open 2nd file
	fp2=fopen(cPtr2,"r");

	//check whether file is open or not.
	if(fp1 == NULL || fp2 == NULL)
	{
		printf("\n Problem in reading or writing a file.\n");
		exit(1);
	}

	while(1)
	{
		//read single characters from both the files.
		ch1 = fgetc(fp1);
		ch2 = fgetc(fp2);
		
		//check whether end of file is reached or not.
		if(ch1 == EOF || ch2 == EOF)
		{
			break;
		}
		
		//compare both characters if they are not same then return 0
		if( ch1 != ch2 )
		{
			return 0;
		}
	}
	//if any of the file is not reached at the end it means files are different.
	if(ch1 != EOF || ch2 != EOF)
	{
		return 0;
	}

	return 1;
	fcloseall();
}
	
int main()
{
	//create char array to store file name
	char fname1[20]={'\0'};
	char fname2[20]={'\0'};
	int result=0;

	//accept file names from user
	printf("\n Enter first file name with extension => ");
	scanf("%s",fname1);

	printf("\n Enter second file name with extension => ");
	scanf("%s",fname2);

	result=CompareFiles(fname1,fname2);

	if(result == 1)
	{
		printf("\n Both files are same.\n");
	}
	else
	{
		printf("\n Files are not same.\n");
	}
	return 0;
}
////////////////////////////////////////////////////////////////////////////////
//
//		Input	:	Enter first file name with extension => demo1.txt
//					Enter second file name with extension => demo2.txt
//
//		Output	:	Both files are same. 
//
////////////////////////////////////////////////////////////////////////////////