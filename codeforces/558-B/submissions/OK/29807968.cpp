#include<bits/stdc++.h>
using namespace std;
const int M=3e6;
long long int n,x,l=0,m=0,t=1e10,mr[M],ml[M],a[M],s[M];
signed main()
{
	cin >> n;
	fill(ml,ml+n+1,0);
	fill(s,s+n+1,0);
 for(int i=1; i<=n; i++)
 {
		cin >> a[i];
		x=a[i];
 if(ml[x]==0)
 {
			ml[x]=i;
 }
		mr[x]=i;
		s[x]++;
 }
 for(int i=1; i<=n; i++)
 {
		x=a[i];
 if(m<s[x])
 {
			m=s[x];
			l=x;
			t=mr[x]-ml[x];
 }
 else if(m==s[x] && t>mr[x]-ml[x])
 {
			t=mr[x]-ml[x];
			l=x;
 }
 }
	cout << ml[l] << ' ' << mr[l];
 return 0;
}
