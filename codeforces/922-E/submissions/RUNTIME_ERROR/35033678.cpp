#include <bits/stdc++.h>
 
using namespace std;
 
#define MAXN 1005
#define MAXR 10005
 
long long dp[MAXN][MAXR*2];
long long cost[MAXR];
long long c[MAXR];
 
int main()
{
 long long n,w,b,x;
	cin >> n >> w >> b >> x;
 for(int i = 1; i <= n; i++)
 {
		cin >> c[i] >> cost[i];
 }
	dp[0][0]=w;
 for(int i = 1; i < MAXR; i++)dp[0][i]=-1*1LL;
 for(int i = 1; i <= n; i++)
 {
 for(int j = 0; j < MAXR; j++)dp[i][j]=dp[i-1][j];
 for(int j = 0; j < MAXR; j++)
 {
 if(dp[i][j]<0)continue;
			dp[i][j]+=x;
			dp[i][j]=min(dp[i][j],w+b*j);
 for(int k = 0; k <= c[i]; k++)
 {
				dp[i][k+j]=dp[i][j];
				dp[i][k+j]-=k*cost[i];
 }
 }
 }
 int r=0;
 for(int i = 0; i < MAXR; i++)
 {
 for(int j = 1; j <= n; j++)
 {
 if(dp[i][j]<0)continue;
			r=i;
 }
 }
	cout << r;
 return 0;
}
