/////////////////////////////////////////////////////////////////////////////////////////////////
//
//	1. Write a program which contains structure for maintaining information such as name of
//	employee and its ID number. Accept that information from user and display it on screen. 
//
////////////////////////////////////////////////////////////////////////////////////////////////


#include<stdio.h>
#include<string.h>

//creating structor which contain name of employee and employee id
//here we use typedef for the structor Employee
typedef struct 
{
	int Emp_Id;
	char Emp_Name[20];
}Employee;


//////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:	DisplayEmpInfo
//
//		Input			:	Address of structor
//
//		Returns			:	integer on success return 1 otherwise return 0
//
//		Description		:	This function accept address of employee structor and display
//							its information.
//
//////////////////////////////////////////////////////////////////////////////////////////////////

int DisplayInfo(Employee *ptr)
{
	if(ptr == NULL)
	{
		return 0;
	}

	printf("\nID of employee is => %d",ptr->Emp_Id);
	printf("\nName of employee is => %s\n",ptr->Emp_Name);
	
	return 1;
}

int main()
{
	//create structor variable for storing info entered by the user.
	Employee emp;

	//zero out the emp variable before its use by using memset().
	memset(&emp,0,sizeof(emp));

	//accepting info from user.
	printf("\nEnter employee id => ");
	scanf("%d",&emp.Emp_Id);
	
	fflush(stdin);

	printf("\nEnter employee name => ");
	scanf("%[^\n]",&emp.Emp_Name);

	//we can pass structor to any function by following 3 ways.
	//1.we can pass each structor element one by one to function.
	//2.we can pass whole structor to function.
	//3.we can pass simply address of sturctor to function.

	//here we pass address of structor to DisplayInfo() function.
	DisplayInfo(&emp);

	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Input	:	Enter employee id => 1111
//					Enter employee name => prasad kamble
//
//		Output	:	ID of employee is => 1111
//					Name of employee is => prasad kamble
//
/////////////////////////////////////////////////////////////////////////////////////////////////