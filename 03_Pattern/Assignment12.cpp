/////////////////////////////////////////////////////////////////////////////////////
//
//	12. Accept number of rows from user and print following pattern
//
//			a	b	c	d
//			a	b	c	d
//			a	b	c	d 
//			a	b	c	d
//
/////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

void PatternDisplay(int iNum)
{
	int iRow,iCol;
	char ch='a';

	for(iRow=0;iRow<iNum;iRow++)
	{
		for(iCol=0;iCol<iNum;iCol++)
		{
			printf("%c\t",ch++);
		}
		ch='a';
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