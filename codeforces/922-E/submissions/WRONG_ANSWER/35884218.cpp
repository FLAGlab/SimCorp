#include<bits/stdc++.h>
using namespace std;
 
int dp[1005][10005];
 
signed main() {
 int n, w, b, x, sum = 0, ans = 0;
	cin >> n >> w >> b >> x;
 int c[n], cost[n];
 for(int i = 0; i < n; i++) {
		cin >> c[i];
		sum += c[i];
 }
 for(int i = 0; i < n; i++) cin >> cost[i];
	memset(dp, -1, sizeof(dp));
	dp[0][0] = w;
 for(int i = 1; i <= n; i++) {
 for(int j = 0; j <= sum; j++) {
 for(int k = 0; k <= min(j, c[i-1]); k++) {
 if(dp[i-1][j-k] >= 0 && min(dp[i-1][j-k] + x, w + (j - k) * b) - cost[i-1] * k >= 0) {
					dp[i][j] = max(dp[i][j], min(dp[i-1][j-k] + x, w + (j - k) * b) - cost[i-1] * k);
					ans = max(ans, j);
 }
 }
 }
 }
	cout << ans;
}
