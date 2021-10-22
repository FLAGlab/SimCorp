#include<bits/stdc++.h>
using namespace std;
 
 
signed main()
{
 int n;
	cin>>n;
	string s;
	cin>>s;
 int c=0,diff;
 for(int i=0;i<s.size();i++)
 if(s[i]=='B') c++;
	diff=s.size()-c;
 if(diff==c) cout<<"YES"<<endl;
 else cout<<"NO"<<endl;
 return 0;
}
