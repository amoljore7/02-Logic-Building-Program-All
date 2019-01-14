//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	2. Write a program which contains structure which is used to maintain 
//	information about date (date, month, and year). Accept two dates from user and 
//	display the difference between those two dates. 
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)

//create structor to store info about date

typedef struct 
{
	int day;
	int month;
	int year;
}Date1,*Date2;

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:	DisplayDifference
//
//		Input			:	Address of structor , Address of structor 
//
//		Returns			:	void
//
//		Description		:	This function accepts two dates and display difference between these two
//							dates.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////

void DisplayDifference(Date2 ptr1,Date2 ptr2)
{
	int daydiff,monthdiff,yeardiff;

	if(ptr1 == NULL || ptr2 == NULL)
	{
		return;
	}
	
	printf("\n The entered date are :\n");
	printf("\n First date is => %d/%d/%d",ptr1->day,ptr1->month,ptr1->year);
	printf("\n Second date is => %d/%d/%d",ptr2->day,ptr2->month,ptr2->year);
	printf("\n");

	if(ptr1->year > ptr2->year)
	{
		yeardiff=ptr1->year-ptr2->year;
	}
	else
	{
		yeardiff=ptr2->year-ptr1->year;
	}
	//calculate difference between months
	if(ptr1->month > ptr2->month)
	{
		monthdiff=ptr1->month-ptr2->month;
	}
	else
	{
		monthdiff=ptr2->month-ptr1->month;
	}
	//calculate difference between days
	if(ptr1->day > ptr2->day)
	{
		daydiff=ptr1->day-ptr2->day;
	}
	else
	{
		daydiff=ptr2->day-ptr1->day;
	}
	printf("\n The difference between two dates is => %d years %d months %d days.\n",yeardiff,monthdiff,daydiff);
	
}

int main()
{
	Date1 d1,d2;

	//accepts two dates from user
	printf("\n Enter first date in the format(dd//mm//yy) => ");
	scanf("%d%d%d",&d1.day,&d1.month,&d1.year);
	
	printf("\n Enter second date in the format(dd//mm//yy) => ");
	scanf("%d%d%d",&d2.day,&d2.month,&d2.year);

	//check for valid date
	if(d1.day > 31 || d2.day > 31 || d1.month >12 || d2.month > 12)
	{
		printf("\n please enter valid date .\n");
		exit(1);
	}

	//call to function to display difference between two dates
	DisplayDifference(&d1,&d2);
	
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////
//
//		Input	:	 Enter first date in the format(dd//mm//yy) => 16
//				 9
//				 2014
//
//				 Enter second date in the format(dd//mm//yy) => 12
//				 7
//				 2005
//
//		Output	:	The entered date are :
//
//				First date is => 16/9/2014
//				Second date is => 12/7/2005
//
//				The difference between two dates is => 9 years 2 months 4 days.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////