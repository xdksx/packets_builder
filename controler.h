#include "packets.h"
#include <fstream>
#include "sender.h"
//此类实现
//1 用户UI交互控制，
//2 根据指令生成包格式规范文件让用户填充，读取包格式规范文件（可以使用工厂模式）
//3 使用工厂模式生成特定对象，并且填充对象的数据属性
//4 生成服务器，让服务器发送数据　或者这一步也可以是利用通信方式传输给服务器对象
enum packet_type
{
    MAC_packet=0,
    IP_packet=1,
    TCP_packet=2
};
class Controler//主要部分可以是一个状态机来控制用户的操作过程
{
	private:
	    packet_type type_packet=IP_packet;
	    MAC_header mac_header_con;
	    IP_header ip_header_con;
	    TCP_header tcp_header_con;
	    string data;
	public:
	    void change_type_packet(packet_type type_packet_in){type_packet=type_packet_in;}
	    void fill_mac_header(vector<int> packet_raw);
	    void fill_ip_header(vector<int> packet_raw);
	    void fill_tcp_header(vector<int> packet_raw);
	    void str_to_chararray(string src,char dst[],int num);
	    void char_to_chararray(unsigned char src[],char dst[],int num);
	    	//显示出可以操作的选项．即在用户在终端打开程序后显示的(1.选择协议包. 2.....),所处状态不同，显示的可选项也不同
	    void show_options(int state);
	    //生成数据包格式规范文件:记得先将类型付给本地变量属性成员
	    int create_packet_file(); //可以使用头文件包含协议类型和数字的宏或者就这样用枚举,
	    //读取包格式规范文件:
	    void load_packet_file(string filename);
        basic_sender* Createsender();
        char* formdata(int &data_size);
        void print_IP(){
			printf("%d  %d  %d  %d  %d  %d  %d  %d  %d  %d   ", ip_header_con.version_ip,ip_header_con.header_length,ip_header_con.type_of_service,ip_header_con.total_length,ip_header_con.identifier,ip_header_con.flags,ip_header_con.fragment_offset,ip_header_con.ttl,ip_header_con.protocol,ip_header_con.header_checksum);
            for(int i=0;i<4;i++)printf("%d ",ip_header_con.source_address[i]);
            for(int i=0;i<4;i++)printf("%d ",ip_header_con.destination_address[i]);
            cout<<data;
		}
};

