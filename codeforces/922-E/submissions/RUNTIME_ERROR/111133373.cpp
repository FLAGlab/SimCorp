#include<bits/stdc++.h>
// time-limit: 1000
 
using namespace std;
 
const int N = 1000;
const int MX = 10000;
int n, a[N];
long long cost[N];
long long w, b, x;
long long dp[N][MX + 1];
 
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> w >> b >> x;
 for(int i = 0;i < n;i ++) {
		cin >> a[i];
 }
 for(int i = 0;i < n;i ++) {
		cin >> cost[i];
 }
 int sm = 0;
 for(int i = 0;i < n;i ++) {
		sm += a[i];
 for(int j = 0;j <= MX;j ++) {
 if(j > sm) {
				dp[i][j] = -1;
 continue;
 }
 if(i == 0) {
				dp[i][j] = (w / cost[i] < j ? -1 : min(w + b * j, w - cost[i] * j + x));
 } else {
				dp[i][j] = -1;
 for(int k = 0;k <= min(j, a[i]);k ++) {
 if(dp[i - 1][j - k] != -1 && dp[i - 1][j - k] >= cost[i] * k) {
						dp[i][j] = max(dp[i][j], min(dp[i - 1][j - k] - cost[i] * k + x, w + b * j));
 }
 }
 }
 }
 }
 int ans = 0;
 for(int j = MX;j >= 0;j --) {
 if(dp[n - 1][j] != -1) {
			ans = j;
 break;
 }
 }
	cout << ans << '\n';
 return 0;
}
