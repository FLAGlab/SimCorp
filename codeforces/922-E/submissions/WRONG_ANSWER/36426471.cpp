#include <bits/stdc++.h>
#define inf 2000000000
#define li 1005
using namespace std;
int n,w,b,x,c[li],cost[li],dp[li][li];
int main()
{
    scanf("%d %d %d %d",&n,&w,&b,&x);
 for(int i=1;i<=n;i++) scanf("%d",&c[i]);
 for(int i=1;i<=n;i++) scanf("%d",&cost[i]);
    memset(dp,-1,sizeof(dp));
    dp[1][0]=w;
 for(int i=1;i<=n;i++)
 {
 for(int j=0;j<=10000 && dp[i][j]!=-1;j++)
 {
 for(int k=0;k<=c[i] && dp[i][j]-k*cost[i]>=0;k++)
 {
                dp[i+1][j+k]=max(dp[i+1][j+k],min(w+(k+j)*b,dp[i][j]+x-k*cost[i]));
 }
 }
 }
 for(int i=10000;i>=0;i--)
 {
 if(dp[n+1][i]!=-1)
 {
            printf("%d",i);
 return 0;
 }
 }
 return 0;
}
