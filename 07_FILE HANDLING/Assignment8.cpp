////////////////////////////////////////////////////////////////////////////////////////////////
//
//	8. Write a program which accept file name from user and print two characters after 
//	every fifty bytes by using library functions.   
//
/////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:		PrintTwoChar
//
//		Input			:		File name
//
//		Returns			:		void
//
//		Description		:		This function accept file name and prints two characters after every
//								fifty bytes by using library functions.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////
void PrintTwoChar( char *cPtr)
{
	//create FILE pointer
	FILE *fp=NULL;
	
	int iNo=1;

	char ch;
	
	//open file by using fopen()
	fp=fopen(cPtr,"r");
	
	//check whether file is open or not.
	if(fp == NULL)
	{
		printf("\n Can not open file.\n");
		exit(1);
	}

	while(iNo<=2)
	{
	
		ch = fgetc(fp);
		
		if( ch == EOF )
		{
			break;
		}
		printf("%c",ch);
		iNo++;

		if( iNo == 3 )
		{
			int retval=fseek(fp,48,SEEK_CUR);
			if( retval == -1 )
			{
				break;
			}
			iNo=1;
		}
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

	//strcat(fname,".txt");

	//calling function for printing two char after every fifty bytes.
	PrintTwoChar(fname);

	return 0;
}
////////////////////////////////////////////////////////////////////////////////
//
//		Input	:	Enter file name with extension => demo.txt
//
//		Output	:	//wiin
//					ec ahiiot  I,& i
//	
////////////////////////////////////////////////////////////////////////////////