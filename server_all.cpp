#include "controler.h"

int main(int argc,char *argv[])
{
	Controler control;
	int state=0;
	int cmd;
	string filename;
	string arg;
	basic_sender *sender1=NULL;
	char *senddata;
	int data_size;
	while(1)
	{
	switch(state)
	{
		case 0:
		{
			control.show_options(state);
		    cin>>cmd;
		    state=cmd;
		}
	      break;
	     case 1:
	     {
			 control.show_options(state);
	         cin>>cmd;
	         if(cmd==1)control.change_type_packet(MAC_packet);
	         else if(cmd==2)control.change_type_packet(IP_packet);
	         else if(cmd==3)control.change_type_packet(TCP_packet);
	         state=0;
		 }
		 break;
		 case 2:
		 {
		      control.show_options(state);
		      control.create_packet_file();
		       state=0;
		      cout<<"create successful\n";
		  }
	      break;
	     case 3:
	      {	  
			  cout<<"please input the filename:"<<endl;
			  cin>>filename;
			  control.show_options(state);
			  control.load_packet_file(filename);
			  control.print_IP();
		      state=0;
		  }
		  break;
		  case 4:
		  {
			  control.show_options(state);
			  senddata=control.formdata(data_size);
			  sender1=control.Createsender();
			  cout<<"please input the arg:if mac:interface name;if ip:ip_adress;"<<endl;
			  cin>>arg;
			  sender1->init(arg);
			  sender1->send(senddata,data_size);
			  state=0;
		  }
		  break;
      }
  }
      return 0;
  }
