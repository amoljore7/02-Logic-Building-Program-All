/////////////////////////////////////////////////////////////////////////////////
//
//	10. Write a program which contains structure as company (name,
//	foundation year, name of CTO, number of employees, address,
//	array of pointers which holds information of employees), employee
//	(name, address, experience, designation, pointer to project
//	structure), project (project name, team size, technology used,
//	starting date, project duration).
//	
//	Accept name of project from user and print information if all
//	employees working on that project.
//
//////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum{C,CPP,JAVA,WIN32_SDK}Technology;

#pragma pack(1)
typedef struct
{
	int day : 5;
	int month : 4;
	int year : 12;
}Date;

# pragma pack(1)
typedef struct
{
	char name[30];
	int team_size;
	Date Starting_date;
	Technology tech;
	int duration;

}Project,*pProject;

#pragma pack(1)
typedef struct
{
	char name[30];
	char address[50];
	int experience;
	char designation[20];
	pProject pro;

}Employee,*pEmployee;


#pragma pack(1)
typedef struct
{
	char Name_Of_Company[50];
	Date Foundation_date;
	char Name_Of_CTO[30];
	int Number_Of_Employees;
	char Address[50];
	
	//here we take array of 3employee thats why we initialized only 3 employess data in Initifo().
	pEmployee emp[3];

}Company,*pCompany;



/////////////////////////////////////////////////////////////////////////////////
//
//	Function name	:	Initinfo
//
//	Input			:	Address of Company structor
//
//	Returns			:	int
//
//	Description		:	This function initialize the company structor.
//
///////////////////////////////////////////////////////////////////////////////////

int InitInfo(pCompany cptr)
{
	if(cptr == NULL)
	{
		return 0;
	}
	//assign company name
	strcpy(cptr->Name_Of_Company,"Tech_M");

	//assign address
	strcpy(cptr->Address,"Karve_Road");

	//assign CTO name
	strcpy(cptr->Name_Of_CTO,"Mahesh Shinde");

	//assign number ofemployees
	cptr->Number_Of_Employees=5;

	//assign date
	cptr->Foundation_date.day=11;
	cptr->Foundation_date.month=4;
	cptr->Foundation_date.year=1980;

	//assign memroy for 1st Employee structor variable
	cptr->emp[0]=(pEmployee)malloc(sizeof(Employee));

	//check whether memory is allocated or not
	if(cptr->emp[0] == NULL)
	{
		printf("\nUnable to allocate memory for employee.\n");
		return 0;
	}

	//initialize the fields of 1st emp structor
	strcpy(cptr->emp[0]->name,"Prasad Kamble");
	
	strcpy(cptr->emp[0]->address,"Pashan");
	
	strcpy(cptr->emp[0]->designation,"Senior_Eng");

	cptr->emp[0]->experience=13;

	//allocate memory for project structor
	cptr->emp[0]->pro=(pProject)malloc(sizeof(Project));

	//check whether memory is allocated or not
	if(cptr->emp[0]->pro == NULL)
	{
		printf("\nUnable to allocate memory for project.\n");
		return 0;
	}
	//initialize project info for the 1st employee.
	strcpy(cptr->emp[0]->pro->name,"LAN MONITORING");
	cptr->emp[0]->pro->duration=2;
	cptr->emp[0]->pro->team_size=2;
	cptr->emp[0]->pro->Starting_date.day=11;
	cptr->emp[0]->pro->Starting_date.month=5;
	cptr->emp[0]->pro->Starting_date.year=2013;
	cptr->emp[0]->pro->tech=JAVA;
	
	//assign memroy for 2nd Employee structor variable
	cptr->emp[1]=(pEmployee)malloc(sizeof(Employee));

	//check whether memory is allocated or not
	if(cptr->emp[1] == NULL)
	{
		printf("\nUnable to allocate memory for employee.\n");
		return 0;
	}

	//initialize 2nd emp structor
	strcpy(cptr->emp[1]->name,"Shrikant Mundhe");
	
	strcpy(cptr->emp[1]->address,"Katraj");
	
	strcpy(cptr->emp[1]->designation,"Senior_Eng");

	cptr->emp[1]->experience=12;

	//allocate memory for project structor
	cptr->emp[1]->pro=(pProject)malloc(sizeof(Project));

	//check whether memory is allocated or not
	if(cptr->emp[1]->pro == NULL)
	{
		printf("\nUnable to allocate memory for project.\n");
		return 0;
	}
	//initialize project info for the 2nd employee.

	strcpy(cptr->emp[1]->pro->name,"LAN MONITORING");
	cptr->emp[1]->pro->duration=2;
	cptr->emp[1]->pro->team_size=2;
	cptr->emp[1]->pro->Starting_date.day=11;
	cptr->emp[1]->pro->Starting_date.month=5;
	cptr->emp[1]->pro->Starting_date.year=2013;

	cptr->emp[1]->pro->tech=JAVA;
	
	//assign memroy for 2nd Employee structor variable
	cptr->emp[2]=(pEmployee)malloc(sizeof(Employee));

	//check whether memory is allocated or not
	if(cptr->emp[2] == NULL)
	{
		printf("\nUnable to allocate memory for employee.\n");
		return 0;
	}
	//initialize the fields of 3rd emp structor
	strcpy(cptr->emp[2]->name,"Rohan Kayangude");
	
	strcpy(cptr->emp[2]->address,"Katraj");
	
	strcpy(cptr->emp[2]->designation,"Senior_Eng");

	cptr->emp[2]->experience=15;

	//allocate memory for project structor
	cptr->emp[2]->pro=(pProject)malloc(sizeof(Project));

	//check whether memory is allocated or not
	if(cptr->emp[2]->pro == NULL)
	{
		printf("\nUnable to allocate memory for project.\n");
		return 0;
	}
	//initialize project info for the 3rd employee.

	strcpy(cptr->emp[2]->pro->name,"LAN MONITORING");
	cptr->emp[2]->pro->duration=2;
	cptr->emp[2]->pro->team_size=2;
	cptr->emp[2]->pro->Starting_date.day=11;
	cptr->emp[2]->pro->Starting_date.month=5;
	cptr->emp[2]->pro->Starting_date.year=2013;
	cptr->emp[2]->pro->tech=JAVA;
	
	return 1;
}

//////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name	:	DisplayInfo
//
//	Input			:	Address of company structor,address of string
//
//	Returns			:	integer
//
//	Description		:	This function accept project name from user and
//						displays the info of project if all the employess are
//						working on same project.
//
//////////////////////////////////////////////////////////////////////////////////////
int DisplayInfo(pCompany cptr,char *ptr)
{
	int i=0;
	if(cptr == NULL || ptr == NULL)
	{
		printf("\nUnable to display project info.");
		return 0;
	}

	for(i=0;i<3;i++)
	{
		if(strcmp(cptr->emp[i]->pro->name,ptr) != 0)
		{
			printf("\nMismatch found.\n");
			return 0;
		}
	}

	//Displaying project info
	printf("\nProject name is => %s.",cptr->emp[0]->pro->name);
	printf("\nProject duration is => %d years.",cptr->emp[0]->pro->duration);
	printf("\nProject team size is => %d.",cptr->emp[0]->pro->team_size);
	printf("\nStarting Date is => %d/%d/%d.",cptr->emp[0]->pro->Starting_date.day,cptr->emp[0]->pro->Starting_date.day,cptr->emp[0]->pro->Starting_date.year);
	if(cptr->emp[0]->pro->tech == 0)
	{
		printf("\nTechnology used => C\n");
	}
	else if(cptr->emp[0]->pro->tech == 1)
	{
		printf("\nTechnology used => CPP\n");
	}
	else if(cptr->emp[0]->pro->tech == 2)
	{
		printf("\nTechnology used => JAVA\n");
	}
	else
	{
		printf("\nTechnology used => WIN32_SDK\n");
	}





	return 1;
}
int main()
{
	//creating structor variable of Company
	Company company;
	char pname[20];

	//zero out the memory of structor
	memset(&company,0,sizeof(company));

	printf("\nEnter project name => ");
	scanf("%[^\n]",pname);

	
	InitInfo(&company);
	
	
	DisplayInfo(&company,pname);
	
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////
//
//	Input	:	Enter project name => LAN MONITORING
//
//	Output  :	Project name is => LAN MONITORING.
//				Project duration is => 2 years.
//				Project team size is => 2.
//				Starting Date is => 11/11/2013.
//				Technology used => JAVA
//
////////////////////////////////////////////////////////////////////////////////////