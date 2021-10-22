#include<bits/stdc++.h>
using namespace std;
 
int dp[1010][10010],cost[1010],c[1010];
int n,w,b,x,cnt;
 
signed main()
{
    memset(dp,-1,sizeof(dp));
    scanf("%d%d%d%d",&n,&w,&b,&x);
 for(int i=0;i<n;i++)
        scanf("%d",&c[i]),cnt+=c[i];
 for(int i=0;i<n;i++)
        scanf("%d",&cost[i]);
 
    dp[0][0]=w;
 for(int i=0;i<n;i++)
 for(int j=0;j<=cnt&&dp[i][j]>=0;j++)
 for(int k=0;k<=c[i]&&dp[i][j]>=k*cost[i];k++)
                dp[i+1][j+k]=max(dp[i+1][j+k],min(dp[i][j]-k*cost[i]+x,w+(j+k)*b));
 
 for(int j=cnt;j>=0;j--)
 if(dp[n][j]>=0)
 {
            printf("%d\n",j);
 return 0;
 }
}
