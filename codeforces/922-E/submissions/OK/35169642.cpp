#include<bits/stdc++.h>
 
using namespace std;
 
long long c[1010],cost[1010];
long long dp[1010][10010];
 
signed main()
{
 long long n,W,B,X;
	scanf("%lld%lld%lld%lld",&n,&W,&B,&X);
 for (long long i=1;i<=n;i++) scanf("%lld",&c[i]);
 for (long long i=1;i<=n;i++) scanf("%lld",&cost[i]);
	memset(dp,-1,sizeof(dp));
	dp[0][0]=W;
 long long cnt=0;
 for (long long i=1;i<=n;i++)
 {
		cnt+=c[i];
 for (long long j=0;j<=cnt;j++)
 {
 for (long long k=0;k<=c[i]&&k<=j;k++)
 {
 if (dp[i-1][j-k]<0) continue;
				dp[i][j]=max(dp[i][j],min(dp[i-1][j-k]+X,W+(j-k)*B)-cost[i]*k);
 }
 }
 }
 for (long long i=cnt;i>=0;i--) 
 if (dp[n][i]>=0) 
 return 0*printf("%lld\n",i);
}
