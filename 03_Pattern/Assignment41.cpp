/////////////////////////////////////////////////////////////////////////////////////
//
//	41. Accept string from user and print following pattern
//		string => PIYUSH
//		
//		P	i	Y	u	S	h
//		P	i	Y	u	S
//		P	i	Y	u
//		P	i	Y
//		P	i
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
			if(iCol % 2 != 0)
			{
				printf("%c\t",*temp+32);
			}
			else
			{
				printf("%c\t",*temp);
			}
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
