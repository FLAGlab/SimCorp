#include<bits/stdc++.h>
using namespace std;
signed main()
{
 int t;
	cin>>t;
 while(t--)
 {
		string s;
		cin>>s;
 int _=0;
 for(int i=0;i<s.size();i++)
 {
 if(s[i]=='B') _++;
 }
 if(_==(s.size()+1)/2) cout<<"YES"<<endl;
 else cout<<"NO"<<endl;
 }
 return 0;
}
