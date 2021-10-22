#include<bits/stdc++.h>
 
using namespace std;
 
string s;
int co[3];
 
signed main()
{
 int t;
	cin >> t;
 while(t--)
 {
		cin >> s;
		memset(co,0,sizeof co);
 for(int i=0;i<s.size();i++)
			co[s[i]-'A']++;
 if(co[1]==co[0]+co[2])
			puts("YES");
 else
			puts("NO");
 }
}
