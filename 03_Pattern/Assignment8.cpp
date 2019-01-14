/////////////////////////////////////////////////////////////////////////////////////
//
//	8. Accept number of elements to be print from user and print following pattern 
//		
//	a    c    e    g    i    k 
//
/////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

void PatternDisplay(int iNum)
{
	int iCount;
	char ch='a';

	for(iCount=1;iCount<=iNum;iCount++)
	{
		printf("%c\t",ch);
		
		ch+=2;
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