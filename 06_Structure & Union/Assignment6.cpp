////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	6. Write a program which contains structures as car (name, type , price, color),
//	Sales_Person (name, designation, pointer to car structure), Car_Showroom(Name, address, Brand name, 
//	pointer to Sales_Person structure). Accept name of sales person from user and print all information
//	of cars which are sold by that sales person. 
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//we use enum for the color of the car
//like this we can use enum for the type of car also.
typedef enum{red,black,white,silver}Color;


//structor for car
#pragma pack(1)
typedef struct
{
	char name[20];
	char type[20];
	double price;
	Color color;

}Car,*pCar;

//structor for sales person
#pragma pack(1)
typedef struct
{
	char name[30];
	char designation[30];
	
	//this is pointer to car structor.
	pCar cptr[2];

}Sales_Person,*pSales_Person;

//structor for showroom.
#pragma pack(1)
typedef struct
{
	char name[30];
	char address[40];
	char brand_name[30];

	//this is pointer to Sales_Person structor
	pSales_Person sptr[2];

}ShowRoom,*pShowRoom;

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:	InitializeShowroom
//
//		Input			:	Address of ShowRoom structor
//
//		Returns			:	void
//
//		Description		:	This function accept address of showroom structor and initialize
//							it with some hardquoted values.
//
///////////////////////////////////////////////////////////////////////////////////////////////////
void InitializeShowroom(pShowRoom ptr) //ptr is pointer of pShowRoom type
{
	strcpy(ptr->name,"Deccan Honda");
	strcpy(ptr->address,"Karve_Road");
	strcpy(ptr->brand_name,"Honda");

	//initialize sales person structor by the sptr pointer which is member of showroom structor,
	//here we allocate dynamic memory.
	ptr->sptr[0]=(pSales_Person)malloc(sizeof(Sales_Person));

	//check whether the memory is allocated or not
	if(ptr->sptr[0] == NULL)
	{
		printf("\n memory is not allocated for sales person.");
		exit(1);
	}

	//initialize the sales_person structor
	strcpy(ptr->sptr[0]->name,"Prasad Kamble");
	strcpy(ptr->sptr[0]->designation,"Manager");

	//allocate memory for 1st car structor
	ptr->sptr[0]->cptr[0]=(pCar)malloc(sizeof(Car));

	//check whether memory is allocated or not
	if(ptr->sptr[0]->cptr[0] == NULL)
	{
		printf("\n memory is not allocated for car.");
		exit(2);
	}

	//initialize 1st car structor
	strcpy(ptr->sptr[0]->cptr[0]->name,"Honda City");
	strcpy(ptr->sptr[0]->cptr[0]->type,"Sedan");
	ptr->sptr[0]->cptr[0]->price=1000000;
	ptr->sptr[0]->cptr[0]->color=red;

	//allocate memory for 2nd car structor
	ptr->sptr[0]->cptr[1]=(pCar)malloc(sizeof(Car));

	//check whether memory is allocated or not
	if(ptr->sptr[0]->cptr[1] == NULL)
	{
		printf("\n memory is not allocated for car.");
		exit(2);
	}

	//initialize 2nd car structor
	strcpy(ptr->sptr[0]->cptr[1]->name,"Honda Civic");
	strcpy(ptr->sptr[0]->cptr[1]->type,"Hybrid");
	ptr->sptr[0]->cptr[1]->price=2000000;
	ptr->sptr[0]->cptr[1]->color=white;

}

/////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:	DisplayInfo
//
//		Input			:	Address of ShowRoom structor
//
//		Returns			:	void
//
//		Description		:	This function accept address of showroom structor and accept name
//							of sales person and display the info of cars sold by this sales
//							person.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

void DisplayInfo(pShowRoom showptr,char *ptr)
{
	int i=0,j=0;
	int result=0;

	if(showptr == NULL || ptr == NULL || showptr->sptr == NULL || showptr->sptr[0]->cptr == NULL)
	{
		return;
	}

	//display info of cars sold by the sales person.
	for(i=0;i<1;i++)
	{
		for(j=0;j<2;j++)
		{
			if(strcmp(showptr->sptr[i]->name,ptr) == 0)
			{
				printf("\n Car Name is => %s ",showptr->sptr[i]->cptr[j]->name);
				printf("\n Car Name is => %s ",showptr->sptr[i]->cptr[j]->type);
				printf("\n Car Name is => %lf",showptr->sptr[i]->cptr[j]->price);
				printf("\n Car Name is => %d ",showptr->sptr[i]->cptr[j]->color);
				printf("\n");
				result=1;
			}
		}
	}

	if(!result)
	{
		printf("\nInformation is not available.\n");
	}

}
int main()
{
	ShowRoom showroom;

	//zero out the memory of showroom structor variable
	memset(&showroom,0,sizeof(showroom));

	char name[20];
	
	
	//call to function to initialize the above structors with some hard quoted values.
	//here we initialize only one structor , if you want to initialize more than one structor
	//then create array of ShowRoom structor  variable and pass this array to following function
	InitializeShowroom(&showroom);

	printf("\n Enter Sales person name to display information about car sold => ");
	scanf("%[^\n]",name);

	//call to function for display info of car sold by sales person
	DisplayInfo(&showroom,name);

	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Input  1	:	Enter Sales person name to display information about car sold => shrikant mundhe
//
//		Output 1	:	Information is not available.
//
//		Input 2		:	Enter Sales person name to display information about car sold => Prasad Kamble
//
//					Car Name is => Honda City
//					Car Name is => Sedan
//					Car Name is => 1000000.000000
//					Car Name is => 0
//
//					Car Name is => Honda Civic
//					Car Name is => Hybrid
//					Car Name is => 2000000.000000
//					Car Name is => 2
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////