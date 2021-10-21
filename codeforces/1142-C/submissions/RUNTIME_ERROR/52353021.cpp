#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
//#define int long long
#define pii pair<int, int>
#define pip pair<ll, pii>
#define x first
#define y second
 
pii dec(pii a, pii b) {
 return {a.x - b.x, a.y - b.y};
}
 
int dot(pii a, pii b) {
 return a.x * b.x + a.y * b.y;
}
 
int cross(pii a, pii b) {
 return a.x * b.y - a.y * b.x;
}
 
vector <pii> hul;
 
vector <pii> pt;
signed main() {
   freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 int n;
    cin >> n;
 for (int i = 0; i < n; ++i) {
        pii c;
        cin >> c.x >> c.y;
        c.y -= c.x * c.x;
        pt.pb(c);
 }
    sort(pt.begin(), pt.end());
    reverse(pt.begin(), pt.end());
 for (int i = 0; i < n; ++i) {
 while (sz(hul) > 1 && cross(dec(hul.back(),hul[sz(hul) - 2]), dec(pt[i],hul[sz(hul) - 2])) <= 0)
            hul.pop_back();
        hul.pb(pt[i]);
 }
 int ans = 0;
 for (int i = 1; i < sz(hul); ++i) {
 if (i && hul[i - 1].x == hul[i].x)
 continue;
 ++ans;
 }
    cout << ans;
 return 0;
}
