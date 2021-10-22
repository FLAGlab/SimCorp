#include<bits/stdc++.h>
#define maxn 150005
#define maxv 1000005
using namespace std;
 
int n, q, s, t, a[maxn], f[maxv], g[maxv];
set<pair<int, int> > ss;
 
inline int read(){
 int s = 0, f = 1; char ch = getchar();
 while(ch<'0' || ch>'9'){if(ch=='-') f = -1; ch = getchar();}
 while(ch>='0' && ch<='9'){s = (s<<1) + (s<<3) + ch - '0'; ch = getchar();}
 return s * f;
}
 
int find(int x){
 return x == f[x] ? x : f[x] = find(f[x]);
}
 
signed main(){
	n = read(), q = read();
 for(int i=1; i<=1000001; ++i) f[i] = i;
 for(int i=1, x; i<=n; ++i){
		x = a[i] = read();
 for(int j=2; j*j<=x; ++j){
 if(x%j==0){
				f[find(a[i])] = find(j);
 while(x%j==0) x /= j;
 }
 }
 if(x>1) f[find(a[i])] = find(x);
 }
 for(int i=1, x, u, v; i<=n; ++i){
		x = a[i] + 1;
 for(int j=2; j*j<=x; ++j){
 if(x%j==0){
				u = find(a[i]), v = find(j);
 if(u!=v){
 if(u>v) swap(u, v);
					ss.insert({u, v});
 }
 while(x%j==0) x /= j;
 }
 }
 if(x>1){
			u = find(a[i]), v = find(x);
 if(u!=v){
 if(u>v) swap(u, v);
				ss.insert({u, v});
 }
 }
 }
 while(q--){
		s = find(a[read()]), t = find(a[read()]);
 if(s>t) swap(s, t);
 if(s==t) puts("0");
 else if(ss.count({s, t})) puts("1");
 else puts("2");
 }
 return 0;
}
