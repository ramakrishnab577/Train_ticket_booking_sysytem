#include"header.h"
int check_pwd(char *str)
{
	int up=0,lw=0,nm=0,sp=0;
	char *ptr=NULL;
	ptr=str;
	while(*ptr)
	{
		if(up==1 && lw==1 && nm==1 && sp==1)
		{
			return 1;
		}
		else if((*ptr>=65 && *ptr<=90)&&(up==0))
		{
			up=1;
		}
		else if((*ptr>=97 && *ptr<=122)&&(lw==0))
		{
			lw=1;
		}
		else if((*ptr>=48 && *ptr<=57) &&(nm==0))
		{
			nm=1;
		}
		else if(((*ptr>=33 && *ptr<=47) || (*ptr>=58 && *ptr <=64) || (*ptr>=91 && *ptr<=96) ||(*ptr>=123 && *ptr<=126)) && sp==0)
		{
			sp=1;
		}
		ptr++;
	}
	if(up==1 && lw==1 && nm==1 && sp==1)
	{
		return 1;
	}
	return 0;
}
void sign_up()
{
	int len,cnt=0;
	RAIL *newnode=NULL,*head=NULL,*ptr=NULL;
	head=sync();
	newnode=calloc(1,sizeof(RAIL));
test1:	printf("Enter name\n");
	__fpurge(stdin);
	fgets(newnode->name,50,stdin);
	newnode->name[strcspn(newnode->name,"\n")]='\0';
	ptr=head;
	while(ptr!=NULL)
	{
		if((strcmp(newnode->name,ptr->name))==0)
		{
			printf("user name already exist\n");
			goto test1;
		}
		ptr=ptr->link;
	}
	printf("Your password have a 1(upper,lower,numeric and numeric)alphabets\n");
test2:	printf("Enter Password\n");
	__fpurge(stdin);
	fgets(newnode->pwd,50,stdin);
	newnode->pwd[strcspn(newnode->pwd,"\n")]='\0';
	cnt++;
	if(cnt>5)
	{
		printf("TIMEOUT\n");
		printf("sign_up after some time\n");
		exit(0);
	}
	len=strlen(newnode->pwd);
	if(len<8)
	{
		printf("invalid password your entered a password minimum 8 characters\n");
		goto test2;
	}
	if(check_pwd(newnode->pwd))
	{
		newnode->link=head;
                head=newnode;            
                printf("your account created successfully.......\n");
                save(head);
	}
	else
	{
		printf("your password is invalid\n");
		goto test2;

	}
}
