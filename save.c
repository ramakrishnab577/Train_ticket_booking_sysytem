#include "header.h"
int size=(sizeof(RAIL)-sizeof(RAIL *));
void save(RAIL *ptr)
{
        RAIL *temp=NULL;
        FILE *fptr=NULL;
        fptr=fopen("user_logins.txt","w");
        temp=ptr;
        while(temp!=NULL)
        {
             fwrite(temp,size,1,fptr);
             temp=temp->link;

        }
        fclose(fptr);
}
