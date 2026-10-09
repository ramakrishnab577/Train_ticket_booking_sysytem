#include "header.h"
int main()
{
	int i;
	while(1)
	{
	printf("1:sign_up\n2:sign_in\n3:exit\n");
	scanf("%d",&i);
	switch(i)
	{
		case 1:sign_up();
		      break;
	        case 2:sign_in();
		      break;
	        case 3:exit(0);
	}
	}
}
