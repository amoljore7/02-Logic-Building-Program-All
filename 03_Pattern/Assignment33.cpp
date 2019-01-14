/////////////////////////////////////////////////////////////////////////////////////
//
//	33. Accept number of rows from user and print following pattern
//
//			1
//			2	3
//			4	5	6
//			7	8	9	1
//			2	3	4	5	6
//
/////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

void PatternDisplay(int iNum)
{
	int iRow,iCol;
	int iNo=1;
	for(iRow=0;iRow<iNum;iRow++)
	{
		for(iCol=0;iCol<=iRow;iCol++)
		{
			printf("%d\t",iNo++);
			if(iNo == 10)
			{
				iNo=1;
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