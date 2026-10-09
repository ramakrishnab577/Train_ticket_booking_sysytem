a.out : main.o sign_up.o save.o sync.o sign_in.o train_details.o menu.o reserve.o sync1.o cancel_ticket.o booking_details.o wait_list.o wait_sync.o 
	gcc main.o sign_up.o save.o sync.o sign_in.o train_details.o menu.o reserve.o sync1.o cancel_ticket.o booking_details.o wait_list.o wait_sync.o
main.o : main.c
	gcc -c main.c
sign_up.o : sign_up.c
	gcc -c sign_up.c
save.o : save.c
	gcc -c save.c
sync.o : sync.c
	gcc -c sync.c
sign_in.o : sign_in.c
	gcc -c sign_in.c
train_details.o : train_details.c
	gcc -c train_details.c
menu.o : menu.c
	gcc -c menu.c
reserve.o : reserve.c
	gcc -c reserve.c
sync1.o : sync1.c
	gcc -c sync1.c
cancel_ticket.o : cancel_ticket.c
	gcc -c cancel_ticket.c
booking_details.o : booking_details.c
	gcc -c booking_details.c
wait_list.o : wait_list.c
	gcc -c wait_list.c
wait_sync.o : wait_sync.c
	gcc -c wait_sync.c
