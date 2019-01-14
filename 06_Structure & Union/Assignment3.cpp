/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	3. Write a program which contains student structure (name, address, standard, division, 
//	marks of five subjects, name of parents, contact number) and pass that structure to a function 
//	and print that structure.  
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////


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

}Student;


//////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:	DisplayEmpInfo
//
//		Input			:	Address of structor
//
//		Returns			:	integer on success return 1 otherwise return 0
//
//		Description		:	This function accept address of student structor and display
//							its information.
//
//////////////////////////////////////////////////////////////////////////////////////////////////

int DisplayInfo(Student *ptr)
{
	int i=0;
	int j=0;

	if(ptr == NULL)
	{
		return 0;
	}

	for(i=0;i<5;i++)
	{
		printf("\nName of student is => %s",ptr->Stud_Name);
		printf("\nAddress of student is => %s",ptr->Stud_Address);
		printf("\nStandard of student is => %d",ptr->std);
		
		//here div is will be print in integer,if we have to print in 
		//a proper manner then we have to use "switch"statement or if-else ladder.
		printf("\nDivision of student is => %d",ptr->div);
		printf("\nParent Name of student is => %s",ptr->Parents_Name);
		printf("\nContact number of parent is => %ld",ptr->Contact_No);
		
		printf("\nMarks of 5 subjects are => ");
		for(j=0;j<5;j++)
		{
			printf("%d\t",ptr->marks[j]);
		}
		printf("\n");
		j=0;
		ptr++;
	
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
	stud[1].marks[4]=89;

	//info of 3rd student.
	strcpy(stud[2].Stud_Name,"shrikant mundhe");
	strcpy(stud[2].Stud_Address,"shirdi");
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
	stud[2].marks[4]=88;

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
	stud[3].marks[4]=88;

	//info of 5th student.
	strcpy(stud[4].Stud_Name,"lalit munawat");
	strcpy(stud[4].Stud_Address,"shirdi");
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



	//we can pass structor to any function by following 3 ways.
	//1.we can pass each structor element one by one to function.
	//2.we can pass whole structor to function.
	//3.we can pass simply address of sturctor to function.

	//here we pass address of structor to DisplayInfo() function.
	DisplayInfo(stud);

	return 0;
}

/*

Output:
				
Name of student is => prasad kamble
Address of student is => shirdi
Standard of student is => 12
Division of student is => 0
Parent Name of student is => Chandrashekhar kamble
Contact number of parent is => 274345
Marks of 5 subjects are => 87   89      91      97      88

Name of student is => rohan kayangude
Address of student is => satara
Standard of student is => 12
Division of student is => 1
Parent Name of student is => manohar kayangude
Contact number of parent is => 274345
Marks of 5 subjects are => 77   99      95      97      89

Name of student is => shrikant mundhe
Address of student is => shirdi
Standard of student is => 12
Division of student is => 0
Parent Name of student is => sunil mundhe
Contact number of parent is => 274345
Marks of 5 subjects are => 87   89      91      97      88

Name of student is => dagadu jogi
Address of student is => latur
Standard of student is => 11
Division of student is => 2
Parent Name of student is => manohar jogi
Contact number of parent is => 274345
Marks of 5 subjects are => 87   89      91      97      88

Name of student is => lalit munawat
Address of student is => shirdi
Standard of student is => 12
Division of student is => 3
Parent Name of student is => uttamchand munawat
Contact number of parent is => 274345
Marks of 5 subjects are => 87   89      91      97      88

*/