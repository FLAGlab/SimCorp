#include<bits/stdc++.h>
using namespace std;
 
 
using ll = long long;
constexpr int SIZE = 1e4+3;
constexpr int inf = 2e9;
 
ll dp[1001][10010];
 
int cost[SIZE];
int c[SIZE];
 
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
 int n,w,b,x;
	cin>>n>>w>>b>>x;
 int mm = 0;
 int ans = 0;
 for(int i=0; i<n; i++){
		cin>>c[i];
		mm += c[i];
 }
 
 for(int i=0; i<n; i++)
		cin>>cost[i];
 
	dp[0][0] = w;
 
 for(int i=0; i<n; i++){
 for(int j=0; j<mm; j++){
 if(dp[i][j] == 0)
 continue;
 for(int k=0; k<=c[i]; k++){
 if(dp[i][j] >= 1LL * k * cost[i]){
					dp[i+1][j + k] = max(dp[i+1][j+k], min(dp[i][j] - k * cost[i] + x, w + 1LL * (j + k) * b));
					ans = max(ans, j + k);
 }
 }
 }
 }
 
	cout<<ans<<"\n";
}
