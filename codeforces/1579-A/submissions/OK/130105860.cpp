#include<bits/stdc++.h>
using namespace std;
 
int T,a,b,c;
string s;
signed main()
{
	scanf("%d",&T);
 while(T--){
		cin>>s,a=b=c=0;
 for(int i=0;i<s.size();++i){
 if(s[i]=='A')a++;
 if(s[i]=='B')b++;
 if(s[i]=='C')c++;
 }
		puts(b==a+c?"YES":"NO");
 }
 } 
