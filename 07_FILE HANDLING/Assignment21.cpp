////////////////////////////////////////////////////////////////////////////////////////////////
//
//	21.Write a program which accept file name from user which contains information of student.
//	Print all information of such a student whose name is “Vibhav” and rollno is 5 
//	by using library functions. 
//
/////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student
{
	int rollno;
	char name[30];
	char address[30];
	int marks1;
	int marks2;
	int marks3;

};

////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name	:	DisplayInfo
//
//	Input			:	File name
//
//	Returns			:   void
//
//	Description		:	This function Print all information of such a student whose name 
//						is “Vibhav” and rollno is 5 by using library functions.
//
//////////////////////////////////////////////////////////////////////////////////////////////////

void DisplayInfo(char *ptr)
{
	FILE *fp=NULL;
	struct Student StudInfo;


	fp=fopen(ptr,"rb");

	if(fp == NULL)
	{
		printf("\n can not open file.");
		exit(1);
	}

	while(!feof(fp))
	{
		fread(&StudInfo,sizeof(Student),1,fp);
		
		if(feof(fp))
		{
			break;
		}

		if( (strcmp(StudInfo.name,"Vibhav") == 0 ) && StudInfo.rollno == 5)
		{
			printf("\n Roll number => %d",StudInfo.rollno);
			printf("\n Name => %s",StudInfo.name);
			printf("\n Address => %s",StudInfo.address);
			printf("\n Marks of 1st subjects => %d",StudInfo.marks1);
			printf("\n Marks of 2nd subjects => %d",StudInfo.marks2);
			printf("\n Marks of 3rd subjects => %d",StudInfo.marks3);
		}
	}
	
	printf("\n");
	fclose(fp);
}
	
int main()
{
	char fname[30]={'\0'};

	//accept file name from user.
	printf("\n Enter file name with extension => ");
	scanf("%s",fname);

	//display information of the students.
	DisplayInfo(fname);

	return 0;
}
////////////////////////////////////////////////////////////////////////////////
//
//		Input	:	 Enter file name with extension => StudentInfo.txt
//
//		Output	:	Roll number => 5
//					Name => Vibhav
//					Address => nagar
//					Marks of 1st subjects => -872401098
//					Marks of 2nd subjects => -872400583
//					Marks of 3rd subjects => -872400839
//
////////////////////////////////////////////////////////////////////////////////