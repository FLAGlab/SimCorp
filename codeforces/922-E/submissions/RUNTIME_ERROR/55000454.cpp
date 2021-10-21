#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
 
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define fi   first
#define se   second
#define all(a) a.begin(), a.end()
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define endl '\n'
 
const int N = 1e3 + 5, C = 1e4 + 5;
ll n, W, B, X, c[N], cost[N];
ll dp[N][C];
 
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
 clock_t tStart = clock();
	freopen("922E.INP", "r", stdin);
	freopen("922E.OUT", "w", stdout);
 
 int sum = 0;
	cin >> n >> W >> B >> X;
	FOR(i, 1, n) {
		cin >> c[i];
		sum += c[i];
 }
	FOR(i, 1, n) {
		cin >> cost[i];
 }
 
	memset(dp, -1, sizeof dp);
	dp[0][0] = W;
	FOR(i, 1, n) FOR(j, 0, sum) {
		FOR(k, 1, min(1LL * j, c[i])) if (dp[i - 1][j - k] != -1) {
			dp[i][j] = max(dp[i][j], min(dp[i - 1][j - k] + X, W + (j - k) * B) - cost[i] * k);
 }
 //cerr << "dp[" << i << "][" << j << "] : " << dp[i][j] << endl;
 }
//  	FORD(j, sum, 0) {
//  		if (dp[n][j] >= 0) {
//  			cout << j << endl;
//  			return 0;
//  		}
//  	}
	fprintf(stderr, "Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
 return 0;
}
