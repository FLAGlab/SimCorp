#include<bits/stdc++.h>
using namespace std;
int t;
signed main()
{
	scanf("%d",&t);
	string s;
 while(t--)
 {
		cin>>s;
 int cnt[3]={0,0,0};
 for(int i=0;i<s.size();i++)
			cnt[s[i]-'A']++;
 if(cnt[0]+cnt[2]==cnt[1]) puts("YES");
 else puts("NO");
 }
 return 0;
}
