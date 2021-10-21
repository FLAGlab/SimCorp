#include<bits/stdc++.h>
using namespace std;
 
int main()
{
 int t;
	cin>>t;
 while(t--)
 {
		string s;
		cin>>s;
 
 int ac=0,b=0;
 for(int i=0;i<s.length();i++)
 if(s[i]=='B')
		b++;
 else
		ac++;
 
 if(ac==b)
		cout<<"YES\n";
 else
		cout<<"NO\n";
 
 }
 
}
 
