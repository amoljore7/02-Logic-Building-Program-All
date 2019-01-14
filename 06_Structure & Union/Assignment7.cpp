/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	7. Write a program which contains a structure to specify data of students given below : Roll number
//	name, department, course, year of joining. Write a function to print names of students who joined 
//	in particular year.  
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////


#include<stdio.h>
#include<string.h>



#pragma pack(1)

//creating structor which contain info of student
//here we use typedef for the structor Student
typedef struct 
{
	int Roll_NO;
	char Stud_Name[30];
	char Department[30];
	char Course[20];
	int Year_Of_Join;
}Student;


//////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:	DisplayStudInfo
//
//		Input			:	Address of structor
//
//		Returns			:	integer on success return 1 otherwise return 0
//
//		Description		:	This function accept address of student structor and display
//							display info of all students who joined course in particular year.
//
//////////////////////////////////////////////////////////////////////////////////////////////////

int DisplayInfo(Student *ptr,int year)
{
	int i=0;
	
	if(ptr == NULL)
	{
		return 0;
	}

	for(i=0;i<5;i++)
	{
		if(ptr->Year_Of_Join == year)
		{
			printf("\nName of student is => %s\n",ptr->Stud_Name);
			flag=1;
		}
		ptr++;
	}
	if(flag==0)
	{
		printf("\n No such student record found who joined course in a particular year.\n");
	}

	printf("\n");
	return 1;
}

int main()
{
	//creating array structor variable for storing info of 5 students.
	Student stud[5];

	//zero out the stud variable before its use by using memset().
	memset(&stud,0,sizeof(stud));

	//info of 1st student.
	stud[0].Roll_NO=1;
	strcpy(stud[0].Stud_Name,"prasad kamble");
	strcpy(stud[0].Department,"Computer science");
	strcpy(stud[0].Course,"MCA");
	stud[0].Year_Of_Join=2013;

	//info of 2nd student.
	stud[1].Roll_NO=2;
	strcpy(stud[1].Stud_Name,"rohan kayangude");
	strcpy(stud[1].Department,"Computer science");
	strcpy(stud[1].Course,"MCA");
	stud[1].Year_Of_Join=2012;
	
	//info of 3rd student.
	stud[2].Roll_NO=3;
	strcpy(stud[2].Stud_Name,"shrikant mundhe");
	strcpy(stud[2].Department,"Computer science");
	strcpy(stud[2].Course,"MCA");
	stud[2].Year_Of_Join=2013;

	
	//info of 4th student.
	stud[3].Roll_NO=4;
	strcpy(stud[3].Stud_Name,"ravindra dhere");
	strcpy(stud[3].Department,"Computer science");
	strcpy(stud[3].Course,"MCS");
	stud[3].Year_Of_Join=2014;

	
	//info of 5th student.
	stud[4].Roll_NO=1;
	strcpy(stud[4].Stud_Name,"lalit munawat");
	strcpy(stud[4].Department,"Computer science");
	strcpy(stud[4].Course,"MCA");
	stud[4].Year_Of_Join=2013;

	//we can pass structor to any function by following 3 ways.
	//1.we can pass each structor element one by one to function.
	//2.we can pass whole structor to function.
	//3.we can pass simply address of sturctor to function.

	//here we pass address of structor to DisplayInfo() function.
	DisplayInfo(stud,2013);

	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////
//
//		output	:	Name of student is => prasad kamble
//
//				Name of student is => shrikant mundhe
//
//				Name of student is => lalit munawat
//
////////////////////////////////////////////////////////////////////////////////////////