#include<bits/stdc++.h>
//Daniel Grzegorzewski
#pragma GCC optimize("O3")
 
#define MP make_pair
#define PB push_back
#define ST first
#define ND second
#define int long long
 
using namespace std;
 
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VII;
typedef long long LL;
 
void init_ios() {
     ios_base::sync_with_stdio(0);
     cin.tie(0);
}
 
const int N = (int)1e5 + 3;
 
int n, res;
PII s, a[N];
VII hull, pkt;
 
PII operator- (PII x, PII y) {
 return {x.ST-y.ST, x.ND-y.ND};
}
 
int dis(PII x, PII y) {
  PII z = y-x;
 return abs(z.ST)+abs(z.ND);
}
 
int det(PII x, PII y, PII z) {
  PII v = y-x, w = z-x;
 return v.ST*w.ND - v.ND*w.ST;
}
 
bool cmp(PII x, PII y) {
 int r = det(s, x, y);
 if (r == 0) {
 return dis(s, x) < dis(s, y);
 }
 return r > 0;
}
 
signed main() {
  init_ios();
  cin >> n;
 for (int i = 1; i <= n; ++i) {
    cin >> a[i].ST >> a[i].ND;
    a[i].ND -= a[i].ST*a[i].ST;
 if (i == 1 || (a[i].ND < s.ND || (a[i].ND == s.ND && a[i].ST < s.ST)))
      s = a[i];
 }
 for (int i = 1; i <= n; ++i)
 if (a[i] != s)
      pkt.PB(a[i]);
  sort(pkt.begin(), pkt.end(), cmp);
  hull.PB(s);
  hull.PB(pkt[0]);
 for (int i = 1; i < pkt.size(); ++i) {
 while (hull.size() > 1 && det(hull[hull.size()-2], hull.back(), pkt[i]) <= 0)
      hull.pop_back();
    hull.PB(pkt[i]);
 }
 for (int i = 0; i+1 < hull.size(); ++i)
 if (hull[i].ST > hull[i+1].ST)
 ++res;
 if (hull.size() > 2 && hull.back().ST > hull[0].ST)
 ++res;
  cout<<res<<"\n";
}
