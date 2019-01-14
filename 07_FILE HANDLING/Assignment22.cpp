////////////////////////////////////////////////////////////////////////////////////////////////
//
//	22.Write a program which accept executable file name from user and create same 
//	executable on “D” drive with name “demo.exe”.  
//
/////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
//#include<string.h>

////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name	:	CreateExeFile
//
//	Input			:	File name
//
//	Returns			:   void
//
//	Description		:	This function accept executable file name from user and create same 
//						executable on “D” drive with name “demo.exe”.
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void CreateExeFile(char *ptr)
{
	FILE *fp1=NULL;
	FILE *fp2=NULL;
	char ch;

	fp1=fopen(ptr,"rb");
	fp2=fopen("D:\\demo1.exe","wb+");

	if(fp1==NULL || fp2 == NULL)
	{
		printf("\n can not open file.");
		exit(1);
	}

	//problem ahe????? file tayar hotiye pn execute hot nahi.

	while((ch=fgetc(fp1))!=EOF)
	{
		fputc(ch,fp2);
	}
	
	/*char str[50];
	while(fgets(str,50,fp1) != NULL)
	{
		fputs(str,fp2);
	}
	*/
	printf("\n File created successfully.");
	
	printf("\n");
	fcloseall();
}
	
int main()
{
	char fname[30]={'\0'};

	//accept file name from user.
	printf("\n Enter executable file name  => ");

	//strcat(fname,".exe");

	scanf("%s",fname);

	//display information of the students.
	CreateExeFile(fname);

	return 0;
}
////////////////////////////////////////////////////////////////////////////////
//
//		Input	:	 Enter file name with extension => demo.exe
//
//		Output	:	 File created successfully.
//
////////////////////////////////////////////////////////////////////////////////