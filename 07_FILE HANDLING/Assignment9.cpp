////////////////////////////////////////////////////////////////////////////////////////////////
//
//	9. Write a program which accept file name from user and print its size by using
//	library functions.(without calling stat function)  
//
/////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:		DisplayFileSize
//
//		Input			:		File name
//
//		Returns			:		int
//
//		Description		:		This function accept file name and display size
//								of file.
//
//////////////////////////////////////////////////////////////////////////////////////////////////
int DisplayFileSize( char *cPtr )
{
	//create FILE pointer
	FILE *fp=NULL;

	//we take filesize as a long int because return type of ftell() is long int.
	long int filesize=0;

	//open file by using fopen()
	fp=fopen(cPtr,"r");
	
	//check whether file is open or not.
	if(fp == NULL)
	{
		printf("\n Can not open file.\n");
		exit(1);
	}

	if( fseek(fp,0,SEEK_END) == -1 )
	{
		printf("\n Unable to perform action.");
		exit(1);
	}

	//ftell() returns the current file pointer position.here file pointer points to ending offset.
	filesize=ftell(fp);

	//	we can count size of file by using following logic also.
	//  char ch;
	//	while( ( ch= fgetc(fp) ) != EOF )
	//	{
	//		filesize++;
	//	}
	//	return filesize-1;
	//

	printf("\n");
	fclose(fp);

	return filesize;
}
int main()
{
	//create char array to store file name
	char fname[20]={'\0'};

	//accept file name from user
	printf("\n Enter file name with extension => ");
	scanf("%s",fname);

	//calling function for printing size of file.
	printf("\n File size is %d bytes.\n",DisplayFileSize(fname));

	return 0;
}
////////////////////////////////////////////////////////////////////////////////
//
//		Input	:	Enter file name with extension => prasad.txt
//
//		Output	:	File size is 25 bytes.  
//
////////////////////////////////////////////////////////////////////////////////