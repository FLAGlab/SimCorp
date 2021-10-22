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
 int len=s.length();
 int sum=0;
 for(int i=0;i<len;i++)
 {
 if(s[i]=='A'||s[i]=='C')sum++;
 else sum--;
 }
 if(sum)puts("NO");
 else puts("YES");
 }
 } 
