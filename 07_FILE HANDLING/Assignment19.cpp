////////////////////////////////////////////////////////////////////////////////////////////////
//
//	19.Write a program which accept file name from user and accept contents from user and 
//  write that contents in file by using library functions. 
//
/////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:		WriteToFile
//
//		Input			:		File name 
//
//		Returns			:		void
//
//		Description		:		This function accept file name and accept contents from user
//								and  write that contents in file by using library functions. 
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////
void WriteToFile( char *cPtr1 )
{
	//create FILE pointer
	FILE *fp1=NULL;
	char arr[50]={'\0'};

	//open 1st file 
	fp1=fopen(cPtr1,"w");
	
	//check whether file is open or not.
	if(fp1 == NULL)
	{
		printf("\n Problem in reading or writing a file.\n");
		exit(1);
	}

	printf("\n Enter the contents to write :\n ");
	
	fflush(stdin);
	
	while(strlen(gets(arr)) > 0)
	{
		fputs(arr,fp1);
		fputs("\n",fp1);
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
	
	WriteToFile(fname1);

	return 0;
}

////////////////////////////////////////////////////////////////////////////////
//
//		Input	:	Enter file name with extension =>	demo.txt
//					Enter the contents of to write =>	djfndjf
//														djjdngjngfdng
//														dfjgfgfgjfgjfjgnjgj
//
//
//		Output	:	File copied successfully..	 
//
////////////////////////////////////////////////////////////////////////////////