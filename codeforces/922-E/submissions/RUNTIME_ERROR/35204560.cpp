#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
//------------------------------------------------------------------------------------------------------
using namespace std;
typedef long long ll;
#define prmat(v) for (auto i : v){for (auto j : i){cout << j << " ";} cout << "\n";} 
#define prv(v) for (auto i : v){cout << i << " ";} 
#define cout(x)  cout << fixed << setprecision(x) 
#define read(v) for (int i_ = 0; i_ < v.size(); i_++){cin >> v[i_];} 
#define io ios_base::sync_with_stdio(false) 
//------------------------------------------------------------------------------------------------------
int main() {
	io;
	ll n, w, b, x;
	cin >> n >> w >> b >> x;
 vector<ll> count(n), price(n);
	read(count);
	read(price);
	ll sum = 0;
 for (auto i : price) {
		sum += i;
 }
	sum++;
	sum *= 2;
	ll answ = 0;
 vector<vector<ll>> dp(n + 1, vector<ll>(1e4 + 1, -1010));
	dp[0][0] = w;
 for (ll i = 1; i <= n; i++) {
 for (ll j = 0; j < sum + 1; j++) {
 for (ll k = 0; k <= min(j, count[i - 1]); k++) {
 if (dp[i - 1][j - k] == -1010) {
 continue;
 }
				ll n_mana = min(dp[i - 1][j - k] + x, w + (j - k) * b) - price[i - 1] * k;
 if (n_mana < 0) {
 continue;
 }
				ll maxx = w + j * b;
				dp[i][j] = max(dp[i][j], min(maxx, n_mana));
				answ = max(answ, j);
 }
 }
 }
	cout << answ;
}
/*
1
4 23232
2 964 7772 10099 11065 17873 18835 28936 48505 58606 66376 67342 76477 77443 85213 95314 137009 147110 154880 155846 164981 165947 173717 183818 203387 213488 214450 221258 222224 224551 231359 232321
*/
