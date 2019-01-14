////////PROBLEM aheeeeeeeeeee

////////////////////////////////////////////////////////////////////////////////////////////////
//
//	13.Write a program which accept file name from user and reverse all occurrences of
//	“include” word in that file..  
//
/////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:		UpdateFile
//
//		Input			:		File name
//
//		Returns			:		void
//
//		Description		:		This function accept file name and reverse all occurrences of
//								“include” word in that file..
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void UpdateFile( char *fname )
{
	//create FILE pointer
	FILE *fp=NULL;
	
	//array is created for store line return by fgets()
	char buffer[80];
	memset(buffer,0,sizeof(buffer));
	
	char *ptr1="include";
	char *ptr2=ptr1;
	char *ptr3="edulcni";
	
	fpos_t pos;
	int i=0;
	int j=0;

	//open file by using fopen()
	fp=fopen(fname,"rb+");
	
	//check whether file is open or not.
	if(fp == NULL)
	{
		printf("\n Can not open file.\n");
		exit(1);
	}
	

	//here we use fgets() which reads file line by line,when file is end then it returns NULL
	while( fgets(buffer,80,fp) !=NULL )
	{
		//inner while loop is used to check occurrence of "include" word in the line which read by fgets() function.
		//simply it is code for finding substring "include" in the file.
		while(buffer[i]!='\0')
		{
			if(buffer[i] == *ptr2)
			{
				i++;
				ptr2++;
			}
			else if(ptr1 == ptr2)
			{
				i++;
			}
			else
			{
				ptr2=ptr1;
			}
			j++;
			
			if(*ptr2=='\0')
			{	
				printf("%d\t",j);
				pos=(j-strlen(ptr3));

				fsetpos(fp,&pos);

				while(*ptr3!='\0')
				{
					fputc(*ptr3,fp);
					ptr3++;
				}
				ptr3=ptr3-strlen(ptr3);
				


			//	fwrite(word,1,sizeof(word),fp);
				ptr2=ptr1;
			}
		}
		i=0;
	}
	
	printf("File updated successfully.");
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

	UpdateFile(fname);

	return 0;
}
////////////////////////////////////////////////////////////////////////////////
//
//		Input	:	Enter file name with extension => prasad.txt
//
//					Enter word to find occurrences => prasad
//
//		Output	:	File updated successfully.
//
/////////////////////////////////////////////////////////////////////////////////////