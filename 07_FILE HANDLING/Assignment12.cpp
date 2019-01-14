////////////////////////////////////////////////////////////////////////////////////////////////
//
//	12.Write a program which accept file name from user and accept word from user and print 
//	number of occurrence of that word in that file also print offset at which that word occur.  
//
/////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:		PrintOccurrence
//
//		Input			:		File name
//
//		Returns			:		void
//
//		Description		:		This function accept file name and word and print number of occurrence of 
//								that word in that file also print offset at which that word occur.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PrintOccurrence( char *fname , char *ptr1 )
{
	//create FILE pointer
	FILE *fp=NULL;
	int count=0;
	
	//array is created for store line return by fgets()
	char arr[90];
	
	char *ptr2=ptr1;
	
	int i=0;
	int j=0;

	//open file by using fopen()
	fp=fopen(fname,"r");
	
	//check whether file is open or not.
	if(fp == NULL)
	{
		printf("\n Can not open file.\n");
		exit(1);
	}

	

	//here we use fgets() which reads file line by line,when file is end then it returns NULL
	while(fgets(arr,90,fp) != NULL)
	{
		//inner while loop is used to check occurrence of "include" word in the line which read by fgets() function.
		//simply it is code for finding substring "include" in the file.
		while(arr[i]!='\0')
		{
			if(arr[i] == *ptr2)
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
				count++;
				//here \"\" is an escape seq used to print double quote.
				printf("\n%d occurrence of \"%s\" word is found at %d offset.\n",count,ptr1,((j-strlen(ptr1))));
				ptr2=ptr1;
			}
		}
		i=0;
	}
	
	printf("\n");
	fclose(fp);

	
}
int main()
{
	//create char array to store file name
	char fname[20]={'\0'};
	char word[20]={"\0"};

	//accept file name from user
	printf("\n Enter file name with extension => ");
	scanf("%s",fname);

	printf("\n Enter word to find occurrences => ");
	scanf("%s",word);

	PrintOccurrence(fname,word);

	return 0;
}
////////////////////////////////////////////////////////////////////////////////
//
//		Input	:	Enter file name with extension => prasad.txt
//
//					Enter word to find occurrences => prasad
//
//		Output	:	1 occurrence of "prasad" word is found at 11 offset.
//
//					2 occurrence of "prasad" word is found at 30 offset.
//
//					3 occurrence of "prasad" word is found at 49 offset.
//
//					4 occurrence of "prasad" word is found at 68 offset.
/
	/////////////////////////////////////////////////////////////////////////////////