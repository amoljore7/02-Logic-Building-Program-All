///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	4. Write a program which contains student structure (name, address, standard, division, marks of 
//	five subjects, name of parents, contact number) and create array of 50 elements of that student 
//	structure. 
//	1. Pass that array to function and print all information of student having maximum marks. 
//	2. Pass that array to function and print all information of student having minimum marks. 
//	3.Pass that array to function and print all information of such students whose address field contains “Karve Road”. 
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include<stdio.h>
#include<string.h>

//here we are going to use enum for the division of student.
typedef enum {A,B,C,D}division;

#pragma pack(1)

//creating structor which contain info of student
//here we use typedef for the structor Student
typedef struct 
{
	char Stud_Name[30];
	char Stud_Address[40];
	int std;
	division div;
	int marks[5];
	char Parents_Name[30];
	long int Contact_No;
	int Total_Marks;

}Student;


//////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:	DisplayMaxMarks
//
//		Input			:	Address of structor
//
//		Returns			:	integer on success return 1 otherwise return 0
//
//		Description		:	This function accept address of student structor and display
//							all info of such student which have max marks.
//
//////////////////////////////////////////////////////////////////////////////////////////////////

int DisplayMaxMarks(Student *ptr1)
{
	// i is used for traverse array of structor, j is used for traverse array of marks.
	int i=0,j=0;
	
	//max is used to store max marks
	int max=0;

	//ptr2 is used to display the info of such a student which have max marks,
	//here ptr2 is needed because our ptr1 pointer is reached at the end of array of structor while finding record with max marks.
	Student *ptr2=NULL;

	if(ptr1 == NULL)
	{
		return 0;
	}

	for(i=0;i<5;i++)
	{
		if( max < ptr1->Total_Marks )
		{
			max=ptr1->Total_Marks;
			ptr2=ptr1;
		}
		ptr1++;
	}

	printf("\nThe info of student which having max marks is as follow.\n");

	printf("\nName of student is => %s",ptr2->Stud_Name);
	printf("\nAddress of student is => %s",ptr2->Stud_Address);
	printf("\nStandard of student is => %d",ptr2->std);
		
	//here div is will be print in integer,if we have to print in 
	//a proper manner then we have to use "switch"statement or if-else ladder.
	
	printf("\nDivision of student is => %d",ptr2->div);
	printf("\nParent Name of student is => %s",ptr2->Parents_Name);
	printf("\nContact number of parent is => %ld",ptr2->Contact_No);
		
	printf("\nMarks of 5 subjects are => ");
	for(j=0;j<5;j++)
	{
		printf("%d\t",ptr2->marks[j]);
	}
	printf("\nTotal marks of student is => %d",ptr2->Total_Marks);
	printf("\n");
	
	return 1;
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:	DisplayMinMarks
//
//		Input			:	Address of structor
//
//		Returns			:	integer on success return 1 otherwise return 0
//
//		Description		:	This function accept address of student structor and display
//							all info of such student which have min marks.
//
//////////////////////////////////////////////////////////////////////////////////////////////////

int DisplayMinMarks(Student *ptr1)
{
	// i is used for traverse array of structor, j is used for traverse array of marks.
	int i=0,j=0;
	
	//min is used to store max marks
	int min=0;

	//ptr2 is used to display the info of such a student which have min marks,
	//here ptr2 is needed because our ptr1 pointer is reached at the end of array of structor while finding record with min marks.
	Student *ptr2=NULL;

	if(ptr1 == NULL)
	{
		return 0;
	}

	//first assign total marks of 1st student to min for further comparision
	min=ptr1->Total_Marks;

	//assign ptr1 to ptr2 , it is very imp if the we are getting min marks.
	ptr2=ptr1;

	ptr1++;


	for(i=1;i<5;i++)
	{
		if( min > ptr1->Total_Marks )
		{
			min=ptr1->Total_Marks;
			ptr2=ptr1;
		}
		ptr1++;
	}

	printf("\nThe info of student which having min marks is as follow.\n");

	printf("\nName of student is => %s",ptr2->Stud_Name);
	printf("\nAddress of student is => %s",ptr2->Stud_Address);
	printf("\nStandard of student is => %d",ptr2->std);
		
	//here div is will be print in integer,if we have to print in 
	//a proper manner then we have to use "switch"statement or if-else ladder.
	
	printf("\nDivision of student is => %d",ptr2->div);
	printf("\nParent Name of student is => %s",ptr2->Parents_Name);
	printf("\nContact number of parent is => %ld",ptr2->Contact_No);
		
	printf("\nMarks of 5 subjects are => ");
	for(j=0;j<5;j++)
	{
		printf("%d\t",ptr2->marks[j]);
	}
	printf("\nTotal marks of student is => %d",ptr2->Total_Marks);
	printf("\n");
	
	return 1;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:	DisplayByAddress
//
//		Input			:	Address of structor
//
//		Returns			:	integer on success return 1 otherwise return 0
//
//		Description		:	This function accept address of student structor and display
//							all info of such student which has address "Karve Road"
//
//////////////////////////////////////////////////////////////////////////////////////////////////

int DisplayByAddress(Student *ptr1)
{
	// i is used for traverse array of structor, j is used for traverse array of marks.
	int i=0,j=0;

	if(ptr1 == NULL)
	{
		return 0;
	}

	for(i=0;i<5;i++)
	{
		if( strcmp(ptr1->Stud_Address,"Karve Road") == 0)
		{
			printf("\nName of student is => %s",ptr1->Stud_Name);
			printf("\nAddress of student is => %s",ptr1->Stud_Address);
			printf("\nStandard of student is => %d",ptr1->std);
			
			//here div is will be print in integer,if we have to print in 
			//a proper manner then we have to use "switch"statement or if-else ladder.
	
			printf("\nDivision of student is => %d",ptr1->div);
			printf("\nParent Name of student is => %s",ptr1->Parents_Name);
			printf("\nContact number of parent is => %ld",ptr1->Contact_No);
		
			printf("\nMarks of 5 subjects are => ");
			for(j=0;j<5;j++)
			{
				printf("%d\t",ptr1->marks[j]);
			}
			printf("\nTotal marks of student is => %d",ptr1->Total_Marks);
			printf("\n");
		}
		ptr1++;
	}
	return 1;
}

int main()
{
	//creating array structor variable for storing info of 50 students.
	Student stud[50];

	//zero out the stud variable before its use by using memset().
	memset(&stud,0,sizeof(stud));

	//info of 1st student.
	strcpy(stud[0].Stud_Name,"prasad kamble");
	strcpy(stud[0].Stud_Address,"shirdi");
	stud[0].std=12;
	stud[0].div=A;
	strcpy(stud[0].Parents_Name,"Chandrashekhar kamble");
	stud[0].Contact_No=274345;
	
	//store marks of 5 subjects.
	//for marks of 5 subject we take array of 5 integers,
	//so we have to following syntax

	stud[0].marks[0]=87;
	stud[0].marks[1]=89;
	stud[0].marks[2]=91;
	stud[0].marks[3]=97;
	stud[0].marks[4]=88;

	stud[0].Total_Marks=452;

	//info of 2nd student.
	strcpy(stud[1].Stud_Name,"rohan kayangude");
	strcpy(stud[1].Stud_Address,"satara");
	stud[1].std=12;
	stud[1].div=B;
	strcpy(stud[1].Parents_Name,"manohar kayangude");
	stud[1].Contact_No=274345;

	//store marks of 5 subjects.
	//for marks of 5 subject we take array of 5 integers,
	//so we have to following syntax

	stud[1].marks[0]=77;
	stud[1].marks[1]=99;
	stud[1].marks[2]=95;
	stud[1].marks[3]=97;
	stud[1].marks[4]=95;

	stud[1].Total_Marks=463;
	
	//info of 3rd student.
	strcpy(stud[2].Stud_Name,"shrikant mundhe");
	strcpy(stud[2].Stud_Address,"Karve Road");
	stud[2].std=12;
	stud[2].div=A;
	strcpy(stud[2].Parents_Name,"sunil mundhe");
	stud[2].Contact_No=274345;

	//store marks of 5 subjects.
	//for marks of 5 subject we take array of 5 integers,
	//so we have to following syntax

	stud[2].marks[0]=87;
	stud[2].marks[1]=89;
	stud[2].marks[2]=91;
	stud[2].marks[3]=97;
	stud[2].marks[4]=90;

	stud[2].Total_Marks=454;

	//info of 4th student.
	strcpy(stud[3].Stud_Name,"dagadu jogi");
	strcpy(stud[3].Stud_Address,"latur");
	stud[3].std=11;
	stud[3].div=C;
	strcpy(stud[3].Parents_Name,"manohar jogi");
	stud[3].Contact_No=274345;

	//store marks of 5 subjects.
	//for marks of 5 subject we take array of 5 integers,
	//so we have to following syntax

	stud[3].marks[0]=87;
	stud[3].marks[1]=89;
	stud[3].marks[2]=91;
	stud[3].marks[3]=97;
	stud[3].marks[4]=93;

	stud[3].Total_Marks=455;

	//info of 5th student.
	strcpy(stud[4].Stud_Name,"lalit munawat");
	strcpy(stud[4].Stud_Address,"Karve Road");
	stud[4].std=12;
	stud[4].div=D;
	strcpy(stud[4].Parents_Name,"uttamchand munawat");
	stud[4].Contact_No=274345;

	//store marks of 5 subjects.
	//for marks of 5 subject we take array of 5 integers,
	//so we have to following syntax

	stud[4].marks[0]=87;
	stud[4].marks[1]=89;
	stud[4].marks[2]=91;
	stud[4].marks[3]=97;
	stud[4].marks[4]=88;

	stud[4].Total_Marks=453;

	//we can pass structor to any function by following 3 ways.
	//1.we can pass each structor element one by one to function.
	//2.we can pass whole structor to function.
	//3.we can pass simply address of sturctor to function.

	//call to function to print record with max marks
	DisplayMaxMarks(stud);

	//call to function to print record with min marks
	DisplayMinMarks(stud);
	
	//call to function to print record with address=karve road
	DisplayByAddress(stud);

	return 0;
}