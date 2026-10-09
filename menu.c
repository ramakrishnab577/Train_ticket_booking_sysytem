#include "header.h"
void menu()
{
	char ch;
	train_details();
	while(1)
	{
		printf("\nr:TO reserve ticket\nc:To Cancel ticket\nb:booking_details\nq:Quit from app\n");
		__fpurge(stdin);
		scanf("%c",&ch);
	        switch(ch)
		{
			case 'r':reserve_ticket();
				 break;
			case 'c':cancel_ticket();
				 break;
			case 'b':booking_details();
				 break;
			case 'q':exit(0);
		}	
	}
}
