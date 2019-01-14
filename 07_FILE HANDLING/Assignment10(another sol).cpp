//in this program we read the file by using fread() function.

////////////////////////////////////////////////////////////////////////////////////////////////
//
//	10.Write a program which accept file name from user and print number of occurrence 
//	of “include” word in that file. 
//
/////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:		PrintOccurrence
//
//		Input			:		File name
//
//		Returns			:		void
//
//		Description		:		This function accept file name and print number of occurrence
//								of "include" word in that file.
//
//////////////////////////////////////////////////////////////////////////////////////////////////
void PrintOccurrence( char *cPtr )
{
	//create FILE pointer
	FILE *fp=NULL;
	int count=0;
	
	char buffer[1024];
	
	//ptr1 stores address of "include"string,and the meaning of following line is
	//ptr1 is pointer to "constant" string.hence we can not able to change single char of this string.
	char *ptr1="include";
	
	char *ptr2=ptr1;
	int i=0;

	//open file by using fopen()
	fp=fopen(cPtr,"r");
	
	//check whether file is open or not.
	if(fp == NULL)
	{
		printf("\n Can not open file.\n");
		exit(1);
	}

	

	//here we use fgets() which reads file line by line,when file is end then it returns NULL
	while(fread(buffer,1,sizeof(buffer),fp))
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
			//here we check our ptr2 is reached at the end of string "include",if it is reached at the end of string
			//then it means that word "include"is found in the file.
			//If word is found in the file then we increment count by 1,and assign starting address of string to ptr2
			//for further checking.
			if(*ptr2=='\0')
			{
				count++;
				ptr2=ptr1;
			}
		}
		i=0;
	}
	
	printf("\n");
	fclose(fp);

	printf("\nNumber of occurrences of \"include\" word is => %d\n",count);
}
int main()
{
	//create char array to store file name
	char fname[20]={'\0'};

	//accept file name from user
	printf("\n Enter file name with extension => ");
	scanf("%s",fname);

	PrintOccurrence(fname);

	return 0;
}
////////////////////////////////////////////////////////////////////////////////
//
//		Input	:	Enter file name with extension => prasad.txt
//
//		Output	:	Number of occurrences of "include" word is => 3   
//
////////////////////////////////////////////////////////////////////////////////