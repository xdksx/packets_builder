#include<iostream>
using namespace std;
int main()
{
 int a[10];
 for(int i=0;i<10;i++)a[i]=i+2;
 for(int i=0;i<10;i++)cout<<a[i]<<" ";
 
 int *b=a+3;
 cout<<b[1]<<" ";
 b[2]=1000;
 cout<<b[2]<<" "<<a[5]<<" ";
 return 0;
 }
