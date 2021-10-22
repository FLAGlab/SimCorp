#include<bits/stdc++.h>
using namespace std;
int T;
string s;
signed main()
{
	scanf("%d",&T);
 while(T--) 
 {
		cin>>s;
 int len=s.size(),ans=0;
 for(int i=0;i<len;i++)
 if(s[i]=='B') ans++;
 else ans--;
 if(ans) printf("NO\n");
 else printf("YES\n");
 } 
 return 0;
}
