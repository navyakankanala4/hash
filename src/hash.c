#include "hash.h"
unsigned short packet(unsigned char *ip)
{
	int key;
	key=addition_digits(source_bin,dest_bin,s_port,d_port);
	return key;
}
int addition_digits(int source,int dest,int sport,int dport)
{
	int res=0,sum;
	sum=add_individual(source)+res;
	sum=add_individual(dest)+res;
	sum=add_individual(sport)+res;
	sum=add_individual(dport)+res;
	return res;
}

int add_individual(long num)
{
	long rem,sum=0;
	while(num>0)
	{
		rem=num%10;
		sum=sum+rem;
		num=num/10;
	}
	return sum;
}

//void insert(unsigned char ip[16], unsigned short port, unsigned char *htime[], unsigned short protocol, unsigned char ch[])
void insert_packet(struct packet *ptr, int source_bin,int dest_bin,int s_port,int d_port,char ch[],unsigned short protocol) 
{
	unsigned char index;
	
	unsigned char i;
	unsigned char cmp;
	struct packet *temp;
	/*generating the key by adding all source port destination port ,source ip,destination ip*/
	key= packet(ip);
	index=key%MAX;
	/*if the elements are not present in the list*/
	if(h[index]==NULL)
	{
		/*allocation of memory using malloc */
		h[index] = (struct packet *) malloc( sizeof(struct packet) );
		
		/*if the memory is not allocated still malloc fails*/
		if(h[index]==NULL)
		{
			printf("malloc failed\n");
			exit(-1);
		}
		/*storing the index value in temp*/
		temp = h[index];
		temp = memset(temp, '\0', sizeof(struct packet));
		/*differentiating the protocols based on port numbers*/
		if(protocol == TCP)
		   temp->protocol = TCP;
		else if(protocol == UDP)
		   temp->protocol = UDP;
		else
		{
			printf("\n\nWrong Protocol\n");
			exit(-1);
		}
		/*if the ip is not null then storing the ip value and port numbers and time at which the packet arrived*/
		for(i=0;i<MAX;i++)
		{
	   	   temp->source_ip=source_bin;
		    temp->dest_ip=dest_bin;
		
		temp->source_port=s_port;
		temp->dest_port=d_port;

		for(i=0;htime[i]!='\0';i++)	
		   temp->time[i]=htime[i];

		++(temp->count);

		temp->next=NULL;
		/*storing the data sent by the client*/
		for(i=0;buf[i]!='\0';i++)
		   temp->data[i]=ch[i];
		   temp->data[i]='\0';

		}
	}

	else
	{
		/*if it is not empty*/
		temp = h[index];
		temp = memset(temp, '\0', sizeof(struct packet));
	  while(temp)
	  {	
		/*if the ip and protocol are same then just update the time stamp*/
		if((cmp = strcmp(temp->source_ip,ip))==0 && temp->protocol == protocol &&strcmp(temp->dest_ip,ip)&&temp->source_port==s_port &&
		temp->dest_port==d_port) 
		{
			for(i=0;htime[i]!='\0';i++)	
		  	 temp->time[i]=htime[i];
			/*increase the count value after updation*/
			++(temp->count);
			
			/*storing the data sent by the cient*/
			for(i=0;ch[i]!='\0';i++)
			   temp->data[i]=ch[i];
			   temp->data[i]='\0';

			return;

		}
		
		else if(temp->next==NULL)
			break;
		/*traversing or shifting to next node*/
		else 
		temp=temp->next;

	  } // end of while

		if(temp->next==NULL ) 
		{
			temp->next = (struct packet *) malloc( sizeof(struct packet) );

			if(temp->next ==NULL)
			{
				printf("malloc failed");
				exit(-1);
			}		

			temp=temp->next;

			
			if(protocol == TCP)
			   temp->protocol = TCP;
			else if(protocol == UDP)
			   temp->protocol = UDP;
			else
			{
				printf("\n\nWrong Protocol ");
				exit(-1);
			}

			for(i=0;i<MAX;i++)
		{
	   	   temp->source_ip=source_bin;
		    temp->dest_ip=dest_bin;
		
		temp->source_port=s_port;
		temp->dest_port=d_port;

		for(i=0;htime[i]!='\0';i++)	
		   temp->time[i]=htime[i];

		++(temp->count);

		temp->next=NULL;
		/*storing the data sent by the client*/
		for(i=0;buf[i]!='\0';i++)
		   temp->data[i]=ch[i];
		   temp->data[i]='\0';
		}
		
	}
		}	//end of if

	}	//end of else 


void delete_packet(struct packet *ptr, int source_bin,int dest_bin,int s_port,int d_port,char ch[],unsigned short protocol)
{
	unsigned char cmp;
	unsigned char index;
	unsigned char flag=0;
	struct packet *temp, *prev;
	
	key= packet(ip);
	index=key%MAX;
	temp=h[index];
	
	
	/**storing the previos location*/
	prev=temp;
	/*if the previous location points to null*/
	if(temp==NULL)
     	   printf( "no entry present\n" );
	else
	{
	   while(temp!=NULL)
	   {	
		/*compare the ip and protocol of which  to be deleted and that present in temp*/	
		if((cmp = strcmp(temp->source_ip,ip))==0 && temp->protocol == protocol &&strcmp(temp->dest_ip,ip)&&temp->source_port==s_port &&
	temp->dest_port==d_port) 
		{
			prev->next = temp->next;
			if(h[index] == temp)
			h[index] = temp->next;
			/*now move the index to the next node and free the temp*/
			temp = memset(temp, '\0', sizeof(struct packet));
			if(h[index] == temp)
			h[index] = temp->next;
			free(temp);
			temp=NULL;
			flag=1;
			break;
		}	
		else 
		{
			prev=temp;
			temp=temp->next;
		} // end of else 
	   }//end of while
	}//end of else 

	if(flag==1)
	printf("\nENTRY DELETED\n");
	else if(flag==0)
	printf("\nno entry found\n");


}
/*function for display*/
void display()
{
	unsigned short c;
	unsigned short count;
	unsigned char flag=0;
	struct packet *temp;

	for(c=0;c<65535;c++)
	   if(h[c]!=NULL)
		flag=1;
	
	if(flag==0) 
	printf("no entry\n" );
	else
	{
	printf("\n hash table");
	printf("\n\n");
	for(c=0;c<65535;c++)
	{
	   	count=0;
		temp=h[c];
	   	
	   	if(temp==NULL)
	     	   continue;
	   	else
	   	{
		   printf("\n\nINDEX :%d\n ", c);
		   while(temp!=NULL)
		   {		
			if(temp->protocol == TCP)
			{
			printf("ip address of source:%d\n",temp->source_ip);
			printf("protocol type of source  :%d\n",temp->protocol);
			printf("time:%s",temp->time);
			printf("port associated is %d",temp->source_port);
			printf("ip address of dest:%d\n",temp->dest_ip);
			printf("port associated is %d",temp->dest_port);
			printf("packet count is %d",temp->count);
			}
			else 
			{
			printf("ip address of source:%d\n",temp->source_ip);
			printf("protocol type of UDP source  :%d\n",temp->protocol);
			printf("time:%s",temp->time);
			printf("port associated is %d",temp->source_port);
			printf("ip address of dest:%d\n",temp->dest_ip);
			printf("port associated is %d",temp->dest_port);
			printf("packet count is %d",temp->count);
			temp=temp->next;
			}
		   }

	   	}//end of else 	     

	} // end of for loop
}
}
void lookup_packet(struct packet *ptr,int source_bin,int dest_bin,int s_port,int d_port,char ip[])
{
	int index;
	int var;
	char ip1[256];
	
		printf("enter the source ip address\n");
		scanf("%s",ip1);
		
		if(strcmp(ip1,ip)==0)
		{
			index=addition_digits(source_bin,dest_bin,s_port,d_port)%MAX;
			printf("packet with source address %s found on index %d and port %d\n ",ip,index,d_port);
		}
		else
		return;

}

