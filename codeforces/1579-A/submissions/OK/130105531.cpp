#include<bits/stdc++.h>
using namespace std;
int T;
int a[9];
string s;
 
int main()
{
	cin>>T;
 while(T--)
 {
		cin>>s;
		memset(a,0,sizeof(a));
 for(int i=0;i<s.length();i++)
			a[s[i]-'A']++;
 if(a[0]+a[2]==a[1]) cout<<"YES\n";
 else cout<<"NO\n";
 }
 return 0;
}
