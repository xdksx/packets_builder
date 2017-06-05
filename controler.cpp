#include "controler.h"
#include <stdio.h>
#include <stdlib.h>
void Controler::show_options(int state)
{
	switch(state)
	{
	 case 0:
		 {
			  cout<<"1  select packet type:"<<endl;
                          cout<<"2  get standard packet_file"<<endl;
                          cout<<"3  load standard packet_file:"<<endl;
		          cout<<"4 send file"<<endl;
		 }
		 break;
         case 1:
	  {
                cout<<" 1   MAC"<<endl;
		cout<<" 2   IP"<<endl;
		cout<<" 3   TCP"<<endl;
	  }
	   	break;
	 case 2:
		cout<<"getting file....."<<endl;
	        break;
	 case 3:
	       cout<<"loading file...."<<endl;
               break;
         case 4:
               cout<<"sending file...."<<endl;
               break;
	}
}

int Controler::create_packet_file()
{ 
   ofstream out;
   out.open("pack",ofstream::out);
   switch(type_packet)
   {
       case MAC_packet:
       {
	  out<<"m_DstAdress:\n";
	  out<<"m_SrcAdress:\n";
	  out<<"m_upType:\n";
	  out<<"data:\n";
       }
       break;
       case IP_packet:
       {
	  out<<"version_ip:\n";
          out<<"header_length:\n";
	  out<<"type_of_service:\n";
	  out<<"total_length:\n";
	  out<<"identifier:\n";
	  out<<"flags:\n";
	  out<<"fragment_offset:\n";
	  out<<"ttl:\n";
	  out<<"protocol:\n";
	  out<<"header_checksum:\n";
	  out<<"source_address:\n";
	  out<<"destination_address:\n";
	  out<<"data:\n";
       }
       break;
       case TCP_packet:
       {
	  out<<"a:\n";
       }
       break;
   }
      out.close();
      cout<<"hree";
      return 0;
}

void Controler::char_to_chararray(unsigned char src[],char dst[],int num)
{
	for(int i=0;i<num;i++)
	dst[i]=src[i];
} 
 void Controler::str_to_chararray(string src,char dst[],int num)
 {
	 for(int i=0;i<num;i++)
               dst[i]=src[i];
} 
void Controler::fill_mac_header(vector<int> packet_raw)
{
     for(int i=0;i<6;i++)mac_header_con.m_DstAdress[i]=packet_raw[i];
     for(int j=0;j<6;j++)mac_header_con.m_SrcAdress[j]=packet_raw[j+6];
     mac_header_con.m_upType=packet_raw[12];
     data=packet_raw[13];
}

void Controler::fill_ip_header(vector<int> packet_raw)
{
    ip_header_con.version_ip=packet_raw[0];
    ip_header_con.header_length=packet_raw[1];
    ip_header_con.type_of_service=packet_raw[2];
    ip_header_con.total_length=packet_raw[3];
    ip_header_con.identifier=packet_raw[4];
    ip_header_con.flags=packet_raw[5];
    ip_header_con.fragment_offset=packet_raw[6];
    ip_header_con.ttl=packet_raw[7];
    ip_header_con.protocol=packet_raw[8];
    ip_header_con.header_checksum=packet_raw[9];
    for(int i=0;i<4;i++)ip_header_con.source_address[i]=packet_raw[i+10];
    for(int j=0;j<4;j++)ip_header_con.destination_address[j]=packet_raw[j+14];
  //  data=packet_raw[18];
}
void Controler::fill_tcp_header(vector<int> packet_raw)
{
	;
}
void Controler::load_packet_file(string filename)//读取参数的函数
{
	    ifstream in(filename.c_str());
	    string tmp;
	    int packet_data;
	    vector<int> packet_raw;
	    string data_send;
	    while(in>>tmp)
	    {
			cout<<tmp<<"  -  \n";
			if(tmp.compare("data:")==0)
			{
				in>>data_send;
				continue;
			}
		    in>>packet_data;
		    cout<<packet_data<<"  +  "<<endl;
		    packet_raw.push_back(packet_data);
	    }
	    for(size_t t=0;t<packet_raw.size();t++)cout<<packet_raw[t]<<" ";
	   switch(type_packet)
	    {
		  case MAC_packet:
		    fill_mac_header(packet_raw);
                    break;
		  case IP_packet:
		  {
		     fill_ip_header(packet_raw);
		     data=data_send;
		 }
		    break;
		  case TCP_packet:
		    fill_tcp_header(packet_raw);
		    break;
	    } 
}
basic_sender* Controler::Createsender()
{
	basic_sender* result=NULL;
  switch(type_packet)
	    {
		  case MAC_packet:
		    result=new MAC_sender();
             break;
		  case IP_packet:
		    result=new IP_sender();
		    break;
		  case TCP_packet:
		    break;
	    }
       return result;
}


 char* Controler::formdata(int &data_size)
 {
	 char senddata[1024];
	 char *retu=senddata;
	  switch(type_packet)
	    {
		  case MAC_packet:
		    {
				char_to_chararray(mac_header_con.m_DstAdress,senddata,6);
				char_to_chararray(mac_header_con.m_SrcAdress,senddata+6,6);
				senddata[13]=mac_header_con.m_upType&0x00FF;
				senddata[12]=mac_header_con.m_upType>>8;
				str_to_chararray(data,senddata+14,data.size());
				data_size=14+data.size();
			}
             break;
		  case IP_packet:
		    {
				char fram=0;
				//先赋值高四位，接着左移４位之后，将高四位置于高位，之后再和低四位或一下，即可
				senddata[0]=ip_header_con.version_ip;
				senddata[0]=senddata[0]<<4;
				senddata[0]=senddata[0]|ip_header_con.header_length;
				
				senddata[1]=ip_header_con.type_of_service;
				senddata[3]=ip_header_con.total_length&0x00FF;
				senddata[2]=ip_header_con.total_length>>8;
				
				senddata[5]=ip_header_con.identifier&0x00FF;
				senddata[4]=ip_header_con.identifier>>8;
				
				senddata[6]=ip_header_con.flags;
				senddata[6]=senddata[6]<<4;
				senddata[6]=senddata[6]|(ip_header_con.fragment_offset>>8);
				
				fram=fram|ip_header_con.fragment_offset;
				senddata[7]=fram;
				senddata[8]=ip_header_con.ttl;
				senddata[9]=ip_header_con.protocol;
				
				senddata[11]=ip_header_con.header_checksum&0x00FF;
				senddata[10]=ip_header_con.header_checksum>>8;
				char_to_chararray(ip_header_con.source_address,senddata+12,4);
				char_to_chararray(ip_header_con.destination_address,senddata+16,4);
				str_to_chararray(data,senddata+20,data.size());
				data_size=20+data.size();
			}
		    break;
		  case TCP_packet:
		    break;
	    }
	    cout<<"form_reuslt:";
	    for(int j=0;j<data_size;j++)printf("%u ",senddata[j]);
	    cout<<endl;
	    return retu;
	}
