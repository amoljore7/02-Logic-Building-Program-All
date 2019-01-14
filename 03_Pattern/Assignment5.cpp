/////////////////////////////////////////////////////////////////////////////////////
//
//	5. Accept number of elements to be print from user and print following pattern 
//		
//	a    a    a    a    a    a 
//
/////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

void PatternDisplay(int iNum)
{
	int iCount;

	for(iCount=1;iCount<=iNum;iCount++)
	{
		printf("a\t");
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