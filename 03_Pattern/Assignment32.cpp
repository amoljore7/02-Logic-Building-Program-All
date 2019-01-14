/////////////////////////////////////////////////////////////////////////////////////
//
//	32. Accept number of rows from user and print following pattern
//
//			10
//			20	21
//			30	31	32
//			40	41	42	43
//			50	51	52	53	54
//
/////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

void PatternDisplay(int iNum)
{
	int iRow,iCol;
	int iNo=10;
	for(iRow=0;iRow<iNum;iRow++)
	{
		for(iCol=0;iCol<=iRow;iCol++)
		{
			printf("%d\t",iNo+iCol);
		}
		iNo+=10;
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