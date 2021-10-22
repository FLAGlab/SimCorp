#include<bits/stdc++.h>
#define met(s,k) memset(s,k,sizeof s)
using namespace std;
typedef long long ll;
ll dp[1005][1005][2],cost[1005],num[1005];
signed main()
{
    ll n,w,b,x,sum=0;
 int ans=0;
    met(dp,-1);
    scanf("%lld%lld%lld%lld",&n,&w,&b,&x);
    dp[0][0][0]=dp[0][0][1]=w;
 for(int i=0;i<n;i++)scanf("%lld",&num[i]),sum+=num[i];
 for(int i=0;i<n;i++)scanf("%lld",&cost[i]);
 for(int i=0;i<n;i++)
 {
 for (int j = 0; j < sum; ++j)
 {
 if(dp[i][j][1]!=-1)
 {
                ll temp=min(dp[i][j][1]/cost[i],num[i]);
 for (int k = 0; k <= temp; ++k)
 {
                    ll next=(dp[i][j][1]-k*cost[i]+x)<=(dp[i][j][0]+k*b)?(dp[i][j][1]-k*cost[i]+x):(dp[i][j][0]+k*b);
 if(dp[i+1][j+k][1]<next)
 {
                        dp[i+1][j+k][0]=dp[i][j][0]+k*b;
                        dp[i+1][j+k][1]=next;
 }
                    ans= max(ans,j+k);
 }
 }
 }
 }
    printf("%d\n",ans);
 return 0;
}
