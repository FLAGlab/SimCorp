#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
 
void solve()
{
 int n;
    cin >> n;
 int a[3200], b[3200];
 for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = a[i];
 }
    sort(b, b + n);
 int minOp = INT_MAX;
 for (int i = 0; i < n; ++i) {
 int op = 0;
 int curr = i;
 for (int j = n - 1; j >= 0 && curr > 0; --j) {
 if (a[j] < b[curr]) {
 ++op;
 } else if (a[j] == b[curr]) {
 --curr;
 }
 }
        curr = i;
 for (int j = 0; j < n && curr < n; ++j) {
 if (a[j] > b[curr]) {
 ++op;
 } else if (a[j] == b[curr]) {
 ++curr;
 }
 }
 /* cout << i << ' ' << op << endl; */
        minOp = min(minOp, op);
 }
    cout << minOp << endl;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
 int T;
    cin >> T;
 for (int t = 0; t < T; ++t) {
        solve();
 }
 return 0;
}
