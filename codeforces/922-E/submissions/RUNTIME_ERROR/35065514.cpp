#include<bits/stdc++.h>
#pragma comment(linker, "/STACK:536870912")
#pragma warning(disable:4996)
 
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
 
#define all(v) v.begin(), v.end()
#define setv(ar, val) memset(ar, val, sizeof(ar));
#define ll long long int
#define ull unsigned long long int
#define PI 3.1415926535897932384626433832795
using namespace std;
 
const int N = 1e3 + 50, M = 1e4 + 50;
ll dp[N][M], cost[N], c[N];
 
signed main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll n, w, b, x;
	scanf("%lld%lld%lld%lld", &n, &w, &b, &x);
 
 for (int i = 0; i < n; i++)
		scanf("%lld", &c[i]);
 for (int i = 0; i < n; i++)
		scanf("%lld", &cost[i]);
 
 int s = 0;
	setv(dp, -1);
	dp[0][0] = w;
 for (int i = 0; i < n; i++) {
 for (int j = 0; j <= s; j++) {
 if (dp[i][j] == -1)
 continue;
 for (int k = min(c[i], dp[i][j] / cost[i]); k >= 0; k--) {
				dp[i + 1][j + k] = max(dp[i + 1][j + k], min(dp[i][j] - k * cost[i] + x, (j + k) * b + w));
 }
 }
		s += c[i];
 }
 
 for (int i = s; i >= 0; i--) {
 if (dp[n][i] >= 0) {
			printf("%d", i);
 return 0;
 }
 }
 
 
 
 
 return 0;
}
