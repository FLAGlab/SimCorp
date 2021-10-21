#include <bits/stdc++.h>
using namespace std;
 
int main() {
 int t;
    cin >> t;
 while(t--) {
 int n;
        cin >> n;
 map<int, int> mp;
 int a[n], b[n];
 for(int i = 0; i < n; i++) {
            cin >> a[i];
            b[i] = a[i];
 }
        sort(b, b + n);
 for(int i = 0; i < n; i++) {
            mp[b[i]] = i + 1;
 }
 for(int i = 0; i < n; i++) {
            a[i] = mp[a[i]];
 }
 int dp[n + 4];
 for(int i = 0; i < n + 4; i++) {
            dp[i] = 0;
 }
 int maxx = 0;
 for(int i = 0; i < n; i++) {
            dp[a[i]] = dp[a[i] - 1] + 1;
            maxx = max(maxx, dp[a[i]]);
 }
        cout << n - maxx << endl;
 }
}
