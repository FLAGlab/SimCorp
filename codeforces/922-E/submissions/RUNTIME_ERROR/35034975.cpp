#include<bits/stdc++.h>
using namespace std;
 
const int MAXN = 1e3 + 1;
const int MAXC = 1e4 + 5;
const int magicconst = 1e9;
 
long long n, W, B, X;
long long sumc = 0;
 
vector< vector<long long>>dp;
long long c[MAXN];
long long cost[MAXN];
 
void init()
{
 for (int i = 0; i < MAXN; i++)
 {
 for (int j = 0; j < MAXC; j++)
 {
			dp[i][j] = -1;
 }
 }
}
 
signed main() {
	ios_base::sync_with_stdio(0);
 
 
	cin >> n >> W >> B >> X;
 
 for (int i = 0; i < n; i++)
 {
		cin >> c[i];
		sumc += c[i];
 }
	dp.resize(n, vector<long long>(sumc));
 for (int i = 0; i < n; i++)
 {
		cin >> cost[i];
 }
	dp[0][0] = W;
 for (int i = 0; i < n; i++)
 {
 for (int j = sumc; j >= 0; j--)
 {
 for (int k = 1; k <= c[i] && j + k < sumc; k++)
 {
				dp[i][j + k] = max(dp[i][j] - cost[i] * k, dp[i][j + k]);
 }
 }
 for (int j = sumc; j >= 0; j--)
 {
 if (dp[i][j] >= 0)
 {
				dp[i + 1][j] = min(dp[i][j] + X, W + B * j);
 }
 }
 }/*
	 cout << endl;
	 for (int i = 0; i < n + 1; i++)
	 {
	 for (int j = 0; j <= sumc; j++)
	 {
	 cout << dp[i][j] << " ";
	 }
	 cout << endl;
	 }
	 cout << endl;*/
 for (int i = sumc; i >= 0; i--)
 {
 if (dp[n - 1][i] >= 0)
 {
			cout << i << endl;
 return 0;
 }
 }
 
}
