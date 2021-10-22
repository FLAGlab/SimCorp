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
 for(int i=1;i<+n;++i) scanf("%lld",&cost[i]);
	memset(dp,-1,sizeof(dp));
 return 0;
}
