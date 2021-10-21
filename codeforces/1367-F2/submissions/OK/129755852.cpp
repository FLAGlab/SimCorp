#include <bits/stdc++.h>
#define int long long
using namespace std;
 
inline int read(){
 int x = 0, f = 1; char c = getchar();
 while (!isdigit(c)){if (c == '-') f = -1; c = getchar();}
 while (isdigit(c)){x = (x << 3) + (x << 1) + (c ^ 48); c = getchar(); }
 return x * f;
}
inline void write(int x){
 if (x < 0) {x = ~(x - 1); putchar('-');}
 if (x > 9) write(x / 10);
	putchar(x % 10 ^ 48);
}
 
const int maxn = 2e5 + 5;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;
int T = 1;
int a[maxn], b[maxn];
int dp[maxn][3];
int l[maxn], r[maxn];
int pos[maxn], num[maxn];
 
void solve() {
 int n = read();
 for (int i = 1; i <= n; i ++)a[i] = read(), b[i] = a[i], dp[i][0] = dp[i][1] = dp[i][2] = 0, l[i] = r[i] = 0, num[i] = 0;
    std::sort(b + 1, b + n + 1);
 int tot = unique(b + 1, b + n + 1) - (b + 1);
 for (int i = 1; i <= n; i ++) {
        a[i] = lower_bound(b + 1, b + tot + 1, a[i]) - b;
        r[a[i]] = i;
 if (!l[a[i]])
            l[a[i]] = i, pos[a[i]] = i;
 ++num[a[i]];
 }
 int maxx = 1;
 for (int i = 1; i <= n; i ++) {
        dp[i][0] = dp[pos[a[i]]][0] + 1;
        dp[i][1] = max(dp[pos[a[i]]][1] + 1, max(dp[pos[a[i] - 1]][0] + 1, dp[pos[a[i] - 1]][2] + 1));
 if (i == r[a[i]])
            dp[i][2] = dp[l[a[i]]][1] + num[a[i]] - 1;
        pos[a[i]] = i;
 for (int  j = 0; j < 3; j ++)maxx = max(maxx, dp[i][j]);
 }
    write(n - maxx), puts("");
}
signed main() {
 int T = read();
 while (T--)solve();
 return 0;
}
