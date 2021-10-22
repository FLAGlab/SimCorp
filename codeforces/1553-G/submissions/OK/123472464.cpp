#include<bits/stdc++.h>
using namespace std;
 
constexpr int INF = 1e6 + 1;
 
struct dsu {
 vector <int> tt, sz;
	dsu(int n) : tt(n + 1, 0), sz(n + 1, 0) {
 for (int i = 1; i <= n ; ++i) {
			tt[i] = i;
			sz[i] = 1;
 }
 };
 
 int find(int x) {
 if (x != tt[x]) return tt[x] = find(tt[x]);
 return x;
 }
 
 void unite(int x, int y) {
		x = find(x); y = find(y);
 if (x == y) return ;
 if (sz[x] < sz[y]) swap(x, y);
		sz[x] += sz[y];
		tt[x] = y;
 }
};
 
signed main() {
 int n, q;
	scanf("%d%d", &n, &q);
 
 vector <vector <int>> prime_div(INF + 1);
 
 for (int d = 2; d <= INF ; ++d) {
 if (prime_div[d].empty()) {
 for (int i = d; i <= INF ; i += d)
				prime_div[i].push_back(d);
 }
 }
 
	dsu D(INF);
 vector <int> a(n);
 for (int i = 0; i < n ; ++i) {
		scanf("%d", &a[i]);
 for (auto it : prime_div[a[i]])
			D.unite(a[i], it);
 }
 
 map <pair <int, int>, bool> edge;
 for (int i = 0; i < n ; ++i) {
 set <int> s;
 for (auto it : prime_div[a[i] + 1])
			s.insert(D.find(it));
 
 int rad = D.find(a[i]);
 for (auto x : s)
			edge[{rad, x}] = edge[{x, rad}] = 1;
 for (auto x : s) for(auto y : s)
			edge[{x, y}] = 1;
 }
 
 while (q--) {
 int x, y;
		scanf("%d%d", &x, &y); --x; --y;
		x = D.find(a[x]); y = D.find(a[y]);
 if (x == y) printf("0\n");
 else if (edge.count({x, y})) printf("1\n");
 else printf("2\n");
 }
 
 return 0;
}
