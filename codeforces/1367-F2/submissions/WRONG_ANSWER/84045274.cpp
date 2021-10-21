#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
#define pb push_back
#define PI 3.14159265
int M = 1000000007;
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 int t;
  cin >> t;
 while (t--)
 {
 int n;
    cin >> n;
 int a[n];
 int b[n];
 for (int i = 0; i < n; ++i)
 {
      cin >> a[i];
      b[i] = a[i];
 }
    sort(b, b + n);
 map<int, int> m;
 for (int i = 0; i < n; ++i)
 {
      m[b[i]] = i + 1;
 }
 map<int, int> loc;
 for (int i = 0; i < n; ++i)
 {
      a[i] = m[a[i]];
      loc[a[i]] = i;
 }
 int dp[n] = {0};
    dp[0] = 1;
 for (int i = 1; i < n; ++i)
 {
 int x = a[i];
 if (x > 1)
 {
 int pos = loc[x - 1];
 if (pos < i)
          dp[i] = dp[pos] + 1;
 else
          dp[i] = 1;
 }
 }
 int ans = 0;
 for (int i = 0; i < n; ++i)
 {
      ans = max (ans, dp[i]);
 }
    cout << n - ans << endl;
 
 }
 
}
