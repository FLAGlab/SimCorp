#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAXN 010
#define MAXC 10010
ll dp[MAXN][MAXC];
ll cost[MAXC];
int c[MAXC];
 
int32_t main(){
 int n;
	ll W, B, X;
	scanf("%d %lld %lld %lld", &n, &W, &B, &X);
 for(int i=0; i<n; ++i) scanf("%d", &c[i]);
 for(int i=0; i<n; ++i) scanf("%lld", &cost[i]);
	memset(dp, -1, sizeof(dp));
 for(int i=0; i<=c[0]; ++i){
 int res = i*cost[0];
 if(res>W) break;
		dp[0][i] = W-res;
 }
 for(int i=1; i<n; ++i){
 for(ll j=0; j<MAXC; ++j){
 if(dp[i-1][j]==-1) break;
			ll mana = min(dp[i-1][j]+X, W+j*B);
 for(int k=0; k<=c[i]; ++k){
				ll res = k*cost[i];
 if(res>mana) break;
				dp[i][k+j] = max(dp[i][k+j], mana-res);
 }
 }
 }
 int ans = 0;
 for(int j=0; j<MAXC; ++j){
 if(dp[n-1][j]==-1) break;
		ans = j;
 }
	printf("%d\n", ans);
}
 
