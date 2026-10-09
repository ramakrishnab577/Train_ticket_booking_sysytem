#include "header.h"
void train_details()
{
	FILE *fptr;
	char str[100];
	fptr=fopen("train_info.txt","r");
	if(fptr==NULL)
	{
		printf("There is no trains details...\n\n");
		exit(0);
	}
	else
	{
		while(fgets(str,100,fptr))
		{
			printf("%s",str);
		}
	}
	fclose(fptr);
}
