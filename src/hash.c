#include "hash.h"

/*insertion of packet*/

void insert_packet(void *q)
{
	struct packet *ptr=(struct packet *p)
	int count=0,i,j;
	int source_bin=inet_addr(ptr->source_ip);
	int dest_bin=inet_addr(ptr->dest_ip);
	int s_port=ptr->source_port;
	int d_port=ptr->dest_port;
	struct packet *temp,*head,*ptr;
	int index;
	index=addition(source_bin,dest_bin,s_port,d_port)%MAX;
	printf("index %d\n",index);
	ma[index]=(struct hash *)malloc(sizeof(struct hash));
	//ifthe index position is empty
	if(ma[index]==NULL)
	{
		
		if(ma[index]==NULL)
		{
			printf("malloc failed\n");
			
			exit(0);
		}
		
		memset(ma[index],0,sizeof(struct hash));
		strcpy(ma[index]->info->time,ptr->time);
		struct hash  *p=ma[index];
		p->info->source_ip=ptr->source_ip;
		p->info->dest_ip=ptr->dest_ip;
		p->info->source_port=ptr->source_port;
		p->info->dest_port=ptr->dest_port;
		p->info->protocol=ptr->protocol;
		p->next=NULL;
		count++;
		printf("insertion done\n");
		printf("source ip:%s\n",p->info->source_ip);
		printf("destination ip:%s\n",p->info->dest_ip);
		printf("source port:%d\n",p->info->source_port);
		printf("destination port:%d\n",p->info->dest_port);
		printf("protocol:%s\n",p->info->protocol);
		printf("time stamp at which packet arrived is %s\n",p->info->time);
		return 0;
	}

	else
	{	
		/*if the postion is not empty*/
		while(ma[index]!=NULL)
		{
			if((ptr->source_ip==p->source_ip)&&(ptr->dest_ip==p->dest_ip)&&(ptr->dest_port==p->dest_port))
			{
				update_packet(p,packet);
				count++;
				return;
			}
			ma[index]=ma[index]->next;
		}
		struct hash  *p=ma[index];
		p=(struct hash *)malloc(sizeof(struct hash));
		memset(p,0,sizeof(struct hash));
		strcpy(p->info->time,ptr[time]);
		p->info=(struct hash *)malloc(sizeof(struct hash)); 
		p->info->source_ip=ptr->source_ip;
		p->info->dest_ip=ptr->dest_ip;
		p->info->source_port=ptr->source_port;
		p->info->dest_port=ptr->dest_port;
		p->info->protocol=ptr->protocol;
		p->next=NULL;
		count++;
		printf("insertion done\n");
		printf("source ip:%s\n",p->info->source_ip);
		printf("destination ip:%s\n",p->info->dest_ip);
		printf("source port:%d\n",p->info->source_port);
		printf("destination port:%d\n",p->info->dest_port);
		printf("protocol:%s\n",p->info->protocol);
		printf("time stamp at which packet arrived is %s\n",p->info->time);
		return 0;
	}
}


void update_packet(void *q)
{
	ma[index]->info->time=time(NULL);
	/*updating timestamp*/
	printf(" updated timestamp=%s",ma[index]->info->time);
}
void delete_packet(void *q)
{
	struct packet *ptr=struct packet *q;
	unsigned char cmp;
	unsigned char index;
	unsigned char flag=0;
	char ip_source[SIZE];
	struct packet *temp, *prev;
	
	index=addition(source_ip,dest_ip,s_port,d_port)%MAX;
	temp=ma[index];
	
	
	/**storing the previos location*/
	prev=temp;
	/*if the previous location points to null*/
	if(temp==NULL)
	{
     	       printf( "no entry present\n" );
	}
		printf("enter the source ip address which packet you have to delete\n");
		scanf(" %s",ip_source);
	else
	{
	   while(temp!=NULL)
	   {	
	
		/*compare the ip and protocol of which  to be deleted and that present in temp*/	
		if(ip_source==ptr->source_ip)
		{
			prev->next = temp->next;
			if(ma[index] == temp)
			ma[index] = temp->next;
			/*now move the index to the next node and free the temp*/
			temp = memset(temp, '\0', sizeof(struct packet));
			if(ma[index] == temp)
			ma[index] = temp->next;
			free(temp);
			temp=NULL;
			ma[index]->source_port=0;
			ma[index]->dest_port=0;
			printf("packet successfully deleted\n");
			
			
		}	
		else 
		{
			prev=temp;
			temp=temp->next;
			printf("the data entered is invalid\n");
		} // end of else 
	   }//end of while
	}//end of else 

	if(flag==1)
	printf("\nENTRY DELETED\n");
	else if(flag==0)
	printf("\nno entry found\n");


}

void lookup_packet(void *q)
{
	struct packet *ptr=struct packet *q;
	int index;
	int var;
	char ip1[SIZE];
	
		printf("enter the source ip address\n");
		scanf("%s",ip1);
		index=addition(source_ip,dest_ip,s_port,d_port)%MAX;
		if(ip1==ma[index]->source_ip)
		
			
		printf("packet with source address %s found on port %d and data %d\n ",ma[index]->info->source_ip,ma[index]->info->source_port,ma[index]->info->data);
		
		else
		printf("packet not found\n");
		return;

}
int addition(int source_ip,int dest_ip,int source_port,int dest_port)
{
	int sum;
	sum=source_ip+dest_ip+source_port+dest_port;
	return sum;
}

