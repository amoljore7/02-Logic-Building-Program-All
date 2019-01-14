/////////////////////////////////////////////////////////////////////////////////////
//
//	25. Accept number of rows from user and print following pattern
//
//			1
//			1	2			
//			1	0	3
//			1	0	0	4
//			1	0	0	0	5
//
/////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

void PatternDisplay(int iNum)
{
	int iRow,iCol;

	for(iRow=1;iRow<=iNum;iRow++)
	{
		for(iCol=1;iCol<=iRow;iCol++)
		{
			if(iCol == 1 || iCol == iRow)
			{
				printf("%d\t",iCol);
			}
			else
			{
				printf("0\t");
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