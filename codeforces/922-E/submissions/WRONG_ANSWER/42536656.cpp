#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int c[1005], cost[1005];
LL dp[1005][10005];
 
int main(){
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
				dp[i][j+k] = max(dp[i][j+k], min((LL)W, dp[i-1][j] + X) - (LL)k*cost[i]);
 if(dp[i][j+k] < 0) dp[i][j+k] = -1;
 }
 }
 }
 
 int ans = 0;
 for(int i=0;i<=10000;i++){
 if(dp[n][i] != -1){
			ans = i;
 }
 }
 
	printf("%d\n", ans);
}
