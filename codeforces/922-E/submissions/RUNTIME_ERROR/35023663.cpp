#include<bits/stdc++.h>
#define LOCAL_GCC 0 // CHANGEME
#if defined(_DEV) || defined(OCL)
#define DEV 1
#else
#define DEV 0
#endif
#define LOCAL_GCC 0 // CHANGEME
#if defined(_DEV)
#define DEV 1
#else
#define DEV 0
#pragma GCC optimize("O3")
#endif
#if defined(__GNUC__) || defined(OCL)
#else
 
#if DEV
#else
#ifndef OCL
#endif
#endif
#endif
//opl includes go here
using namespace std;
 
#define $ALL(x) (x).begin(), (x).end()
template<typename T>
void $readvec(const vector<T>& vec, int cnt) {
    vec.resize(cnt);
 for (int i = 0; i < cnt; ++i) {
        cin >> vec[i];
 }
}
using ll = signed long long;
using ld = long double;
void $main();
signed main() {
 if (DEV) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
 }
    $main();
}
 
void $main() {
    ll n, w, b, x;
    cin >> n >> w >> b >> x;
 vector<ll> c(n);
 for (int i = 0; i < n; ++i) cin >> c[i];
 vector<ll> cost(n);
 for (int i = 0; i < n; ++i) cin >> cost[i];
 int c_sum = 0;
 for (int t : c) {
        c_sum += t;
 }
 vector<vector<ll>> d(n + 1, vector<ll>(c_sum + 1, -1));
    d[0][0] = w;
 for (int i = 0; i < n; ++i) {
 for (int k = 0; k <= c_sum; ++k) {
 if (d[i][k] == -1) continue;
            ll pre_magic_limit = w + b * k;
            ll pre_magic = d[i][k];
            ll max_take = min(c[i], pre_magic / cost[i]);
 for (ll take = 0; take <= max_take; ++take) {
                ll new_magic_limit = pre_magic_limit + take * b;
                d[i + 1][k + take] = max(d[i + 1][k + take], min(d[i][k] - take * cost[i] + x, new_magic_limit));
 }
 }
 }
 for (int t = c_sum; t >= 0; --t) {
 if (d[n][t] != -1) {
            cout << t;
 return;
 }
 }
}
