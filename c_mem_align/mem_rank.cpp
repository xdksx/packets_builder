#include<iostream>
using namespace std;
#pragma pack(1)
struct test_t{
 int a;
 char b;
 short c;
 char d[6];
 };
 struct test_2{
	 int a;
	 char b;
	 char d;
	 char dd[5];
	 short c;

 };
 struct test_3{
	 int a;
	 char b;
	 short c;
	 char d;
 };
  struct test_4{
	 int a;
	 char b;
	 short c:8;
	 char d;
	// char e;
	// char j[3];
	 short f:8;
 };
   struct test_5{
	 unsigned char a:4;
	 unsigned char b:4;
	 unsigned char addr[4];
	 unsigned char c:4;
	 unsigned int d:12;
	// char e;
	// char j[3];
	 //short f:8;
 };
 
int main()
{
  cout<<"int:"<<sizeof(int)<<endl;
  cout<<"char:"<<sizeof(char)<<endl;
  cout<<"short:"<<sizeof(short)<<endl;
  cout<<"test:"<<sizeof(struct test_t)<<endl;
  cout<<"test_2:"<<sizeof(struct test_2)<<endl;
  cout<<"test_3:"<<sizeof(struct test_3)<<endl;
   cout<<"test_4:"<<sizeof(struct test_4)<<endl;
   cout<<"test_5:"<<sizeof(struct test_5)<<endl;
  return 0;
 }
