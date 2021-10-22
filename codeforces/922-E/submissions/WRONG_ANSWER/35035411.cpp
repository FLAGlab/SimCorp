#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
 
int n, w, b, x;
ll dp[1010][10010];
int c[1010], cost[1010];
signed main(){
	cin >> n >> w >> b >> x;
 for(int i = 1; i <= n; i++) cin >> c[i];
 for(int i = 1; i <= n; i++) cin >> cost[i];
 
	memset(dp, -1, sizeof(dp));
	dp[0][0] = w;
 for(int i = 1; i <= n; i++){
 for(int j = 0; j <= 10000; j++){
 if(dp[i - 1][j] == -1) continue;
 for(int k = 0; k <= c[i]; k++){
 if(cost[i] * k <= dp[i - 1][j]){
					dp[i][j + k] = max(dp[i][j + k], min(dp[i - 1][j] - cost[i] * k + x, w + b * 1ll * (j + k)));
 }
 }
 }
 }
 int ans = 0;
 for(int i = 0; i <= 10000; i++) if(dp[n][i] != -1) ans = max(ans, i);
	cout << ans << endl;
 return 0;
}
