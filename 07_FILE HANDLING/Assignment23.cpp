////////////////////////////////////////////////////////////////////////////////////////////////
//
//	23.Write a program which accept file name from user and create new encrypted file.
//	Apply decryption logic also to generate original file.   
//
/////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
//#include<string.h>

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name	:	CreateEncryptedFile
//
//	Input			:	File name
//
//	Returns			:   void
//
//	Description		:	This function accept file name from user and create new encrypted file.
//						and apply decryption logic also to generate original file.  
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CreateEncryptedFile(char *ptr)
{
	FILE *fp1=NULL;
	FILE *fp2=NULL;
	char ch;

	fp1=fopen(ptr,"r");
	fp2=fopen("Demo.txt","w");

	if(fp1==NULL || fp2 == NULL)
	{
		printf("\n can not open file.");
		exit(1);
	}

	while((ch=fgetc(fp1))!=EOF)
	{
		ch=ch+32;
		fputc(ch,fp2);
	}
	
	printf("\n File created successfully.");
	
	printf("\n");
	fcloseall();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name	:	DisplayOriginalFile
//
//	Input			:	nothing
//
//	Returns			:   void
//
//	Description		:	This function displays the contents of file before decryption and after
//						performing decryption operation.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DisplayOriginalFile()
{
	FILE *fp=NULL;

	char ch;

	fp=fopen("Demo.txt","r");
	if(fp == NULL)
	{
		printf("\n Unable to open file.");
		exit(1);
	}

	printf("\n Before decryption file contents are => ");
	while((ch=fgetc(fp))!=EOF)
	{
		printf("%c",ch);
	}

	rewind(fp);
	printf("\n After decryption file contents are => ");
	while((ch=fgetc(fp))!=EOF)
	{
		ch=ch-32;
		printf("%c",ch);
	}

	printf("\n");
	fclose(fp);
}
	
int main()
{
	char fname[30]={'\0'};

	//accept file name from user.
	printf("\n Enter file name with extension => ");

	//strcat(fname,".txt");

	scanf("%s",fname);

	//display information of the students.
	CreateEncryptedFile(fname);

	DisplayOriginalFile();

	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Input	:	  Enter file name with extension => prasad.txt
//
//					  File created successfully.
//
//					  Before decryption file contents are => לÖ@Äüלא@כפ@ÉÆüפüה@ןüלימאN
//					
//					  After decryption file contents are => my name is prasad kamble.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////