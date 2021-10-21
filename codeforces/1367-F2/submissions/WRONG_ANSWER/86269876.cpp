#include <cstdio>
#include <set>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <deque>
#include <iomanip>
using namespace std;
 
#define ll long long
#define ld long double
#define M_PI 3.14159265358979323846264338327950288
const ll N = 1000000007;
 
void solve() {
 int n;
    cin >> n;
 vector<int> a(n);
 vector<pair<int,int> > b(n);
 
 for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = make_pair(a[i], i);
 }
    sort(b.begin(), b.end());
 
 int ans = n - 1;
 for (int i = 0; i < n; ++i) {
 int cur = n - i - 1;
 for (int j = i - 1; j > -1; --j) {
 if (b[j].second > b[j + 1].second) {
                cur += j + 1;
 break;
 }
 }
        ans = min(ans, cur);
 }
    cout << ans << endl;
}
 
int main() {
 int tt = 1;
    cin >> tt;
 while(tt--) {
        solve();
 }
 return 0;
}
