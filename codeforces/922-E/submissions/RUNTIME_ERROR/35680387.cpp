#include<bits/stdc++.h>
 
using namespace std;
 
const int MAX = 1e4 + 10;
 
long long dp[1000][MAX];
int v[MAX];
 
signed main(){
 long long n, w, b, x;
    cin >> n >> w >> b >> x;
 for(int i = 1; i <= n+1; ++i){
 if(i != n+1)cin >> v[i];
 for(int j = 0; j < MAX; ++j) dp[i][j] = -1;
 }
    dp[1][0] = w;
 
 long long cost = 0;
 for(int i = 1; i <= n; ++i){
        cin >> cost;
 for(int j = 0; j < MAX; ++j){
 if(dp[i][j] == -1) continue;
 for(int k = 0; k <= v[i] && dp[i][j] - (cost * k) >= 0; ++k){
                dp[i+1][j+k] = max(dp[i+1][j+k], min(dp[i][j] - k*cost + x, (w + (k + j)*b)));
 }
 }
 }
 
 long long ans = 0;
 for(int i = 0; i < MAX; ++i) if(dp[n+1][i] != -1) ans = i;
    cout << ans;
 return 0;
}
