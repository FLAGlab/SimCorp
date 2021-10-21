#include <bits/stdc++.h>
 
using namespace std;
 
#define IO ios_base::sync_with_stdio(0);cin.tie(0);
 
void build (int curr, vector <int> & c, vector <int> & cost, int w, int maxw, int birds, int b, int x, int & ans) {
 if (curr == (int)c.size())
    ans = max(ans, birds);
 else {
 for (int i = 0; i <= min(c[curr], w / cost[curr]); ++i) {
      build(curr + 1, c, cost, min(w - i * cost[curr] + x + b * i, maxw + b * i), maxw + b * i, birds + i, b, x, ans);
 }
 }
}
 
int main()
{
  IO;
 int n, w, b, x; cin >> n >> w >> b >> x;
 vector <int> c(n), cost(n);
 
 for (int i = 0; i < n; ++i)
    cin >> c[i];
 
 for (int i = 0; i < n; ++i)
    cin >> cost[i];
 
 int ans = 0;
  build(0, c, cost, w, w, 0, b, x, ans);
  cout << ans << endl;
 
 return 0;
}
