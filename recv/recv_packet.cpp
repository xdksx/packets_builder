#include<sys/socket.h>
#include<sys/ioctl.h>
#include<linux/if_ether.h>
#include<net/if.h>
#include<netinet/in.h>
#include<linux/ip.h>
#include<linux/udp.h>
#include<linux/tcp.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include <arpa/inet.h>

#include<unistd.h>
using namespace std;
int main()
{ 
	int fd;
	//fd=socket(AF_INET,SOCK_PACKET,htons(0x0003));
	fd=socket(PF_PACKET,SOCK_RAW,htons(ETH_P_IP));
	
    char *ethname="lo";
    struct ifreq ifr;
    int i;
    strcpy(ifr.ifr_name,ethname);
    i=ioctl(fd,SIOCGIFFLAGS,&ifr);
    if(i<0)
    {
		close(fd);
		perror("cannot get flags\n");
		return -1;
	}
	ifr.ifr_flags|=IFF_PROMISC;
	i=ioctl(fd,SIOCSIFFLAGS,&ifr);
	 if(i<0)
    {
		perror("promiscuous can not set\n");
		return -2;
	}
	char ef[ETH_FRAME_LEN];
	struct ethhdr*p_ethhdr;
	int n;
	while(1)
	{
	p_ethhdr=(struct ethhdr*)ef;
	n=read(fd,ef,ETH_FRAME_LEN);
	
	
//	printf("dest_MAC:");
	for(i=0;i<ETH_ALEN-1;i++)
	{
	//	printf("%02x-",p_ethhdr->h_dest[i]);
	}
    // printf("%02x\n",p_ethhdr->h_dest[ETH_ALEN-1]);
	
	
	//printf("source_MAC:");
	for(i=0;i<ETH_ALEN-1;i++)
	{
	//	printf("%02x-",p_ethhdr->h_source[i]);
	}
  //   printf("%02x\n",p_ethhdr->h_source[ETH_ALEN-1]);
 //    printf("protocol:0x%04x", ntohs(p_ethhdr->h_proto));
     
    if(ntohs(p_ethhdr->h_proto)==0x0800)
     {
		 struct in_addr addr_1,addr_2;
		 
		 struct iphdr*p_iphdr=(struct iphdr*)(ef+ETH_HLEN);
		 memcpy(&addr_1,&p_iphdr->saddr,4);
		 memcpy(&addr_2,&p_iphdr->daddr,4);
		 printf("src ip:%s\n",inet_ntoa(addr_1));
		 printf("des ip:%s\n",inet_ntoa(addr_2));
	
 
 
    if(p_iphdr->protocol==6)
    {
		struct tcphdr* p_tcphdr=(struct tcphdr*)(p_iphdr+p_iphdr->ihl*4);
		printf("src　port:%d\n", ntohs(p_tcphdr->source));
		printf("dest　port:%d\n", ntohs(p_tcphdr->dest));
 
   } }}
  // for(int i=0;i<220;i++)printf("%d  ",ef[i]);
     return 0;
 }
	
	
	
	
	
	
		
