#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e6+5;
int tab[MAXN],c[MAXN],cost[MAXN];
ll dp[1005][10005];
 
signed main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
 int n,w,b,x;
    cin >> n >> w >> b >> x;
 for(int i=0;i<n;i++){
		cin >> c[i];
		fill(dp[i],dp[i]+10005,-1);
 }
	fill(dp[n],dp[n]+10005,-1);
 for(int i=0;i<n;i++)
		cin >> cost[i];
	dp[0][0]=w;
 for(int i=0;i<n;i++)
 for(int j=0;dp[i][j]!=-1;j++)
 for(int k=0;k<=c[i] && dp[i][j]>=ll(k)*cost[i];k++)
				dp[i+1][j+k]=max(dp[i+1][j+k],min(w+ll(k+j)*b,dp[i][j]+x-ll(k)*cost[i]));
 int res=0;
 while(dp[n][res++]!=-1);
	cout << res-2;
}
