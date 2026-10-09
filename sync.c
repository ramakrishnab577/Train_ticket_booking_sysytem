#include "header.h"
RAIL *sync()
{
        RAIL *newnode=NULL,var,*temp=NULL,*ptr=NULL;
        FILE *fptr=NULL;
        fptr=fopen("user_logins.txt","r");
        if(fptr==NULL)
        {
                printf("sync failed\n");
                return ptr;
        }
        while((fread(&var,size,1,fptr))==1)
        {
                newnode=calloc(1,sizeof(RAIL));
                strcpy(newnode->name,var.name);
		strcpy(newnode->pwd,var.pwd);
                if(ptr==NULL)
                {
                        ptr=newnode;
                }
                else
                {
                        temp=ptr;
                        while((temp->link)!=NULL)
                        {
                                temp=temp->link;
                        }
                        temp->link=newnode;

                }
        }
        fclose(fptr);
        return ptr;
}
