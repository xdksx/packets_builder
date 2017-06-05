#include "packets.h"
void MAC_pro::Array_fill(unsigned char src[],unsigned char dst[],int num)
{
	for(int i=0;i<num;i++)
		dst[i]=src[i];
}
MAC_header MAC_pro::get_mac_header()
{
	return mac_header;
}
void  MAC_pro::fill_mac_header(MAC_header mac_header_fill)
{
	Array_fill(mac_header_fill.m_DstAdress,mac_header.m_DstAdress,6);
	Array_fill(mac_header_fill.m_SrcAdress,mac_header.m_SrcAdress,6);
	mac_header.m_upType=mac_header_fill.m_upType;
}

vector<string>& MAC_pro::get_mac_data()
{
	vector<string>& ret=mac_data;
	return ret;
}
void MAC_pro::fill_mac_data(vector<string> mac_data_fill)
{
	mac_data.swap(mac_data_fill);
}
void MAC_pro::print_mac_header()
{
	cout<<"srcadress:"<<mac_header.m_SrcAdress<<"\ndesadress:"<<mac_header.m_DstAdress<<"\nuptype:"<<mac_header.m_upType<<endl;
}

IP_header IP_pro::get_ip_header()
{
     return ip_header;
}

void IP_pro::fill_ip_header(IP_header ip_header_fill)
{
	ip_header.version_ip=ip_header_fill.version_ip;
        ip_header.header_length=ip_header_fill.header_length;
	ip_header.type_of_service=ip_header_fill.type_of_service;
	ip_header.total_length=ip_header_fill.total_length;
	ip_header.identifier=ip_header_fill.identifier;
	ip_header.flags=ip_header_fill.flags;
	ip_header.fragment_offset=ip_header_fill.fragment_offset;
	ip_header.ttl=ip_header_fill.ttl;
	ip_header.protocol=ip_header_fill.protocol;
	ip_header.header_checksum=ip_header_fill.header_checksum;
	Array_fill(ip_header_fill.source_address,ip_header.source_address,4);
	Array_fill(ip_header_fill.destination_address,ip_header.destination_address,4);
}

vector<string>& IP_pro::get_ip_data()
{
     vector<string>& ret=ip_data;
     return ret;
}

void IP_pro::fill_ip_date(vector<string> ip_data_fill)
{
	ip_data.swap(ip_data_fill);
}
