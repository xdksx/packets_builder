#include<vector>
#include<string>
#include<iostream>
using namespace std;
#pragma pack(1)
typedef struct MAC_header_a
{
	unsigned char m_DstAdress[6];
	unsigned char m_SrcAdress[6];
	short m_upType;     //上一层协议类型，如0x800表示上一层是ip,0x806为ARP
}MAC_header;

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
}TCP_header;

class MAC_pro
{
	private:
	    MAC_header mac_header;
	    vector<string> mac_data;
	public:
	    void Array_fill(unsigned char src[],unsigned char dst[],int num);
	    MAC_header get_mac_header();
	    void fill_mac_header(MAC_header mac_header_fill);
	    vector<string>& get_mac_data();
	    void fill_mac_data(vector<string> mac_data_fill);
	    void print_mac_header();
};

class IP_pro:public MAC_pro
{
	private:
	    IP_header ip_header;
	    vector<string> ip_data;
	public:
	   // IP(IP_header ip_header_i,vector<string> ip_data_i);
	    IP_header get_ip_header();
	    void fill_ip_header(IP_header ip_header_fill);
	    vector<string>& get_ip_data();
	    void fill_ip_date(vector<string> ip_data_fill);
	    void print_ip_header();
};
class tcp:public IP_pro
{
	private:
	   TCP_header tcp_header;
	   vector<string> tcp_data;
	public:
	  // Tcp_header(
	   void get_tcp_header();
	   void fill_tcp_header(TCP_header tcp_header_fill);
	   void get_tcp_data();
	   void fill_tcp_data(vector<string> tcp_data_fill);
 };

 
	
//从文件中取得数据并填充到结构体中的模块函数
//将头部和数据一起组成buf以供发送的函数
