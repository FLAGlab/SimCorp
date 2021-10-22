#include<bits/stdc++.h>
 
using namespace std;
 
static const int MAX = 1000000;
 
int l[MAX + 1] = {}, r[MAX + 1] = {}, c[MAX + 1] = {};
 
signed main()
{
 int n, m = 0; cin >> n;
 for (int i = 1; i <= n; ++i) {
 int x; cin >> x;
 if (l[x] == 0)
            l[x] = i;
        r[x] = i;
        m = max(m, ++c[x]);
 }
 for (int x = 0; x <= MAX; ++x) {
 if (c[x] == m) {
            cout << l[x] << " " << r[x] << endl;
 return 0;
 }
 }
 return 0;
}
