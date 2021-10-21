#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
 
#define REP(k, n) for (ll k = 0; k < (ll)(n); ++k)
#define REPREV(k, n) for (ll k = (ll)(n)-1; k >= 0; --k)
#define FOR(k, a, b) for (ll k = (ll)(a); k < (ll)(b); ++k)
#define FORREV(k, a, b) for (ll k = (ll)(b)-1; k >= (ll)(a); --k)
#define FOREACH(e, v) for (auto& e : v)
 
#define TGET(t, i) get<i>(t)
#define TSET(t, i, a) get<i>(t) = a
// MinHeap - priority_queue<ll, vll, greater<ll>> pq;
 
#define EVEN(n) ((n)&1) == 0
#define ODD(n) ((n)&1) == 1
#define MOD(x, m) ((x) % (m) + (m)) % (m)
 
#define SORT(v) sort(v.begin(), v.end())
#define SORTREV(v) sort(v.rbegin(), v.rend())
#define SHUFFLE(v) random_shuffle(v.begin(), v.end())
//srand(unsigned(time(0)));
 
#define REMOVEAT(v, i) v.erase(v.begin() + i)
#define REVERSE(v) reverse(v.begin(), v.end())
 
template <typename T>
void join(T& arr, string sep) {
 bool first = true;
 for (auto t : arr) {
 if (first) {
            first = false;
            cout << t.first;
 } else {
            cout << sep << t.first;
 }
 }
    cout << endl;
}
 
#define POS "POSSIBLE"
#define IMPOS "IMPOSSIBLE"
 
// #define INF LLONG_MAX
// #define MINF LLONG_MIN
#define INF 9e18
#define MINF -INF
 
void solve() {
    ll n;
    cin >> n;
    vll b(n + 1);
 set<ll> s;
    REP(i, n) {
        cin >> b[i + 1];
        s.insert(b[i + 1]);
 }
 if (n == 1) {
        cout << "0\n";
 return;
 }
 
 map<ll, ll> idx;
    FOREACH(a, s) {
        idx[a] = idx.size() + 1;
 }
    FOR(i, 1, n + 1) {
        b[i] = idx[b[i]];
 }
 
    vll dp(n + 1, 0);
    vll all(n + 1, 0);
    vll last(n + 1, 0);
    vll cnt(n + 1, 0);
    vll now(n + 1, 0);
    vll first(n + 1, 0);
    FOR(i, 1, n + 1) {
        cnt[b[i]]++;
 }
    FORREV(i, 1, n + 1) {
        first[b[i]] = i;
 }
    ll res = 0;
    FOR(i, 1, n + 1) {
        dp[i] = max(dp[last[b[i]]], now[b[i] - 1]) + 1;
 if (now[b[i] - 1] == cnt[b[i] - 1]) dp[i] = max(dp[i], all[b[i] - 1] + 1);
        res = max(res, dp[i]);
        last[b[i]] = i;
        now[b[i]]++;
 if (now[b[i]] == cnt[b[i]]) all[b[i]] = dp[first[b[i]]] + cnt[b[i]] - 1;
 }
 
    cout << n - res << "\n";
 // SORT(a);
 // vll nxt(n);
 // ll prv = -1;
 // ll cur = a[n-1].first;
 // REPREV(i, n) {
 //     if (cur == a[i].first) {
 //         nxt[i] = prv;
 //     } else {
 //         prv = a[i+1].first;
 //         cur = a[i].first;
 //         nxt[i] = prv;
 //     }
 // }
 
 // vector<pll> dp(n);
 // dp[n-1].first = 1;
 // dp[n-1].second = 1;
 // FORREV(i, 0, n-1) {
 //     if (a[i].second < a[i+1].second) {
 //         dp[i].first = 1 + dp[i+1].second;
 //     } else {
 //         dp[i].first = 1;
 //     }
 
 //     if (a[i].first == a[i+1].first) {
 //         dp[i].second = 1 + dp[i+1].second;
 //     } else {
 //         dp[i].second = 1;
 //     }
 
 //     if (nxt[i] == -1)
 //         continue;
 
 //     auto lb = lower_bound(a.begin() + i + 1, a.end(), make_pair(nxt[i], a[i].second));
 //     if (lb == a.end() || lb->first != nxt[i] || lb->second <= a[i].second) {
 //         continue;
 //     }
 //     dp[i].second = max(dp[i].second, 1 + dp[(int)(lb - a.begin())].first);
 // }
 
 // ll res = 0;
 // REP(i, n) {
 //     res = max({res, dp[i].first, dp[i].second});
 // }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 int tt = 1;
    cin >> tt;
 for (int t = 1; t <= tt; t++) {
 // cout << "Case #" << t << ": ";
        solve();
 }
 
 return 0;
}
