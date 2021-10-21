#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, x, y, q, cnt, a[N], lst[N], p[N], id[N], vis[N], fa[N]; unordered_set <int> edge[N / 8];
inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
int main() {
	scanf("%d%d", &n, &q);
 for (int i = 2; i <= 1e6 + 1; ++ i) {
 if (!vis[i]) p[++ cnt] = lst[i] = fa[i] = i;
 for (int j = 1; i * p[j] <= 1e6 + 1 && j <= cnt; ++ j) {
			lst[i * p[j]] = p[j], vis[i * p[j]] = 1; if (i % p[j] == 0) break;
 }
 }
 for (int i = 1; i <= n; ++ i) {
		scanf("%d", a + i); int x = a[i], pre = 0;
 while (x > 1) { int pr = lst[x]; x /= pr; if (pre) fa[find(pr)] = find(pre); pre = pr; }
 }
 for (int i = 1, tot = 0; i <= 1e6 + 1; ++ i) if (fa[i] == i) id[i] = ++ tot;
 for (int i = 1; i <= n; ++ i) {
 int pr = id[find(lst[a[i]])], r = a[i] + 1; vector <int> fac; fac.push_back(pr);
 while (r > 1) { int pl = lst[r]; r /= pl; fac.push_back(id[find(pl)]); }
 for (auto x : fac) for (auto y : fac) edge[x].insert(y);
 }
 while (q --) {
		scanf("%d%d", &x, &y), x = id[find(lst[a[x]])], y = id[find(lst[a[y]])];
		printf("%d\n", x == y ? 0 : (edge[x].find(y) == edge[x].end() ? 2 : 1));
 }
 return 0;
}
