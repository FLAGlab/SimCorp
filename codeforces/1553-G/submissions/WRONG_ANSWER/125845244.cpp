#include<bits/stdc++.h>
 
#define re register
#define N 1000005
 
using namespace std;
typedef pair<int, int> P;
int n, q, gs, cnt, tot, a[N], p[N], f[N], id[N], pr[N], mip[N];
P g[5*N];
int find(int x){ return (f[x] == x) ? f[x] : f[x] = find(f[x]); }
signed main(){
//	freopen("D.out", "w", stdout);
 for(re int i = 2; i < 1000001; ++i){
 if(!mip[i]){ mip[i] = i; pr[++tot] = i;}
 for(re int j = 1; j <= tot; ++j){
 if(pr[j] > mip[i] || pr[j] * i > 1000001) break;
			mip[pr[j] * i] = pr[j];
 }
 }
	scanf("%d%d", &n, &q);
 for(re int i = 1; i <= n; ++i){
		f[i] = i;
		scanf("%d", &a[i]); int tp = a[i];
 while(tp > 1){
 if(id[mip[tp]]) f[find(id[mip[tp]])] = find(i);
			id[mip[tp]] = i; tp /= mip[tp];
 }
 }
 for(re int i = 1; i <= n; ++i){
 int tp = a[i] + 1; p[gs = 1] = find(i);
 while(tp > 1) p[++gs] = id[mip[tp]], tp /= mip[tp];
		sort(p + 1, p + gs + 1);
		gs = unique(p + 1, p + gs + 1) - p - 1;
 for(re int i = 1; i <= gs; ++i)
 for(re int j = i + 1; j <= gs; ++j)
				g[++cnt] = P(p[i], p[j]);
 }
	sort(g + 1, g + cnt + 1);
 while(q--){
 int x, y; scanf("%d%d", &x, &y); x = find(x), y = find(y);
 if(x == y) puts("0");
 else{
 if(x > y) swap(x, y);
			P pos = *lower_bound(g + 1, g + cnt + 1, P(x, y));
 if(pos.first == x && pos.second == y) puts("1");
 else puts("2");
 }
 }
 return 0;
}
