#include<iostream>
#include<string>
#include<stdlib.h>
#include<vector>
#include<stdio.h>
using namespace std;
#pragma pack(1)
struct test
{
 unsigned char a:4;
 unsigned char b:4;
 short c;
 unsigned char d:4;
 unsigned char e:4;
};

int main()
{
  struct test tt;
  string aa("i");
  vector<string> bb;
  bb.push_back("a");
  bb.push_back("23");
  bb.push_back("14");
  bb.push_back("15");
  tt.a=aa[0];
  tt.b=bb[0][0];
  tt.c=(short)(atoi(bb[1].c_str()));
  cout<<sizeof(tt)<<endl;
  tt.d=atoi(bb[2].c_str());
  tt.e=atoi(bb[3].c_str());
  printf("%d  %d  %d  %d %d \n",tt.a,tt.b,tt.c,tt.d,tt.e);
  return 0;
}
