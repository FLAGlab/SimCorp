#include<bits/stdc++.h>
 
using namespace std;
 
int c[1010],cost[1010];
int dp[1010][10010];
 
int main()
{
 int n,W,B,X;
	scanf("%d%d%d%d",&n,&W,&B,&X);
 for (int i=1;i<=n;i++) scanf("%d",&c[i]);
 for (int i=1;i<=n;i++) scanf("%d",&cost[i]);
	memset(dp,-1,sizeof(dp));
	dp[0][0]=W;
 int cnt=0;
 for (int i=1;i<=n;i++)
 {
		cnt+=c[i];
 for (int j=0;j<=cnt;j++)
 {
 for (int k=0;k<=c[i]&&k<=j;k++)
 {
 if (dp[i-1][j-k]<0) continue;
				dp[i][j]=max(dp[i][j],min(dp[i-1][j-k]+X,W+(j-k)*B)-cost[i]*k);
 }
 }
 }
 for (int i=cnt;i>=0;i--) 
 if (dp[n][i]>=0) 
 return 0*printf("%d\n",i);
}
