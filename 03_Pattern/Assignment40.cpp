/////////////////////////////////////////////////////////////////////////////////////
//
//	40. Accept string from user and print following pattern
//		string => PIYUSH
//		
//		P	I	Y	U	S	H
//		P	I	Y	U	S
//		P	I	Y	U
//		P	I	Y
//		P	I
//		P
//
/////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<string.h>

void PatternDisplay(char *sPtr)
{
	int iRow,iCol;
	
	int strlength=strlen(sPtr);

	char *temp=sPtr;

	for(iRow=strlength;iRow>0;iRow--)
	{
		for(iCol=0;iCol<iRow;iCol++)
		{
			printf("%c\t",*temp);
			temp++;
		}
		printf("\n");
		temp=sPtr;
	}
}
int main()
{
	char cString[20]={'\0'};

	printf("\n Enter string to display pattern => ");
	scanf("%s",&cString);

	PatternDisplay(cString);

	return 0;

}
