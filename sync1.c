#include "header.h"
PASSENGER *sync1()
{
        PASSENGER *newnode=NULL,var,*temp=NULL,*ptr=NULL;
        FILE *fptr=NULL;
        fptr=fopen("passenger_info.txt","r");
        if(fptr==NULL)
        {
                printf("sync failed\n");
                return ptr;
        }
        while((fread(&var,size1,1,fptr))==1)
        {
                newnode=calloc(1,sizeof(PASSENGER));
		strcpy(newnode->user_name,var.user_name);
                newnode->train_no=var.train_no;
                strcpy(newnode->date,var.date);
		newnode->seat_no=var.seat_no;
		strcpy(newnode->passenger_name,var.passenger_name);
		newnode->age=var.age;
		strcpy(newnode->gender,var.gender);
                if(ptr==NULL)
                {
                        ptr=newnode;
                }
                else
                {
                        temp=ptr;
                        while(temp->next!=NULL)
                        {
                                temp=temp->next;
                        }
                        temp->next=newnode;

                }
        }
        fclose(fptr);
        return ptr;
}
