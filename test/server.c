#include "hash.h"
int main()
{
	int server_sockfd,client_sockfd,var,serverfd1,clientfd1,result,maxfd,ret,source_bin,source,dest;
	int dest_bin,source1,dest1,server_len,client_len,slen,res,source_port,dest_port,s_port,d_port;	
	fd_set readfds,testfds;
	struct sockaddr_in server_address,my_addr,client_address, cli_addr; 
	unsigned short protocol;
	char ch[SIZE],ip1[SIZE],ip[SIZE],proto[SIZE];
	struct packet *ptr;
	ptr=(struct packet *)malloc(sizeof(struct packet));
    	/*creation of tcp server socket*/
        if((server_sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)	
		perror("TCP error\n");
	else
		printf("TCP sucessfull\n");

	server_address.sin_family=AF_INET;
	server_address.sin_addr.s_addr=inet_addr(IP);
	server_address.sin_port=htons(PORT);
	server_len=sizeof(server_address);
	client_len=sizeof(client_address);


	/*binding of the tcp server socket*/
	if((bind(server_sockfd,(struct sockaddr *)&server_address,server_len))==-1)	
		perror("Bind error\n");
	else
		printf("Bind sucessfull\n");
	/*listening for client socket */
	listen(server_sockfd,5);
	/*creation of UDP socket*/
	if ((serverfd1 = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1)
		perror("socket error\n");
	else
	      printf("udp successful\n");
	/*bzero sets all the values in the buffer to zero,this line initializes my_address to zero*/
	bzero(&my_addr, sizeof(my_addr));
	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(PORT);
	my_addr.sin_addr.s_addr = inet_addr(IP);
	slen=sizeof(my_addr);
	/*binding of UDP server socket*/
	if (bind(serverfd1, (struct sockaddr* ) &my_addr, sizeof(my_addr))==-1)
	      	printf("bind error\n");
	else
		printf("binding success\n");
	
	while(1)
	{
		printf("\n");
		printf("server waiting\n");
		/*clear and fd_set*/
		FD_ZERO(&readfds);
		/*adding a descriptor to an fd*/		
		FD_SET(serverfd1,&readfds);
		FD_SET(server_sockfd,&readfds);
		if(serverfd1>server_sockfd)
			maxfd=serverfd1;
		else
			maxfd=server_sockfd;
		/*select function blocks,till an activity occurs*/
		result=select(maxfd+1, &readfds, NULL, NULL, NULL);
		if(result==-1)
		{
			perror("select");
			return -1;
		}//end of if
		/*FD_ISSET is to check if the descriptor is in an fd_set*/
		if(FD_ISSET(server_sockfd,&readfds))
		{
			printf("receiving Tcp packet\n");
			/*accepting the tcp client connection*/
			client_sockfd=accept(server_sockfd,(struct sockaddr *)&client_address,&client_len);
			strcpy(ptr->protocol,"TCP");
			/* binary ip adress for both destination and source ip address*/
			dest_bin=server_address.sin_addr.s_addr;
			source_bin=client_address.sin_addr.s_addr;
			/*to do DNS lookups*/
			getsockname(server_sockfd,(struct sockaddr *)&server_address,&server_len);
			/*getpeername tells about the other end of the connected socket stream*/
			getpeername(client_sockfd,(struct sockaddr *)&client_address,&client_len);
			printf("source binary:%d\n",dest_bin);
			/*inet_ntoa()-function converts the internet host address in n/w byte order to a string in dotted-decimal format*/
			strcpy(ptr->dest_ip,inet_ntoa(server_address.sin_addr));
			
			/*source port*/
			d_port=htons(server_address.sin_port);
			ptr->dest_port=d_port;
			
			strcpy(ptr->source_ip,inet_ntoa(client_address.sin_addr));
			printf("destination ip=%d\n",source_ip);
			/*destination port*/
			sport=htons(client_address.sin_port);
			ptr->source_port=sport;
			/*reading the data from TCP client*/
			read(client_sockfd,ch,sizeof(ch));
			strcpy(ptr->data,ch);
			printf("data recived from tcp client:%s\n",ch);
			printf("\n");
			insert_packet((void *p);
			if( strcmp(ch,"lookup")==0 || strcmp(ch,"LOOKUP")==0 )
			{
				
			
				lookup_packet((void *q);
			}
			 if( strcmp(ch,"delete")==0 || strcmp(ch,"DELETE")==0 )
			{
				
				printf("\ndeleting the ip");
				delete_packet(void *q);
				
				
			}
			
		}//end of if
		/*processing of UDP packet*/
		if(FD_ISSET(serverfd1,&readfds))
		{
			int len;
			len=sizeof(cli_addr);
			printf("receving udp packet\n");
			/* receiving data from client*/
			if (recvfrom(serverfd1,ch, 256, 0, (struct sockaddr*)&cli_addr, &slen)==-1)
            			printf("received packet from");
			strcpy(ptr->protocol,"UDP");
			dest_bin=my_addr.sin_addr.s_addr;
			source_bin=cli_addr.sin_addr.s_addr;
			d_port=htons(my_addr.sin_port);
			s_port=htons(cli_addr.sin_port);
			/*getsockname returns the  address to which the current socket is bound*/
			getsockname(serverfd1,(struct sockaddr *)&my_addr,&slen);
			strcpy(ptr->dest_ip,inet_ntoa(my_addr.sin_addr));
			/*ip and port number of source port*/
			
			/*getpeername gives details of client which is connected to UDP server*/
			getpeername(serverfd1,(struct sockaddr *)&cli_addr,&len);
			
			strcpy(ptr->source_ip,inet_ntoa(cli_addr.sin_addr));
			ptr->source_port=s_port;
			ptr->dest_port=d_port;

			printf("data received from udp client :%s\n",ch);
			strcpy(ptr->data,ch);
			insert_packet(void *p );
			if( strcmp(ch,"lookup")==0 || strcmp(ch,"LOOKUP")==0 )
			{
				
				printf("\nsearching for the ip");
				lookup_packet((void *q);
			}
			 if( strcmp(ch,"delete")==0 || strcmp(ch,"DELETE")==0 )
			{
				
				printf("\n\nDELETING the IP ENTRY!!");
				delete_packet((void *q);			}//end of if
			
			
		}
	} //end of while
		/*closing of udp socket*/
		close(serverfd1);
		/*closing of tcp socket*/
		close(server_sockfd);
		free(ptr);

} //end of main

