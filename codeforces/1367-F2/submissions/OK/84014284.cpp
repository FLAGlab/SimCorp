#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef NeverBeRed
#include "debug.h"
#else
#define debug(...) 9715
#endif
typedef long long ll;
typedef long double ld;
typedef complex<ld> point;
#define F first
#define S second
 
 
 
int main()
{
 #ifdef TurnRed
 //freopen("a.in", "r", stdin);
 //freopen("a.out", "w", stdout);
 #endif
 
	ios_base::sync_with_stdio(0), cin.tie(0);
 
 int t;
	cin >> t;
 while (t--)
 {
 int n;
		cin >> n;
 vector<int> a(n);
 for (auto &i : a) cin >> i;
 
 auto b = a;
		sort(b.begin(), b.end());
		b.push_back(2e9);
 
 map<int, vector<int>> mp;
 for (int i = 0; i < n; ++i)
			mp[a[i]].push_back(i);
 
 map<int, int> dp;
 for (auto it = mp.rbegin(); it != mp.rend(); ++it)
 {
			dp[it->F] = it->S.size();
 if (it != mp.rbegin())
 {
 auto pit = prev(it);
 if (pit->S[0] > it->S.back())
					dp[it->F] += dp[pit->F];
 else
					dp[it->F] += pit->S.end() - upper_bound(pit->S.begin(), pit->S.end(), it->S.back());
 }
 }
 
 int ans = n, pos = 0, last = -1;
 for (int l = 0; l < n; ++l)
 {
 if (b[l] == last) ++pos;
 else last = b[l], pos = 0;
 
 auto nxt = upper_bound(b.begin(), b.end(), b[l]);
 int take = mp[b[l]].size() - pos;
 
 int rdp = take;
 if (*nxt < 2e9)
 {
 if (mp[b[l]][take-1] < mp[*nxt][0])
					rdp += dp[*nxt];
 else
					rdp += mp[*nxt].end() - upper_bound(mp[*nxt].begin(), mp[*nxt].end(), mp[b[l]][take-1]);
 }
 
			ans = min(ans, n - rdp);
 }
		cout << ans << "\n";
 }
 
 return 0;
}
