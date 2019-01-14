////////////////////////////////////////////////////////////////////////////////////////////////
//
//	11.Write a program which accept file name from user and count number of words and lines,
//	characters from that file. 
//
/////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:		Count
//
//		Input			:		File name
//
//		Returns			:		void
//
//		Description		:		This function accept file name count number of words and lines,
//								characters from that file.
//
//////////////////////////////////////////////////////////////////////////////////////////////////
void Count( char *cPtr )
{
	//create FILE pointer
	FILE *fp=NULL;

	char ch='\0';

	int NumOfChar=0;
	int words=1;
	int lines=1;

	//open file by using fopen()
	fp=fopen(cPtr,"r");
	
	//check whether file is open or not.
	if(fp == NULL)
	{
		printf("\n Can not open file.\n");
		exit(1);
	}

	while( ( ch = fgetc(fp) ) != EOF )
	{
		if(ch == ' ' || ch == '\t')
		{
			words++;
		}
		if(ch == '\n')
		{
			lines++;

			if((ch=fgetc(fp)) !=EOF)
			{
				words++;
				NumOfChar++;
			}
		}
		NumOfChar++;
	}

	printf("\n");
	fclose(fp);

	printf("\n Number of words in the file => %d ",words);
	printf("\n Number of lines in the file => %d ",lines);
	printf("\n Number of characters in the file => %d ",NumOfChar);
}
int main()
{
	//create char array to store file name
	char fname[20]={'\0'};

	//accept file name from user
	printf("\n Enter file name with extension => ");
	scanf("%s",fname);

	//calling function.
	Count(fname);

	return 0;
}
////////////////////////////////////////////////////////////////////////////////
//
//		Input	:	Enter file name with extension => prasad.txt
//
//					Number of words in the file => 20
//					Number of lines in the file => 6
//					Number of characters in the file => 95 Press
//
////////////////////////////////////////////////////////////////////////////////