#include <iostream>
using namespace std;int main(void){int a;cin>>a;for(int t=0;t<a;t++){int n,m,b=0,s=0;char c;cin>>n>>m;for(int i = 0;i<n;i++){cin>>c;b=b*10+c-'0';if(b%m==0){b = 0;s++;}else while(b-m>0)b-=m;}cout<<s<<endl;}return 0;}
