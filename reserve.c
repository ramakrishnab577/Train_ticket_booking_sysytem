#include "header.h"
int size1=sizeof(PASSENGER)-sizeof(PASSENGER *);
int get_train_details(int train_no, TRAIN *train)
{
    FILE *fp;
    fp = fopen("train_info.txt", "r");
    if (fp == NULL)
        return 0;
	while (fscanf(fp, "%d %s %s %s %d",
                  &train->train_no,
                  train->train_name,
                  train->source,
                  train->destination,
                  &train->total_seats) == 5)
       {
      	  if (train->train_no == train_no)
          {
            fclose(fp);
            return 1;
          }
      }
    fclose(fp);
    return 0;
}
void save_passenger(PASSENGER *ptr)
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
void reserve_ticket()
{
    TRAIN train;
    PASSENGER *head = NULL;
    PASSENGER *newnode;
    PASSENGER *temp;
    head=sync1();
    int train_no;
    int n,w,r;
    int i;
    int seat_no=0;
    int available;
    char date[15];
    printf("============================!TICKET RESERVATION!============================\n\n");
    printf("Enter Train Number: ");
    scanf("%d", &train_no);
    if (get_train_details(train_no, &train) == 0)
    {
        printf("Train not found\n");
        return;
    }
    printf("\nTrain Name  : %s", train.train_name);
    printf("\nSource      : %s", train.source);
    printf("\nDestination : %s", train.destination);
    printf("\nTotal Seats : %d\n", train.total_seats);
    printf("\nEnter Journey Date(DD-MM-YY): ");
    scanf("%s", date);
    temp=head;
    while(temp!=NULL)
    {
	    if((train_no==temp->train_no) && (strcmp(date,temp->date))==0)
	     seat_no++;
	    temp=temp->next;
    }
    printf("\nBooked seats are:%d\n",seat_no);
    available=train.total_seats-seat_no;
    printf("Available seats are:%d\n",available);
    printf("\nEnter Number of Seats: ");
    scanf("%d", &n);
    if(n > available)
    {
	w=n-available;
	r=n-w;
	printf("if you want reserve all  tickets yes[y] or no[n]\n");
        char ch;
	__fpurge(stdin);
	scanf("%c",&ch);
	if(ch=='y')
	{
		printf("%d seats will be reserve\n",r);
        	printf("%d seats are going to waiting list\n",w);
	}
	else
	{
        	return;
	}
    }
    for(i=0;i<n;i++)
    {
	
	if(seat_no == train.total_seats)
	{
	    waiting_list(w,train_no,date);
	    break;
	}
        newnode = malloc(sizeof(PASSENGER));
        if (newnode == NULL)
        {
            printf("Memory allocation failed\n");
            return;
        }
        newnode->train_no = train_no;
	strcpy(newnode->user_name,login_name);
	strcpy(newnode->date, date);
        printf("\nPassenger %d\n", i + 1);
        printf("Name: ");
	__fpurge(stdin);
	fgets(newnode->passenger_name,30,stdin);
	newnode->passenger_name[strlen(newnode->passenger_name)-1]='\0';
        printf("Age: ");
        scanf("%d", &newnode->age);
        printf("Gender: ");
        scanf("%s", newnode->gender);
        newnode->seat_no = ++seat_no;
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

	save_passenger(head);
       	printf("Seat Number: %d\n",newnode->seat_no);
        printf("Ticket booked successfully!\n");
    }


} 
