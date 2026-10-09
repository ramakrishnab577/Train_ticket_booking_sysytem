#include "header.h"
char login_name[50];
void sign_in()
{
	RAIL *head=NULL,*ptr=NULL;
	char pwd[50];
	int cnt=0,flag=0;
	head=sync();
user:	printf("Enter user Name\n");
	__fpurge(stdin);
	//fgets(name,50,stdin);
	//name[strcspn(name,"\n")]='\0';
	scanf("%s",login_name);
	printf("Enter password\n");
	__fpurge(stdin);
	//fgets(pwd,50,stdin);
	//pwd[strcspn(pwd,"\n")]='\0';
	scanf("%s",pwd);
	if(head==NULL)
	{
		printf("first create your account....\n");
		printf("\n");
	}
	else
	{
		ptr=head;
		while(ptr!=NULL)
		{
			if((strcmp(login_name,ptr->name)==0) && (strcmp(pwd,ptr->pwd)==0))
			{
				printf("login successfully...\n\n");
				flag=1;
				break;
			}
			ptr=ptr->link;
		}
	}
	if(flag==1)
	{
	      menu();
	}
	else
	{
		printf("invald login credentials..\nIf you don't have account sign-up first sign_up after sign_in\n\n");
		cnt++;
		if(cnt==3)
		{
			printf("TIME OUT!...\ntry again after 5 mins\n\n");
			exit(0);
		}
		goto user;
	}



}
