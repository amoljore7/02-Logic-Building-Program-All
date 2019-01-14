/////////////////////////////////////////////////////////////////////////////////////////////////
//
//	5.  Write a program which contains student structure and pass that structure to a function 
//	and modify marks of that student and return the modified structure. 
//
/////////////////////////////////////////////////////////////////////////////////////////////////


#include<stdio.h>
#include<string.h>

#pragma pack(1)

//creating structor which contain info of student
//here we use typedef for the structor Student
typedef struct 
{
	char Stud_Name[30];
	char Stud_Address[40];
	int std;
	char div;
	char Parents_Name[30];
	long int Contact_No;
	int Total_marks;
}Student;

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:	ModifyMarks
//
//		Input			:	Address of structor
//
//		Returns			:	Address of structor
//
//		Description		:	This fuction accept address of student structor and modify the
//							marks of student and returns the address of structor.
//
//////////////////////////////////////////////////////////////////////////////////////////////////

Student* ModifyMarks(Student *ptr)
{
	if(ptr == NULL)
	{
		return NULL;	
	}

	ptr->Total_marks=499;
	
	return ptr;
}

int main()
{
	//creating array structor variable for storing info of 5 students.
	Student stud,*ptr;

	//zero out the stud variable before its use by using memset().
	memset(&stud,0,sizeof(stud));

	//info of 1st student.
	strcpy(stud.Stud_Name,"prasad kamble");
	strcpy(stud.Stud_Address,"shirdi");
	stud.std=12;
	stud.div='A';
	strcpy(stud.Parents_Name,"Chandrashekhar kamble");
	stud.Contact_No=274345;
	stud.Total_marks=495;
	
	printf("\nTotal marks of student is => %d",stud.Total_marks);

	ptr=ModifyMarks(&stud);

	printf("\nAfter modification marks of student is => %d\n",ptr->Total_marks);

	return 0;

}
/*
Output:

Total marks of student is => 495
After modification marks of student is => 499

*/