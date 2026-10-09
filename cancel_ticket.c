#include "header.h"
void update_passengers(PASSENGER *ptr)
{
        PASSENGER *temp=NULL;
        FILE *fptr=NULL;
        fptr=fopen("passenger_info.txt","w");
        temp=ptr;
        while(temp!=NULL)
        {
             fwrite(temp,size1,1,fptr);
             temp=temp->next;

        }
        fclose(fptr);
}
void cancel_ticket()
{
	PASSENGER *head=NULL,*temp=NULL,*prev=NULL,*futu=NULL;
	printf("\n=============================TICKET CANCELLATION=====================\n\n");
	int train_no;
	char date[15];
	char name[30];
	int age;
	char gender[30];
	int seat_no;
	head=sync1();
	printf("Enter train Number: ");
	scanf("%d",&train_no);
	printf("Enter date: ");
	scanf("%s",date);
	printf("Enter name: ");
	__fpurge(stdin);
	fgets(name,30,stdin);
	name[strlen(name)-1]='\0';
	printf("Enter age : ");
	scanf("%d",&age);
	printf("Enter gender: ");
	__fpurge(stdin);
	scanf("%s",gender);
	printf("Enter seat_no: ");
	scanf("%d",&seat_no);
	if(head==NULL)
	{
		printf("details are not found!..\n");
		return;
	}
	if(head->next==NULL)
	{
		if((train_no==head->train_no)&&
					(seat_no==head->seat_no)&&
					(strcmp(name,head->name)==0)&&
					(age==head->age)&&
					(strcmp(gender,head->gender)==0))
		{
				free(head);
				printf("your ticket is successfully cancelled!....\n");
				head=NULL;
		}
		else
		{
			printf("Deatails not found\n");
			return;
		}
	}
	else
	{
		temp=head;
		while(temp!=NULL)
		{
			if((train_no==temp->train_no)&&
					(seat_no==temp->seat_no)&&
					(strcmp(name,temp->name)==0)&&
					(age==temp->age)&&
					(strcmp(gender,temp->gender)==0))
			{
			    prev->next=temp->next;
			    free(temp);
			    printf("your ticket is successfully cancelled!.....\n");
				break;
			}
			prev=temp;
			temp=temp->next;
		}

	}
	update_passengers(head);
}	
