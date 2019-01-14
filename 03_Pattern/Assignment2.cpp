/////////////////////////////////////////////////////////////////////////////////////
//
//	2. Accept number of elements to be print from user and print following pattern 
//		
//	1    1    1    1    1    1 
//
/////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

void PatternDisplay(int iNum)
{
	int iCount=0;

	for(iCount=0;iCount<iNum;iCount++)
	{
		printf("1\t");
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