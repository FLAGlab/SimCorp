#include<bits/stdc++.h>
using namespace std;
 
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 int n, m, q;
  cin >> n >> m >> q;
 vector<int> p(n + 1), pos(n + 1);
 for (int i = 1; i <= n; i++) {
    cin >> p[i];
    pos[p[i]] = i;
 }
  p[0] = p[n];
 vector<int> a(m + 1), b(m + 1), prev(m + 1, -1);
 for (int i = 1; i <= m; i++) {
    cin >> a[i];
    b[i] = prev[p[pos[a[i]] - 1]];
    prev[a[i]] = i;
 }
 int max_log = ceil(log2((double) m));
 vector< vector<int> > up(m + 1, vector<int>(max_log + 1));
 for (int i = 1; i <= m; i++) {
    up[i][0] = b[i];
 for (int j = 1; j <= max_log; j++) {
 if (up[i][j - 1] == -1) {
        up[i][j] = -1;
 } else {
        up[i][j] = up[up[i][j - 1]][j - 1];
 }
 }
 }
 vector<int> last(m + 1, -1);
 for (int i = 1; i <= m; i++) {
    last[i] = last[i - 1];
 int left = n - 1;
 int cur = i;
 for (int j = max_log; j >= 0; j--) {
 if (left >= (1 << j)) {
        left -= (1 << j);
 if (cur != -1) {
          cur = up[cur][j];
 }
 }
 }
    last[i] = max(last[i], cur);
 }
 while (q--) {
 int l, r;
    cin >> l >> r;
 if (last[r] < l) {
      cout << 0;
 } else {
      cout << 1;
 }
 }
  cout << '\n';
 return 0;
}
