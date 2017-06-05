#include "sender.h"
void MAC_sender::init(string arg)
{
   eth_info.sll_family=PF_PACKET;
   eth_info.sll_ifindex=if_nametoindex(arg.c_str());//参数为网卡接口名称，可以是以太网或wlan
   
   fd=socket(PF_PACKET,SOCK_RAW,htons(ETH_P_ALL));
   if(fd<0)
   {
	 cout<<"socket SOCK_RAW failed:\n";
         perror("socket");
	 exit(EXIT_FAILURE);
   }	 
}

void MAC_sender::send(char *data,int size_data)
{
	send_num=sendto(fd,data,size_data,0,(struct sockaddr*)(&eth_info),sizeof(eth_info));
	if(send_num<0)
	{
		cout<<"sendto failed\n";
		perror("sendto");
		exit(EXIT_FAILURE);
	}
	cout<<"successful"<<endl;
}

void IP_sender::init(string arg)
{
  ip_info.sin_family=AF_INET;
  ip_info.sin_addr.s_addr=inet_addr(arg.c_str());
  
  fd=socket(AF_INET,SOCK_RAW,IPPROTO_RAW);
  if(fd<0)
   {
	 cout<<"socket SOCK_RAW failed:\n";
         perror("socket");
	 exit(EXIT_FAILURE);
 }
  int set=1;
  if(setsockopt(fd,IPPROTO_IP,IP_HDRINCL,&set,sizeof(set))<0)
  {
	  perror("setsockopt");
	  exit(EXIT_FAILURE);
  }
  
} 

void IP_sender::send(char *data,int size_data)
{
   send_num=sendto(fd,data,size_data,0,(struct sockaddr *)&ip_info,sizeof(ip_info));
	if(send_num<0)
	{
		cout<<"sendto failed\n";
		perror("sendto");
		exit(EXIT_FAILURE);
	}
	cout<<"successful"<<endl;
}

