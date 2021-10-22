#include<bits/stdc++.h>
#define INF (ll)(2e16)
#define MD (998244353)
#define pb push_back
#define mp make_pair
#define ft first
#define sd second
 
using namespace std;
using ll = long long;
using cd = complex<double>;
using ul = unsigned long;
 
void f_io () { ios_base :: sync_with_stdio (false); cin.tie (nullptr);
 cout.tie (nullptr);
}
const ll MAX = 2e2 + 10, MOD = 1e9 + 7, M = 3e6;
ll gc (ll a, ll b) {
 if (!a || !b) {
 return max (a, b);
 }
	ll r = a % b;
 while (r) {
		a = b;
		b = r;
		r = a % b;
 }
 return b;
}
 
ll mult (ll a, ll b) {
 return ((a % MOD) * 1LL * (b % MOD)) % MOD;
}
 
ll add (ll a, ll b) {
	b = (b % MOD + MOD) % MOD;
 return (a + b) % MOD;
}
 
ll pw (ll a, ll b) {
 if (b < 0) {
 return 1;
 }
	ll r = 1;
 while (b) {
 if (b & 1) {
			r = mult (a, r);
 }
		b >>= 1;
		a = mult (a, a);
 }
 return r;
}
 
vector<ll> gr[MAX];
 
ll cc (ll n, ll p1, ll p2) {
	ll a = 1;
 for (ll x : gr[n]) {
 if (x != p2 && x != p1) {
			a += cc (x, n, p2);
 }
 }
 return a;
}
vector<ll> path[MAX][MAX];
 
void dfs (ll st, ll n, ll p) {
	path[st][n] = path[st][p];
	path[st][n].pb (n);
 for (ll x : gr[n]) {
 if (x != p) {
			dfs (st, x, n);
 }
 }
}
 
ll dp[1003][10005];
int  main () {
	f_io ();
	ll t;
	t = 1;
 while (t--) {
		ll n, w, b , y;
		cin >> n >> w >> b >> y;
		ll c[n], ss = 0, co[n];
 for (ll i = 0; i < n; i++) {
			cin >> c[i];
			ss += c[i];
 }
 for (ll i = 0; i < n; i++) {
			cin >> co[i];
 }
 for (ll i = 0; i <= n + 10; i++) {
 for (ll j = 0; j <= ss; j++) {
				dp[i][j] = -MOD;
 }
 }
		dp[0][0] = w;
		ll ma = 0;
 for (ll i = 0; i < n; i++) {
 for (ll j = 0; j <= ss; j++) {
 if (dp[i][j] == -MOD) {
 break;
 }
				ma = max (j, ma);
 for (ll x = 0; x <= c[i] && x + j <= ss; x++) {
					ll mm = w + b * (x + j);
 if (dp[i][j] >= (x * co[i])) {
						dp[i + 1][j + x] = max (min (mm, dp[i][j] - (x * co[i]) + y), dp[i + 1][j + x]);
						ma = max (j + x, ma);
 }
 }
 }
 }
		cout << ma << "\n";
 }
}
