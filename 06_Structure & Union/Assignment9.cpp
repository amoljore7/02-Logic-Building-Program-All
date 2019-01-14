////////////////////////////////////////////////////////////////////////////////
//
//	9. Write a program which contains information about cricket team
//	(country name, coach name, pointer to coach structure, number of
//	players, array of player structure), player (name, type : batsman /
//	bowler, no of matches played, age , number of runs scored, number
//	of wicket taken, number of matches played), coach (name,
//	experience, country name).
//	
//	Write a function which accept cricket team structure from user and
//	print information of such players which plays maximum number of
//	matches.
//
//////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef enum{batsman,bowler}Player_Type;

//creating player structor 
#pragma pack(1)

typedef struct
{
	char Player_Name[30];
	Player_Type ptype;
	int Age;
	int Runs;
	int No_Of_Matches;
	int wicket;


}Player,*pPlayer;

//creating structor for coach
#pragma pack(1)
typedef struct
{
	char Coach_Name[30];
	int Experience;
	char Country_Name[20];

}Coach,*pCoach;

//create structor for storing info about circket team
#pragma pack(1)
typedef struct
{
	char Country_Name[20];
	
	int No_Of_Players;

	//this is pointer to player structor
	pPlayer pptr;
	//this is pointer to coach structor
	pCoach cptr;

}Team,*pTeam;

/////////////////////////////////////////////////////////////////////////
//
//	Function Name	:	InitInfo
//
//	Input			:	Array of Team sturctor
//
//	Returns			:	void
//
//	Description		:	This function initialize the team structor with
//						the info entered by the user.
//
//////////////////////////////////////////////////////////////////////////

void InitInfo(pTeam tptr)
{
	int i=0;
	
	if(tptr == NULL)
	{
		printf("\n Can not able to initialize team info.");
		exit(1);
	}

	/*printf("\nEnter country name => ");
	scanf("%[^\n]",tptr->Country_Name);
	fflush(stdin);
	*/
	printf("\nEnter number of players => ");
	scanf("%d",&tptr->No_Of_Players);
	fflush(stdin);
/*
	//allocate memory for coach structor
	tptr->cptr=(pCoach)malloc(sizeof(Coach));

	//check whether memory is allocated or not
	if(tptr->cptr == NULL)
	{
		printf("\nUnable to allocate memory.");
		exit(2);
	}

	printf("\nEnter coach name => ");
	scanf("%[^\n]",tptr->cptr->Coach_Name);
	fflush(stdin);

	printf("\nEnter country name of coach => ");
	scanf("%[^\n]",tptr->cptr->Country_Name);
	fflush(stdin);

	printf("\nEnter experience of coach => ");
	scanf("%d",&tptr->cptr->Experience);
	fflush(stdin);
	*/
	//allocate memory for player structor 
	//here we allocate memory dynamically for the number of player
	//b'coz we want declare player array with no of players entered by the user.
	
	tptr->pptr = (pPlayer)malloc(sizeof(Player) * tptr->No_Of_Players);
	if(tptr->pptr == NULL)
	{
		printf("\nUnable to allocate memory.");
		exit(3);
	}

	memset(tptr->pptr,0,(sizeof(Player) * tptr->No_Of_Players));

	printf("\nEnter info of %d players.\n",tptr->No_Of_Players);
/*
	for(i=0;i<tptr->No_Of_Players;i++)
	{
		printf("\nEnter info of %d player.",i+1);

		printf("\nEnter player name => ");
		scanf("%[^\n]",tptr->pptr->Player_Name);
		fflush(stdin);

		printf("\nEnter player type (0=batsman,1=bowler) => ");
		scanf("%d",&(tptr->pptr->ptype));

		printf("\nEnter player age => ");
		scanf("%d",&tptr->pptr->Age);

		printf("\nEnter player runs => ");
		scanf("%d",&tptr->pptr->Runs);

		printf("\nEnter number of matches played by player => ");
		scanf("%d",&tptr->pptr->No_Of_Matches);

		printf("\nEnter wicket taken by player => ");
		scanf("%d",&tptr->pptr->wicket);

		tptr->pptr++;
	}
*/	

}

void DisplayPlayerInfo(pTeam tptr)
{
	int i=0;
	int MaxMatches=0;

	//create another Team type pointer variable which is used to display player info with max matches
	pTeam tptr1=NULL;
	tptr1=tptr;

	if(tptr == NULL)
	{
		printf("\nUnable to display information of player.");
		exit(3);
	}

	for(i=0;i<tptr->No_Of_Players;i++)
	{
		if(MaxMatches < tptr->pptr->No_Of_Matches)
		{
			tptr1=tptr;
			tptr->pptr++;
		}
	}

	printf("\nThe info of player who played max matches is as follow.\n");
	
	printf("\nName of player is => %s",tptr1->pptr->Player_Name);
	printf("\nType of player is => %d",tptr1->pptr->ptype);
	printf("\nAge of player is => %d",tptr1->pptr->Age);
	printf("\nRuns scored by player is => %d",tptr1->pptr->Runs);
	printf("\nNumber of matches played by the player is => %d",tptr1->pptr->No_Of_Matches);
	printf("\nNumber of wicket taken by the player is => %d",tptr1->pptr->wicket);

	


}

int main()
{
	//creating structor variable for Team
	Team team;

	//zero out the memory of Team structor
	memset(&team,0,sizeof(team));

	//call to InitInfo() to initialize the Team structor info
	InitInfo(&team);

	//call to function to display info of such player who played max matches
//	DisplayPlayerInfo(&team);

	return 0;
}

