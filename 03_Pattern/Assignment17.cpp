/////////////////////////////////////////////////////////////////////////////////////
//
//	17. Accept number of rows from user and print following pattern
//
//			*	*	*	*	*
//			*	-	-	-	*
//			*	-	-	-	*
//			*	-	-	-	*
//			*	*	*	*	*
//
/////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

void PatternDisplay(int iNum)
{
	int iRow,iCol;

	for(iRow=1;iRow<=iNum;iRow++)
	{
		for(iCol=1;iCol<=iNum;iCol++)
		{
			if(iCol == 1 || iRow == 1 || iCol == iNum || iRow == iNum)
			{
				printf("*\t");
			}
			else
			{
				printf("-\t");
			}
		}
		printf("\n");
	}
}


int main()
{
	int iNum=0;

	printf("\n Enter number of elements do you want to print => ");
	scanf("%d",&iNum);

	PatternDisplay(iNum);

	return 0;

}