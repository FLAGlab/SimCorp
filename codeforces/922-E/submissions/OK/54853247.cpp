#include <bits/stdc++.h>
using namespace std;
long long a[1005],cost[1005],n,initial,cap_increase,x,dp[1005][10005],ans;
int main(){
	cin>>n>>initial>>cap_increase>>x;
 for(int i=0;i<n;cin>>a[i++]);
 for(int i=0;i<n;cin>>cost[i++]);
	fill(&dp[0][1],&dp[1005][0],-1);
	dp[0][0] = initial;
 for(int i=0;i<n;++i) for(int j=0;j<10005&&dp[i][j]>=0;++j)
 for(int k=0;k<=a[i]&&dp[i][j]>=k*cost[i];++k)
			dp[i+1][j+k]=max(dp[i+1][j+k],min(dp[i][j]-k*cost[i]+x,initial+(j+k)*cap_increase));
 for(long long j=0;j<10005;++j) if(dp[n][j]>=0) ans=max(ans,j);
	cout<<ans;
}
