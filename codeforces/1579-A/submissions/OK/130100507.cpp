#include<bits/stdc++.h> 
using namespace std;
const int N=1e5+5; int T,i,s,t,n; char st[N];
int main() {
	scanf("%d",&T);
 for (;T--;) {
		scanf("%s",st),n=strlen(st),s=0,t=0;
 for (i=0;i<n;i++)
 if (st[i]==66) s++; else t++;
 if (s==t) puts("YES"); else puts("NO");
 }
}
