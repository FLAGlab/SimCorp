#include<bits/stdc++.h>
using namespace std;
int a[10];
int t;
int main()
{
	cin>>t;
	string s;
 while(t--)
 {
		memset(a,0,sizeof(a));
		cin>>s;
 for(int i=0;i<s.size();i++)a[s[i]-'A']++;
 if(a[0]+a[2]==a[1])cout<<"YES"<<endl;
 else cout<<"NO"<<endl;
 }
 return 0;
}
