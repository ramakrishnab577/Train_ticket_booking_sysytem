#include "header.h"
int wsize=sizeof(WAIT)-sizeof(WAIT *);
void save_wait(WAIT *ptr)
{
        WAIT *temp=NULL;
        FILE *fptr=NULL;
        fptr=fopen("waiting_list_info.txt","w");
        temp=ptr;
        while(temp!=NULL)
        {
             fwrite(temp,wsize,1,fptr);
             temp=temp->next;

        }
        fclose(fptr);
}
void waiting_list(int n,int train_no,char *date)
{
    WAIT *newnode=NULL,*head=NULL,*temp=NULL;
    int i;
    head=wait_sync();
    for(i=0;i<n;i++)
    {
        newnode = malloc(sizeof(WAIT));
        if (newnode == NULL)
        {
            printf("Memory allocation failed\n");
            return;
        }
        newnode->train_no = train_no;
	strcpy(newnode->date, date);
        printf("\nPassenger %d\n", i + 1);
        printf("Name: ");
	__fpurge(stdin);
	fgets(newnode->name,30,stdin);
	newnode->name[strlen(newnode->name)-1]='\0';
        printf("Age: ");
        scanf("%d", &newnode->age);
        printf("Gender: ");
        scanf("%s", newnode->gender);
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp = head;
            while(temp->next != NULL)
            temp = temp->next;
            temp->next = newnode;
        }
	save_wait(head);
	printf("added in waiting list.......\n");
    }
}
