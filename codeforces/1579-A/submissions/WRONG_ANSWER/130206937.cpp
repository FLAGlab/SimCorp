#include <bits/stdc++.h>
 
#define ll long long
using namespace std; 
 
 
 
int main() {
 
 int tt=1;
	cin>>tt;
 while(tt--){
	string s;
	cin>>s;
 int b=0;
 for(int i=0;i<s.size();i++)
 if(s[i]=='B')
	b++;
 if(s.size()%2==0&&b>=2&&b==s.size()/2)
	cout<<"YES";
 else
	cout<<"NO";
	cout<<endl;
 }
}
 
 
 
 
