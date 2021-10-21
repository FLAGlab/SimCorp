#include<iostream>
using namespace std;
int main()
{int a=0,b=0,c=0,n;
string s;
cin>>n;
for(int j=0;j<n;++j){
	cin>>s;
 for(int i=0;i<s.length();++i){
 if(s[i]=='A')
 ++a;
 else if(s[i]=='B')
      	  b++;
 else ++c;}
 if(b==(a+c))
       cout<<"YES"<<endl;
 else cout<<"NO"<<endl;}
return 0;}
