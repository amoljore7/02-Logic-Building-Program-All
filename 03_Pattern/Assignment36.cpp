/////////////////////////////////////////////////////////////////////////////////////
//
//	36. Accept number of rows from user and print following pattern
//
//		0
//		1	1
//		2	3	5
//		8	13	21	34
//
/////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

void PatternDisplay(int iNum)
{
	int iRow,iCol;
	int iNum1,iNum2,iNum3;

	iNum1=1;
	iNum2=0;
	iNum3=0;

	for(iRow=0;iRow<=iNum;iRow++)
	{
		for(iCol=0;iCol<=iRow;iCol++)
		{
			printf("%d\t",iNum3);

			iNum2=iNum1;
			iNum1=iNum3;
			iNum3=iNum1+iNum2;
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