#include<bits/stdc++.h>
using namespace std;
#define int int64_t
const int N = 1e3 + 9;
int n, w, b, x, c[N], cost[N], dp[N][N*10];
bool solved[N][N*10];
int f(int i, int j)
{
 if(i == 0 && j == 0)
 return w;
 if(i == 0)
 return -100000000;
 if(solved[i][j])
 return dp[i][j];
 int ans = INT_MIN;
 for(int k = 0;k <= c[i] && k <= j;k++)
		ans = max(ans, min(f(i-1, j-k) + x, w + (j-k)*b) - cost[i]*k);
	solved[i][j] = 1;
 return dp[i][j] = ans;
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> w >> b >> x;
 int tot = 0;
 for(int i = 1;i <= n;i++)
 {
		cin >> c[i];
		tot += c[i];
 }
 for(int i = 1;i <= n;i++)
		cin >> cost[i];
 int ans = 0;
 for(int i = 1;i <= tot;i++)
 if(f(n, i) >= 0)
			ans = i;
	cout << ans << '\n';
}
