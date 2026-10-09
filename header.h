#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio_ext.h>
typedef struct train
{
	char name[50];
	char pwd[50];
	struct train *link;
}RAIL;
typedef struct
{
    int train_no;
    char train_name[30];
    char source[30];
    char destination[30];
    int total_seats;
}TRAIN;
typedef struct passenger
{
    char user_name[50];
    int train_no;
    char date[15];
    int seat_no;
    char passenger_name[30];
    int age;
    char gender[10];
    struct passenger *next;

}PASSENGER;
typedef struct wait
{
    int train_no;
    char date[15];
    char name[30];
    int age;
    char gender[10];
    struct wait *next;
}WAIT;
extern int size;
extern int size1;
extern int wsize;
extern char login_name[50];
void sign_up();
RAIL *sync();
void save(RAIL *ptr);
void sign_in();
void train_details();
void menu();
PASSENGER *sync1();
void reserve_ticket();
void cancel_ticket();
void booking_details();
void waiting_list(int n,int train_no,char *date);
WAIT *wait_sync();
