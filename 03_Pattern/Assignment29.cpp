/////////////////////////////////////////////////////////////////////////////////////
//
//	29. Accept number of rows from user and print following pattern
//
//			1
//			2	3			
//			4	5	6
//			7	8	9	10
//			11	12	13	14	15
//
/////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

void PatternDisplay(int iNum)
{
	int iRow,iCol;
	int iNo=1;

	for(iRow=1;iRow<=iNum;iRow++)
	{
		for(iCol=1;iCol<=iRow;iCol++)
		{
			printf("%d\t",iNo++);
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