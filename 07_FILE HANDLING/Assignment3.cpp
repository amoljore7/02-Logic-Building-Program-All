////////////////////////////////////////////////////////////////////////////////////////////////
//
//	3. Write a program which accept file name from user and display contents of file by 
//	using library functions. 
//
/////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:		DisplayFileContents
//
//		Input			:		File name
//
//		Returns			:		void
//
//		Description		:		This function accept file name and display contents
//								of file.
//
//////////////////////////////////////////////////////////////////////////////////////////////////
void DisplayFileContents( char *cPtr)
{
	//create FILE pointer
	FILE *fp=NULL;
	char Buffer[1024]={'\0'};


	//open file by using fopen()
	fp=fopen(cPtr,"r");
	
	//check whether file is open or not.
	if(fp == NULL)
	{
		printf("\n Can not open file.\n");
		exit(1);
	}

	printf("\n File contets are => \n ");
	
	while(fgets(Buffer,1024,fp) != NULL)	//we can also use fread() function for reading contents of file.
	{
		printf("%s",Buffer);
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

	//calling function for printing contents of file.
	DisplayFileContents(fname);

	return 0;
}
////////////////////////////////////////////////////////////////////////////////
//
//		Input	:	Enter file name with extension => prasad.txt
//
//		Output	:	File contents are => my name is prasad. 
//
////////////////////////////////////////////////////////////////////////////////