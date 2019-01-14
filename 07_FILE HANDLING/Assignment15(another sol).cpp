#include<stdio.h>

#include<stdlib.h>
int main()
{
	FILE *fp1=NULL;
	FILE *fp2=NULL;
	char c;
	fpos_t location;

		fp1=fopen("abc.txt","r");
		fp2=fopen("xyz.txt","w");	
		if(fp1==NULL && fp2==NULL)
		{
			printf("Unable to open file");	
			exit(1);
		}

		rewind(fp1);
		fgetpos(fp1,&location);
		printf("Current position of file = %d \n",location);

		
		
		fseek(fp1,0,SEEK_END);
	    fgetpos(fp1,&location);
		printf(" Now Current position of file = %d\n ",location);
		
		while(location>0)
		 {
			 c=fgetc(fp1);
			 printf("%c",c);
			 fputc(c,fp2);
			 location--;
			 fsetpos(fp1,&location);
		}
		 fclose(fp1);
		 fclose(fp2);



	return 0;
} 