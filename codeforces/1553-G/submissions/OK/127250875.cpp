#include<bits/stdc++.h>
#define maxn 150005
#define maxv 1000005
using namespace std;
 
int n, q, s, t, a[maxn], fa[maxv];
vector<int> pfac[maxv];
set<pair<int, int> > ss;
 
inline int read(){
 int s = 0, f = 1; char ch = getchar();
 while(ch<'0' || ch>'9'){if(ch=='-') f = -1; ch = getchar();}
 while(ch>='0' && ch<='9'){s = (s<<1) + (s<<3) + ch - '0'; ch = getchar();}
 return s * f;
}
 
int find(int x){
 return x == fa[x] ? x : fa[x] = find(fa[x]);
}
 
signed main(){
	n = read(), q = read();
 for(int i=1; i<=1000000; ++i) fa[i] = i;
 for(int i=2; i<=1000001; ++i){
 if(pfac[i].empty()){
 for(int j=i; j<=1000001; j+=i) pfac[j].push_back(i);
 }
 }
 for(int i=1, x; i<=n; ++i){
		a[i] = read();
 for(int j=0; j<pfac[a[i]].size(); ++j) fa[find(a[i])] = find(pfac[a[i]][j]);
 }
 for(int i=1, u, v; i<=n; ++i){
 vector<int> fac = pfac[a[i]+1];
		fac.push_back(a[i]);
 for(int j=0; j<fac.size(); ++j){
 for(int k=j+1; k<fac.size(); ++k){
				u = find(fac[j]), v = find(fac[k]);
 if(u!=v){
 if(u>v) swap(u, v);
					ss.insert({u, v});
 }
 }
 }
 }
 while(q--){
		s = read(), t = read();
		s = find(a[s]), t = find(a[t]);
 if(s>t) swap(s, t);
 if(s==t) puts("0");
 else if(ss.count({s, t})) puts("1");
 else puts("2");
 }
 return 0;
}
