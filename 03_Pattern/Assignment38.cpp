/////////////////////////////////////////////////////////////////////////////////////
//
//	38. Accept number of rows from user and print following pattern
//
//		1
//		1	2
//		1	2	3
//		1	2	3	4
//		4	6	6	4	0
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
			if(iRow == iNum)
			{
				printf("%d\t",(iRow - iCol)*iCol);
			}
			else
			{
				printf("%d\t",iCol);
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