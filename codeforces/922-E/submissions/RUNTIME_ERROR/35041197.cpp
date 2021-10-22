#include<bits/stdc++.h>
 
using namespace std;
 
long long n, w, b, x, cost[1000001], c[1000001], dp[1011][10011];
 
signed main()
{
    cin >> n >> w >> b >> x;
 for(int i = 1; i <= n; i++)
        cin >> c[i], c[i] = c[i - 1] + c[i];
 for(int i = 1; i <= n; i++)
        cin >> cost[i];
 
    memset(dp, -1, sizeof(dp));
 
 int mx = 0;
 for(int i = 0; i <= c[i]; i++)
 if(i <= c[1])
            dp[1][i] = max(-1ll, w - cost[1] * i);
 
    mx = min(w / cost[1], c[1]);
 //cout << mx << endl;
 for(int i = 2; i <= n; i++)
 {
 int q = -1;
 int y = mx;
        mx = 0;
 for(int j = 0; j <= c[i]; j++)
 {
 for(int k = min(y, j); k >= 0; k--)
 {
 if(c[i] - c[i - 1] >= (j - k))
                     dp[i][j] = max(dp[i][j], min(dp[i - 1][k] + x, k * b + w) - cost[i] * (j - k));
 else
 break;
 }
 if(dp[i][j] != -1)
                mx = j;
 }
 }
 
 for(int i = 1; i <= 1e4; i++)
 {
 if(dp[n][i] == -1)
 {
            cout << i - 1;
 return 0;
 }
 }
 return 0;
}
