#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <array>
#include <string>
#include <set>
#include <map>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <utility>
 
using namespace std;
typedef long long ll;
 
#define size(v) ((int)v.size())
#define all(v) v.begin(), v.end()
#define iosb ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
const int maxn = 1000;
ll cost[maxn], W, B, X;
int n, cnt[maxn], sum = 0;
 
vector<ll> dp, prv;
 
int main() {
	iosb;
	cin >> n >> W >> B >> X;
 for (int i = 0; i < n; ++i)
		cin >> cnt[i];
 for (int i = 0; i < n; ++i)
		cin >> cost[i];
 for (int i = 0; i < n; ++i)
		sum += cnt[i];
	dp.resize(sum + 1, -1); prv = dp;
	dp[0] = prv[0] = W;
 for (int i = 1; i <= cnt[0] && dp[i - 1] - cost[0] >= 0; ++i)
		prv[i] = dp[i] = dp[i - 1] - cost[0];
 for (int i = 1; i < n; ++i) {
 for (int j = 0; j <= sum; ++j) {
 if (prv[j] != -1)
				prv[j] = min(W + j * B, prv[j] + X);
 int c = min((ll)cnt[i], prv[j] / cost[i]);
 for (int dt = 0; dt + j <= sum && dt <= c; ++dt)
				dp[j + dt] = max(dp[j + dt], prv[j] - cost[i] * dt);
 }
		prv = dp;
 }
 int mx = 0;
 for (int i = 0; i <= sum; ++i)
 if (dp[i] > -1)
			mx = i;
	cout << mx;
 return 0;
}
