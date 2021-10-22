#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int c[1005], cost[1005];
LL dp[1005][10005];
 
signed main(){
	memset(dp, -1, sizeof(dp));
 int n, W, B, X;
	scanf("%d%d%d%d", &n, &W, &B, &X);
 for(int i=1;i<=n;i++){
		scanf("%d", &c[i]);
 }
 for(int i=1;i<=n;i++){
		scanf("%d", &cost[i]);
 }
	dp[0][0] = W;
 for(int i=1;i<=n;i++){
 for(int j=0;j<=10000;j++){
 if(dp[i-1][j] == -1) continue;
 for(int k=0;k<=c[i];k++){
				dp[i][j+k] = max(dp[i][j+k], dp[i-1][j] - (LL)k*cost[i]);
 if(dp[i][j+k] < 0) dp[i][j+k] = -1;
 }
 }
 for(int j=0;j<=10000;j++){
 if(dp[i][j] == -1) continue;
			dp[i][j] = min(dp[i][j]+X, W + (LL)j*B);
 }
 }
 
 int ans = 0;
 for(int i=0;i<=20;i++){
 if(dp[n][i] != -1){
			ans = i;
 }
 }
 
	printf("%d\n", ans);
}
