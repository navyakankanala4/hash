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
#define PORT 9732
#define IP "192.168.131.33"
int server_sockfd,client_sockfd,var,serverfd1,clientfd1,result,maxfd,ret,source_bin,source,dest;
	int dest_bin,source1,dest1,server_len,client_len,slen,res,source_port,dest_port;	
	struct sockaddr_in server_address,my_addr,client_address, cli_addr; 	
fd_set readfds,testfds;
int key;

time_t current_time;
/*structure named packet to store all five tupple*/
struct packet
{	
	int key;
	char source_ip[SIZE],dest_ip[SIZE];
	int source_port,dest_port;
        char data[SIZE];
	unsigned short protocol;
	char time[SIZE];
	
	//struct packet *next;

}*h[65536],*ptr;
struct hash
{
struct hash *next;
struct packet *info;
char time[SIZE];
int key;
};
struct hash *ma[100];



int addition(int , int ,int , int);

void insert_packet(void *p);
void delete_packet(void *q);
void lookup_packet(void *q)

