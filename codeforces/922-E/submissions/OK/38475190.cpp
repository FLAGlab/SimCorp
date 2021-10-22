#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ft first
#define sc second
#define pb push_back
#define pp pop_back
signed main() {
	ll n,w,b,x; cin>>n>>w>>b>>x;
	ll c[n],j,i,k;
 for(i=0;i<n;i++)cin>>c[i];
	ll cost[n];
 for(i=0;i<n;i++)cin>>cost[i];
	ll dp[1001][10001];
	fill_n(&dp[0][0],1001*10001,-1); 
	dp[0][0]=w;
 for(i=0;i<n;i++)
 for(j=0;j<10001&&dp[i][j]!=-1;j++)
 for(k=0;k<=c[i]&& dp[i][j] - k * cost[i] >= 0;k++)
	               dp[i+1][j+k]=max(dp[i+1][j+k],min(w+ (j+k)*b ,dp[i][j]+ x - k*cost[i]));
 
 for(i=0;i<10001&&dp[n][i]!=-1;i++);
    cout<<i-1; 
 return 0;
}
