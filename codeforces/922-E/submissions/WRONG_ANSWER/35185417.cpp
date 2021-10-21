#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[1010][10010];
int c[10010], cost[10010], sum[10010];
int main(void)
{
	memset(dp, -1, sizeof(dp));
 int n, w, b, x;
	cin >> n >> w >> b >> x;
 int i, j, k;
 for (i = 1; i <= n; i++)
 {
		cin >> c[i];
		sum[i] = sum[i-1] + c[i];
 }
 for (i = 1; i <= n; i++)
 {
		cin >> cost[i];
 }
	dp[0][0] = w;
 int res = 0;
 for (i = 1; i <= n; i++)
 {
 for (j = 0; j <= sum[i]; j++)
 {
 for (k = 0; k <= c[i] && k <= j; k++)
 {
 
 if (dp[i-1][j-k] < 0) continue;
				dp[i][j] = max(dp[i][j], min(dp[i-1][j-k]+x, (ll)w + (j-k) * b) - cost[i]*k); 
 if (dp[i][j] >= 0) res = max(res, j);
 }
 }
 }
	cout << res;
}
