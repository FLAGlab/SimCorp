#include <bits/stdc++.h>
 
#define Mod 1000000007
 
using namespace std;
 
const int N = 1e6 + 10;
 
int n, fa[N], tr[N][26], len[N], d[N], pre[N], las, nodeid, dp[N], g[N]; char s[N], t[N];
 
void ins(int c, int m) {
 int u = las;
 while (t[m - len[u] - 1] != t[m]) u = fa[u];
 int now = tr[u][c];
 if (!now) {
		now = ++nodeid;
 int v = fa[u];
 while (t[m - len[v] - 1] != t[m]) v = fa[v];
		fa[now] = tr[v][c];
		tr[u][c] = now;
		len[now] = len[u] + 2;
		d[now] = len[now] - len[fa[now]];
 if (d[now] == d[fa[now]]) pre[now] = pre[fa[now]];
 else pre[now] = fa[now];
 }
	las = nodeid;
}
 
inline int M(const int &o) {
 return o >= Mod ? o - Mod : o;
}
 
int main() {
	scanf("%s", s + 1); n = strlen(s + 1);
 if (n & 1) return puts("0"), 0;
 for (int i = 1; (i << 1) <= n; i++) t[i * 2 - 1] = s[i], t[i * 2] = s[n - i + 1];
	fa[0] = fa[1] = 1, len[0] = 0, len[1] = -1, nodeid = 1;
	dp[0] = 1;
 for (int i = 1; i <= n; i++) {
		ins(t[i] - 'a', i);
 for (int j = las; j > 1; j = pre[j]) {
			g[j] = dp[i - len[pre[j]] - d[j]];
 if (d[j] == d[fa[j]]) g[j] = M(g[j] + g[fa[j]]);
 if (!(i & 1)) dp[i] = M(dp[i] + g[j]);
 }
 }
	cout << dp[n] << endl;
 return 0;
} 
