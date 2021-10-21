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
 vector<int> dp(n);
 
 for (int i = 1; i < n; ++i) {
 if (b[i - 1].second > b[i].second) {
            dp[i] = i;
 } else {
            dp[i] = dp[i - 1];
 }
 }
 
 int ans = n - 1;
 for (int i = 0; i < n; ++i) {
        ans = min(ans, n - i - 1 + dp[i]);
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
