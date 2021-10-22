#include<bits/stdc++.h>
using namespace std;
 
signed main()
{
 
int t;
cin>>t;
while(t--)
{
	string s;
 int count=0;
 int n=s.size();
	cin>>s;
 for(int i=0;i<s.size();i++)
 {
 if((s[i]=='A'&& s[i+1]=='B' )|| (s[i]=='B'&&s[i]=='C'))
		  n--;
 }
 if(n==0)
	cout<<"YES"<<endl;
 else
	cout<<"no"<<endl;
}
 
 
return 0;
 
}
 
