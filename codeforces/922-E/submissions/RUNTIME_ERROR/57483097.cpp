#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int maxn = 1e3 + 17;
const int maxbird = 1e4 + 17;
 
int num[maxn],cost[maxn];
 
ll dp[maxn][maxbird];
 
int main(){
	ios_base::sync_with_stdio(0);
 int n;
	ll cap,inc,reg;
	cin>>n>>cap>>inc>>reg;
 for(int i = 1;i <= n;++i) cin>>num[i];
 for(int i = 1;i <= n;++i) cin>>cost[i];
 
	memset(dp,-1,sizeof dp);
 
	dp[1][0] = cap;
 
 for(int i = 1;i <= n;++i){
 for(int j = 0;j <= maxbird;++j){
 if(dp[i][j] != -1){
				ll cur_cap = cap + inc * j;
				ll cur_mana = dp[i][j];
 for(int k = 0;k <= min((ll)num[i],cur_mana / cost[i]);++k){
					dp[i + 1][j + k] = max(dp[i + 1][j + k],cur_mana + reg - cost[i] * k);
					dp[i + 1][j + k] = min(dp[i + 1][j + k],cur_cap);
 }
 }
 }
 }
 
	ll res = 0;
 
 for(int i = maxbird - 1;i >= 0;--i){
 if(dp[n + 1][i] != -1){
			res = i;
 break;
 }
 }
 
	cout<<res;
}
