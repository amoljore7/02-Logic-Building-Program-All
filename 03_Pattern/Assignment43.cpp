/////////////////////////////////////////////////////////////////////////////////////
//
//	43. Accept string from user and print following pattern
//		string => UNIX WIN32 SDK
//		
//		U
//		U	N
//		U	N	I
//		U	N	I	X
//					W
//					W	I
//					W	I	N
//					W	I	N	3
//					W	I	N	3	2
//									S
//									S	D
//									S	D	K
//		
//
/////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<string.h>

void PatternDisplay(char *sPtr)
{
	int iRow,iCol;
	int iCount1=0,iCount2=0;
	
	int strlength=strlen(sPtr);
	char *temp=sPtr;
	
	for(iRow=1;iRow<=strlength;iRow++)
	{
		for(iCol=1;iCol<=iRow;iCol++)
		{
			while(iCount1 != 0)
			{
				printf("\t");
				iCount1--;
			}
			printf("%c\t",*temp);
			temp++;
			if(*temp == 32)
			{
				sPtr=temp + 1;
				strlength=(strlength - (iRow + 1));
				iRow=0;
				iCount2=iCount2+(iCol - 1);
			}
		}
		temp=sPtr;
		iCount1=iCount2;
		printf("\n");
	}
}
int main()
{
	char cString[20]={'\0'};

	printf("\n Enter string to display pattern => ");
	gets(cString);

	PatternDisplay(cString);

	return 0;

}
