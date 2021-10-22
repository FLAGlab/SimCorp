#include<bits/stdc++.h>
using namespace std;
const int maxn = 3000010;
typedef long long LL;
#define int LL
int n,w,b,x;
int c[maxn];
int cost[maxn];
int dp[1001][10010];
signed main()
{
	scanf("%lld%lld%lld%lld",&n,&w,&b,&x);
 for(int i = 1;i<= n;i++)scanf("%lld",&c[i]);
 for(int i = 1;i<= n;i++)scanf("%lld",&cost[i]);
	memset(dp,-1,sizeof dp);
	dp[0][0] = w;
 for(int i = 1;i<= n;i++)
 {
 for(int j = 0;j<= 10000;j++)
 {
 for(int k = 0;k<= c[i];k++)
 {
 if(j-k<0)break;
 if( dp[i-1][j-k] >= cost[i]*k)
					dp[i][j] = max( dp[i-1][j-k]-cost[i]*k,dp[i][j]);
 }
 if(dp[i][j]!=-1)
			dp[i][j] = min(w+j*b,dp[i][j]+x);
 }
 }
 for(int i = 10000;i>= 1;i--)
 {
 if(dp[n][i]!=-1){printf("%lld\n",i );return 0;}
 }
 
 return 0;
} 
