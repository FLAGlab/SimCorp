#include <cstdio>
#include <unordered_set>
 
const int N = 200100;
int dv[1000100], prime[N], fa[N], tot;
void init(int n) {
 for (int i = 2; i <= n; i++) {
 if (!dv[i]) {
			prime[++tot] = i;
			dv[i] = tot;
 }
 for (int j = 1; j <= tot; j++) {
 const int p = prime[j];
 if (i * p > n) break;
			dv[i * p] = j;
 if (i % p == 0) break;
 }
 }
}
int getfa(int x) { return fa[x] == x ? x : fa[x] = getfa(fa[x]); }
int a[N], b[N][10], c[N];
 
std::unordered_set<int> edge[N];
 
bool test(int x, int y) {
	x = getfa(x), y = getfa(y);
 return edge[x].find(y) != edge[x].end();
}
int main() {
	init(1000001);
 int n, q;
	scanf("%d %d", &n, &q);
 for (int i = 1; i <= tot; i++) fa[i] = i;
 for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
 for (int j = a[i], t = 0; j > 1; t = dv[j], j /= prime[dv[j]])
 if (t) fa[getfa(t)] = getfa(dv[j]);
 for (int j = a[i] + 1, t = 0; j > 1; t = dv[j], j /= prime[dv[j]])
 if (t != dv[j]) b[i][++c[i]] = dv[j];
		b[i][0] = dv[a[i]];
 }
 for (int i = 1; i <= n; i++)
 for (int j = 0; j <= c[i]; j++) for (int k = 0; k <= c[i]; k++)
			edge[getfa(b[i][j])].insert(getfa(b[i][k]));
 for (int i = 1, x, y; i <= q; i++) {
		scanf("%d %d", &x, &y);
 if (getfa(dv[a[x]]) == getfa(dv[a[y]])) {
			puts("0");
 continue;
 }
 if (test(dv[a[x]], dv[a[y]])) {
			puts("1");
 continue;
 }
		puts("2");
 }
}
