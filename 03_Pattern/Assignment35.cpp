/////////////////////////////////////////////////////////////////////////////////////
//
//	35. Accept number of rows from user and print following pattern
//
//							1
//						1	1	1
//					1	0	1	0	1
//				1	0	0	1	0	0	1
//			1	0	0	0	1	0	0	0	1
//		1	1	1	1	1	1	1	1	1	1	1
//
/////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

void PatternDisplay(int iNum)
{
	int iRow,iCol;
	int range= (iNum*2)-1;

	for(iRow=1;iRow<=iNum;iRow++)
	{
		for(iCol=1;iCol<=range;iCol++)
		{
			if(iRow == iNum || iCol == iNum || (iCol-iRow)+1 == iNum || (iRow+iCol)-1 == iNum)
			{
				printf("1\t");
			}
			else if(iRow+iCol > iNum && iCol-iRow < iNum)
			{
				printf("0\t");
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