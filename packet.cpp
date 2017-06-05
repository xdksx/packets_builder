#include <iostream>
#include <string>
#include <vector>
using namespace std;
#pragma pack(1)
typedef struct IP_header_a
{
	unsigned char version_ip:4;
	unsigned char header_length:4;
	unsigned char type_of_service;
	short total_length;
	
	short identifier;
	unsigned char flags:4;
	unsigned int fragment_offset:12;
	
	unsigned char ttl;
	unsigned char protocol;
	short header_checksum;
	
	unsigned char source_address[4];
	unsigned char destination_address[4];
} IP_header;

typedef struct Tcp_header_a
{
	int a;
}Tcp_header;

class IP
{
	private:
	    IP_header ip_header;
	    vector<string> ip_data;
	public:
	   // IP(IP_header ip_header_i,vector<string> ip_data_i);
	    void get_ip_header();
	    void fill_ip_header(IP_header ip_header_fill);
	    void get_ip_data();
	    void fill_ip_date(vector<string> ip_data_fill);
};
class tcp:public IP
{
	private:
	   Tcp_header tcp_header;
	   vector<string> tcp_data;
	public:
	  // Tcp_header(
	   void get_tcp_header();
	   void fill_tcp_header(Tcp_header tcp_header_fill);
	   void get_tcp_data();
	   void fill_tcp_data(vector<string> tcp_data_fill);
 };
	   
class build_packets
{
	public:
	   int init(string proctcol,string filename);
	   int build();  //根据协议类型选择填充的协议数据包
	   IP ip;
	   tcp tcp;
	   string protocol;
 };
 
class server
{
	public:
	  void send();
}
server::send()
{
    int fd=0;
    struct sockaddr_ll eth_info;
    eth_info.sll_family=PF_PACKET；
    eht_info.sll_ifindex=if_nametoindex("ppp0");
    fd=socket(PF_PACKET,SOCK_DRAW,htons(ETH_P_IP));
    if(fd<0)
    {
		cout<<"socket error"<<endl;
		exit(1);
	}
	getdata_buf();
	num=sendto();
	
}
	   
	   
//本轮子要实现的功能如下：
/*  实现一个程序，第一部分是构建各种类型的数据包，第二部分是发送对应数据包和接收响应的服务器,具体要进行的内容，通过参数传递*/
int main(int argc,char *argv[])
{
	cout<<"ip_header_length:"<<sizeof(IP_header)<<endl;
	//比较参数１是什么协议
	build_packets build;
	build.init();
	
	return 0;
}
	
//从文件中取得数据并填充到结构体中的模块函数
//将头部和数据一起组成buf以供发送的函数
