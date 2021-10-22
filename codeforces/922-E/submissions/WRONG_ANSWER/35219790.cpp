#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
const int mx = 1123, mc = 11234;
long long dp[2][mc];
int c[mx], cost[mx];
int n;
long long W, B, X;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> W >> B >> X;
 for(int i = 1; i <= n; i++){
		cin >> c[i];
 }
 for(int i = 1; i <= n; i++){
		cin >> cost[i];
 }
	memset(dp, -1, sizeof dp);
	dp[0][0] = W;
 for(int i = 1; i <= n; i++){
		memset(dp[i%2], -1, sizeof dp[i%2]);
 for(int j = 0; j <= c[i]; j++){
 for(int k = 0; j+k < mc; k++){
 if(dp[!(i%2)][k] != -1){
					dp[i%2][j+k] = max(dp[i%2][j+k], min(dp[!(i%2)][k] + (i != 1)*X, W+((j+k)*B)) - cost[i]*j);
 }
 }
 }
 }
 int ans = 0;
 for(int k = 0; k < mc; k++){
 if(dp[n%2][k] != -1) ans = max(ans, k);
 }
	cout << ans << endl;
}
