#include <iostream>
using namespace std;
 
const int inf = 1e9 + 7;
int dp[1005][10005];
int main() {
 int n, w, b, x, sum = 0, ans = 0;
	cin >> n >> w >> b >> x;
 int c[n], cost[n]; c[0] = 0;
 for(int i = 0; i < n; i++) {
		cin >> c[i];
		sum += c[i];
 }
 for(int i = 0; i < n; i++) cin >> cost[i];
 for(int i = 0; i <= n; i++) {
 for(int j = 0; j <= sum; j++) dp[i][j] = -inf;
 }
	dp[0][0] = 0;
 for(int i = 1; i <= n; i++) {
 for(int j = 0; j <= sum; j++) {
 for(int k = 0; k <= min(j, c[i-1]); k++) {
 if(dp[i-1][j-k] > -inf && min(dp[i-1][j-k] + x, w + (j - k) * b) - cost[i-1] * k >= 0) {
					dp[i][j] = max(dp[i][j], min(dp[i-1][j-k] + x, w + (j - k) * b) - cost[i-1] * k);
					ans = max(ans, j);
 }
 }
 }
 }
	cout << ans;
}
