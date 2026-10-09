#include "header.h"
void booking_details()
{
	PASSENGER *head=NULL,*temp;
	head=sync1();
	char date[15];
	int train_no;
	printf("Enter date(DD-MM-YY)\n");
	__fpurge(stdin);
	scanf("%s",date);
	printf("Enter train_no:\n");
	scanf("%d",&train_no);
	printf(".....!BOKKING DETAILS!....\n");
	if(head==NULL)
	{
		printf("No one Booked!........\n");
		return;
	}
	else
	{
		temp=head;
		while(temp!=NULL)
		{
			if((strcmp(date,temp->date)==0)&&(train_no==temp->train_no)&&(strcmp(login_name,temp->user_name)==0))
			{
			printf("Seat_No : %d\n",temp->seat_no);
			printf("Name    : %s\n",temp->passenger_name);
			printf("Age	: %d\n",temp->age);
			printf("Gender	: %s\n",temp->gender);
			printf("\n");
			}
			temp=temp->next;
		}
	}
}
