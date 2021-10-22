#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1009;
int n;
ll W,B,X,c[MAXN],cost[MAXN],dp[MAXN][MAXN*10];
signed main()
{
	scanf("%d%lld%lld%lld",&n,&W,&B,&X);
 for(int i=1;i<=n;++i) scanf("%lld",&c[i]);
 for(int i=1;i<=n;++i) scanf("%lld",&cost[i]);
	memset(dp,-1,sizeof(dp));
	ll ans=0,sum=0;
	dp[0][0]=W;
 for(int i=1;i<=n;++i){
		sum+=c[i];
 for(ll j=0;j<=sum;++j){
 for(ll k=0;k<=c[i];++k){
				ll pre=j-k;
 if(dp[i-1][pre]==-1) continue;
				ll WW=min(W+pre*B,dp[i-1][pre]+X);
 if(cost[i]*k>WW) continue;
				dp[i][j]=WW-cost[i]*k;
				ans=max(ans,j);
 }
 }
 }
	printf("%lld\n",ans);
 return 0;
}
