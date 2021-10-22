#include<bits/stdc++.h>
using namespace std;
 
#define int long long
 
signed main() {
 int n;
 long long W, B, X;
 long long a[n + 1], b[n + 1];
	cin >> n >> W >> B >> X;
 for(int i = 1; i <= n; i++) cin >> a[i];
 for(int i = 1; i <= n; i++) cin >> b[i];
 long long dp[n + 1][10001];
 for(int i = 0; i <= n; i++) {
 for(int j = 0; j <= 10000; j++) {
			dp[i][j] = -1;
 }
 }
	dp[0][0] = W;
 int ans = -1;
 for(int i = 1; i <= n; i++) {
 // cout << i << endl;
 for(int j = 0; j <= 10000; j++) {
 long long maxx = W + j * B;
 for(int k = 0; k <= j and k <= a[i]; k++) {
 // cout << i << ' ' << j << ' ' << k << endl;
 if(dp[i - 1][j - k] != -1) {
 // cout << i - 1 << ' ' << j - k << endl;
 if(min(dp[i - 1][j - k] + X, W + (j - k) * B) - b[i] * k >= 0) {
						dp[i][j] = max(dp[i][j], min(min(W + (j - k) * B, dp[i - 1][j - k] + X) - b[i] * k, maxx));
						maxx += B;
						ans = max(ans, j);
 }
 }
 }
 }
 }
 /*for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= 10; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
	*/
	cout << ans << endl;
 return 0;
}
