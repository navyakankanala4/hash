#include<stdio.h>	
#include<unistd.h>
#include<netinet/in.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<stdlib.h>
#include<time.h>
#include<errno.h>
#define MAX 100
#define TCP 6
#define UDP 17
#define SIZE 2048
int server_sockfd,client_sockfd,vara,serverfd1,clientfd1,result,maxfd,ret,source_bin,source,dest;
int dest_bin,source1,dest1,server_len,client_len,slen,res,s_port,d_port;	
struct sockaddr_in server_address,my_addr,client_address,  cli_addr;	
fd_set readfds,testfds;
int key;
unsigned char ch[100],ip[100];
time_t current_time;

struct packet
{	
	int source_ip,dest_ip,source_port,dest_port;
        char data[256];
	unsigned short protocol;
	unsigned char time[30];
	unsigned short count;
	struct packet *next;

}*h[65536],*ptr;
unsigned char buf[SIZE],*htime;

int addition_digits(int , int ,int , int);
int add_individual(long );
void insert_packet(struct packet *, int ,int ,int ,int ,char [],unsigned short );
void delete_packet(struct packet *, int ,int ,int ,int ,char [],unsigned short );
void lookup_packet(struct packet *,int ,int ,int ,int ,char [] );
void display();
