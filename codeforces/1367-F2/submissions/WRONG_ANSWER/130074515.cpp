#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn = 2e5 + 50;
 
int a[maxn], b[maxn];
 
int dp[maxn][3];
 
int l[maxn], r[maxn];
 
int num[maxn];
 
int pos[maxn];
 
signed main()
{
 register int T; cin >> T;
 while (T--)
 {
 register int n; cin >> n;
 for (register int i = 1; i <= n; ++i)
		  cin >> a[i], b[i] = a[i], dp[i][0] = dp[i][1] = dp[i][2] = l[i] = r[i] = num[i] = 0;
		sort (b + 1, b + n + 1);
 register int cnt = unique(b + 1, b + n + 1) - (b + 1);
 for (register int i = 1; i <= n; ++i)
 {
			a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
			r[a[i]] = i;
 if (!l[a[i]]) l[a[i]] = i, pos[a[i]] = i;
 ++num[a[i]];
 }
 register int x = -1;
 for (register int i = 1; i <= n; ++i) 
 {
			dp[i][0] = dp[pos[a[i]]][0] + 1;
			dp[i][1] = max(dp[pos[a[i]]][1] + 1, max(dp[pos[a[i] - 1]][0] + 1, dp[pos[a[i] - 1]][2] + 1));
 if (i == r[a[i]]) dp[i][2] = dp[l[a[i]]][1] + num[a[i]] - 1;
			pos[a[i]] = i;
 for (register int j = 0; j < 2; ++j) x = max(x, dp[i][j]);
 }
 		printf("%d\n", n - x);
 }
 return 0;
}
