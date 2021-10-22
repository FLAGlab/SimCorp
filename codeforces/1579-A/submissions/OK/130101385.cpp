#include<bits/stdc++.h>
using namespace std;
int T;
char s[105];
signed main() {
	cin>>T;
 while(T--) {
		scanf("%s",s);
 int n = strlen(s);
 int sum = 0;
 for(int i=0;i<n;i++)
 if(s[i] == 'B') sum++;
 if(n == sum*2) puts("YES");
 else puts("NO");
 }
 return 0;
}
