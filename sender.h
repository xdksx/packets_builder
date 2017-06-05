

#include<string>
#include<linux/if_packet.h>
#include<linux/if_ether.h>
 #include<sys/socket.h>
#include <sys/types.h>
#include<net/if.h>
#include <arpa/inet.h>
#include<iostream>
#include<errno.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
class basic_sender
{
	protected:
	   int fd;
	   int send_num;
	public:
	   virtual void init(string arg)=0;
	   virtual void send(char *data,int size_data)=0;
 };
 
 class MAC_sender:public basic_sender
 {
	  private:
	     struct sockaddr_ll eth_info;
	  public:
	     void init(string arg);
	     void send(char *data,int size_data);
 };
 
 class IP_sender:public basic_sender
 {
	 private:
	   struct sockaddr_in ip_info;
	 public:
	   void init(string arg);
	   void send(char *data,int size_data);
 };
  
