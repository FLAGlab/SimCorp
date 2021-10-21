#include <bits/stdc++.h>
 
#define start ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define int ll
#define ls st<<1
#define rs st<<1|1
#define pii pair<int,int>
#define rep(z, x, y) for(int z=x;z<=y;++z)
#define com bool operator<(const node &b)
using namespace std;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int maxn = (ll) 2e5 + 5;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;
int T = 1;
int a[maxn], b[maxn];
int dp[maxn][3];
int l[maxn], r[maxn];
int pos[maxn], num[maxn];
 
void solve() {
 int n;
    cin >> n;
    rep(i, 1, n)cin >> a[i], b[i] = a[i], dp[i][0] = dp[i][1] = dp[i][2] = 0, l[i] = r[i] = 0, num[i] = 0;
    sort(b + 1, b + n + 1);
 int tot = unique(b + 1, b + n + 1) - (b + 1);
    rep(i, 1, n) {
        a[i] = lower_bound(b + 1, b + tot + 1, a[i]) - b;
        r[a[i]] = i;
 if (!l[a[i]])
            l[a[i]] = i, pos[a[i]] = i;
 ++num[a[i]];
 }
 int maxx = 1;
    rep(i, 1, n) {
        dp[i][0] = dp[pos[a[i]]][0] + 1;
        dp[i][1] = max(dp[pos[a[i]]][1] + 1, max(dp[pos[a[i] - 1]][0] + 1, dp[pos[a[i] - 1]][2] + 1));
 if (i == r[a[i]])
            dp[i][2] = dp[l[a[i]]][1] + num[a[i]] - 1;
        pos[a[i]] = i;
        rep(j, 0, 2)maxx = max(maxx, dp[i][j]);
 }
    cout << n - maxx << '\n';
}
 
signed main() {
    start;
    cin >> T;
 while (T--)
        solve();
 return 0;
}
