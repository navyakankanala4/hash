#include "hash.h"
int main()
{
	unsigned short protocol;
    	/*creation of tcp server socket*/
        if((server_sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)	
		perror("TCP error\n");
	else
		printf("TCP sucessfull\n");

	server_address.sin_family=AF_INET;
	server_address.sin_addr.s_addr=inet_addr("192.168.131.33");
	server_address.sin_port=htons(9732);
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
	my_addr.sin_port = htons(9732);
	my_addr.sin_addr.s_addr = inet_addr("192.168.131.33");
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
			/* binary ip adress for both destination and source ip address*/
			dest_bin=server_address.sin_addr.s_addr;
			source_bin=client_address.sin_addr.s_addr;
			/*to do DNS lookups*/
			getsockname(server_sockfd,(struct sockaddr *)&server_address,&server_len);
			/*getpeername tells about the other end of the connected socket stream*/
			getpeername(client_sockfd,(struct sockaddr *)&client_address,&client_len);
			printf("source binary:%d\n",source_bin);
			/*inet_ntoa()-function converts the internet host address in n/w byte order to a string in dotted-decimal format*/
			strcpy(ip,inet_ntoa(server_address.sin_addr));
			printf(" source ip = %d\n",source);
			/*source port*/
			s_port=htons(server_address.sin_port);
			printf("source port=%d\n",s_port);
			/*destination ip */
			dest=client_address.sin_port;
			printf("destination ip binary :%d\n",dest_bin);
			strcpy(ip,inet_ntoa(client_address.sin_addr));
			printf("destination ip=%d\n",dest);
			/*destination port*/
			d_port=htons(client_address.sin_port);
			printf("destination port=%d\n",d_port);
			/*reading the data from TCP client*/
			read(client_sockfd,ch,sizeof(ch));
			printf("data recived from tcp client:%s\n",ch);
			printf("\n");
			if( strcmp(buf,"lookup")==0 || strcmp(buf,"LOOKUP")==0 )
			{
				
				printf("\nsearching for the ip");
				lookup_packet(ptr, source_bin, dest_bin, s_port, d_port, ip);
			}
			 if( strcmp(buf,"delete")==0 || strcmp(buf,"DELETE")==0 )
			{
				
				printf("\ndeleting the ip");
				delete_packet(ptr,  source_bin, dest_bin, s_port, d_port, ch, protocol);
				
				display();
			}
			time(&current_time);
			htime=ctime(&current_time);
			insert_packet(ptr,  source_bin, dest_bin, s_port, d_port, ch, protocol);
			display();
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

			dest1=my_addr.sin_addr.s_addr;
			source1=cli_addr.sin_addr.s_addr;
			d_port=htons(my_addr.sin_port);
			s_port=htons(cli_addr.sin_port);
			/*getsockname returns the  address to which the current socket is bound*/
			getsockname(serverfd1,(struct sockaddr *)&my_addr,&slen);
			printf("source ip binary:%d\n",source1);
			strcpy(ip,inet_ntoa(my_addr.sin_addr));
			/*ip and port number of source port*/
			printf("source ip =%d\n",source);
			printf("source port no=%d\n",s_port);
			/*getpeername gives details of client which is connected to UDP server*/
			getpeername(serverfd1,(struct sockaddr *)&cli_addr,&len);
			printf("destination ip in binary:%d\n",dest1);
			strcpy(ip,inet_ntoa(cli_addr.sin_addr));
			printf("destination ip=%d\n",dest);
			printf("destination port no=%d\n",d_port);

			printf("data received from udp client :%s\n",ch);
			if( strcmp(buf,"lookup")==0 || strcmp(buf,"LOOKUP")==0 )
			{
				
				printf("\nsearching for the ip");
				lookup_packet(ptr, source_bin, dest_bin, s_port, d_port, ip);
			}
			 if( strcmp(buf,"delete")==0 || strcmp(buf,"DELETE")==0 )
			{
				
				printf("\n\nDELETING the IP ENTRY!!");
				delete_packet( ptr,  source_bin, dest_bin, s_port, d_port, ch, protocol);
			}//end of if
			
			time(&current_time);
			htime=ctime(&current_time);
			insert_packet( ptr, source_bin, dest_bin, s_port, d_port, ch, protocol);
			display();
		}
	} //end of while
		/*closing of udp socket*/
		close(serverfd1);
		/*closing of tcp socket*/
		close(server_sockfd);

} //end of main
