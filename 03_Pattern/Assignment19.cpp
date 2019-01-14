/////////////////////////////////////////////////////////////////////////////////////
//
//	19. Accept number of rows from user and print following pattern
//
//			*	*	*	*	*
//			*	*	*	*
//			*	*	*	
//			*	*	
//			*
//
/////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

void PatternDisplay(int iNum)
{
	int iRow,iCol;

	for(iRow=iNum;iRow>0;iRow--)
	{
		for(iCol=iRow;iCol>0;iCol--)
		{
			if(iRow >= iCol)
			{
				printf("*\t");
			}
			else
			{
				printf("\t");
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