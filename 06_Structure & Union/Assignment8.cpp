//////////////////////////////////////////////////////////////////////////////////////////////////
//
//	8. Write a program which creates a structure to specify data of customers in bank. 
//	The data to be stored is: Account number, name, and balance in account. Write a function 
//	withdrawal and deposited by using above structure. 
//
//////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#pragma pack(1)
//creating structor which stores info of bank customers
typedef struct 
{
	int Account_No;
	char name[30];
	double balance;
}Customer,*pCustomer;

#pragma pack(1)
typedef struct
{
	char Bank_Name[30];
	char Bank_Address[30];

	//this is pointer to customer structor
	pCustomer cptr[3];

}Bank,*pBank;

///////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:	InitializeBankRecords
//
//		Input			:	Address of Bank structor
//
//		Returns			:	int
//
//		Description		:	This function accept address of bank structor and
//							initialize it with some hardquoted values.
//
////////////////////////////////////////////////////////////////////////////////////////

int InitializeBankRecords(pBank ptr)
{
	int i=0;
	
	if(ptr == NULL)
	{
		return 0;
	}

	//initialize bank structor with some hardquoted values.
	strcpy(ptr->Bank_Name,"SBI");
	strcpy(ptr->Bank_Address,"Shivajinagar");
	
	//initialize 1st customer structor

	ptr->cptr[0]=(pCustomer)malloc(sizeof(Customer));
	if(ptr->cptr[0]==NULL)
	{
		printf("\n memory not allocted.\n");
		return 0;
	}

	ptr->cptr[0]->Account_No=1001;

	strcpy(ptr->cptr[0]->name,"Prasad Kamble");

	ptr->cptr[0]->balance=15000;
	
	//initialize 2nd customer structor

	ptr->cptr[1]=(pCustomer)malloc(sizeof(Customer));
	if(ptr->cptr[1]==NULL)
	{
		printf("\n memory not allocted.\n");
		return 0;
	}

	ptr->cptr[1]->Account_No=1002;

	strcpy(ptr->cptr[1]->name,"Shrikant Mundhe");

	ptr->cptr[1]->balance=25000;	
	
	//initialize 3rd customer structor

	ptr->cptr[2]=(pCustomer)malloc(sizeof(Customer));
	if(ptr->cptr[2]==NULL)
	{
		printf("\n memory not allocted.\n");
		return 0;
	}

	ptr->cptr[2]->Account_No=1002;

	strcpy(ptr->cptr[2]->name,"Rohan Kayangude");

	ptr->cptr[2]->balance=35000; 

	return 1;
}
////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:	DepositeAmount
//
//		Input			:	Address of bank structor , account number
//
//		Returns			:	int
//
//		Description		:	This function deposite the amount in a particular customer
//							account.
//
/////////////////////////////////////////////////////////////////////////////////////////////

int DepositeAmount(pBank ptr,int acc_no,double Amount)
{
	int i=0;

	if(ptr == NULL)
	{
		printf("\n Can not able to deposite amount.\n");
		return 0;
	}

	for(i=0;i<3;i++)
	{
		if(ptr->cptr[i]->Account_No == acc_no)
		{
			ptr->cptr[i]->balance = ptr->cptr[i]->balance + Amount;
	
			printf("\nAmount deposited successfully.");
			printf("\nCustomer \"%s\" has \"%lf\" amount in his account.",ptr->cptr[i]->name,ptr->cptr[i]->balance);
	
			return 1;
		}
	}
	


	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name	:	WithdrawAmount
//
//		Input			:	Address of bank structor , account number
//
//		Returns			:	int
//
//		Description		:	This function withdraw the amount in a particular customer
//							account.
//
/////////////////////////////////////////////////////////////////////////////////////////////
int WithdrawAmount(pBank ptr,int acc_no,double Amount)
{
	int i=0;
	int result=0;

	if(ptr == NULL)
	{
		printf("\n Can not able to deposite amount.\n");
		return 0;
	}

	for(i=0;i<3;i++)
	{
		if(ptr->cptr[i]->Account_No == acc_no)
		{
			ptr->cptr[i]->balance = ptr->cptr[i]->balance - Amount;
	
			printf("\nAmount withdraw successfully.");
			printf("\nCustomer \"%s\" has \"%lf\" amount in his account.",ptr->cptr[i]->name,ptr->cptr[i]->balance);
	
			
			return 1;
		}
	}
	return 0;
}
int main()
{
	//create structor variable bank structor
	Bank b1;

	int Choice=0;
	int Account_No=0;
	double Amount=0.0;
	
	//zero out the structor
	memset(&b1,0,sizeof(b1));

	//call to function to initialize bank structor
	InitializeBankRecords(&b1);

	//show menu to user 
	do
	{
		printf("\n 1.Deposite amount.");
		printf("\n 2.Withdraw amount.");
		printf("\n 3.Exit");

		//accepting choice from user to perform operation.
		printf("\n Enter your choice => ");
		scanf("%d",&Choice);

		//call to specific function depend upon choice entered by the user
		if(Choice == 1)
		{
			printf("\nEnter account number in which do you want to deposite amount => ");
			scanf("%d",&Account_No);
	
			printf("\nEnter amount do you want to deposite  => ");
			scanf("%lf",&Amount);
	
			DepositeAmount(&b1,Account_No,Amount);
		}
		else if(Choice == 2)
		{
			printf("\nEnter account number from which do you want to withdraw amount => ");
			scanf("%d",&Account_No);
	
			printf("\nEnter amount do you want to withdraw  => ");
			scanf("%lf",&Amount);
	
			WithdrawAmount(&b1,Account_No,Amount);
		}
		else if(Choice == 3)
		{
			exit(0);
		}
		else
		{
			printf("\nPlease enter valid choice.\n");
			exit(2);
		}


	}while(Choice != 3);


	printf("\n");
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Input	:	Select which operation do you want to perform.
//
//					1.Deposite amount.
//					2.Withdraw amount.
//					3.Exit
//
//					Enter your choice => 1
//
//					Enter account number in which do you want to deposite amount => 1001
//
//					Enter amount do you want to deposite  => 10000
//
//		Output	:	Amount deposited successfully.
//
//					Customer "Prasad Kamble" has "25000.000000" amount in his account.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////