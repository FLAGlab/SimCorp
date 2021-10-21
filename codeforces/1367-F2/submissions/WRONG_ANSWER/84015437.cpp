#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
 
const int N = 100005;
 
void solve() {
 int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
	cin >> n;
 int a[n];
 map<int, int> mp;
 for (i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]] = i;
 }
	ans = n;
	sort(a, a + n);
	j = 0;
 for (i = 0; i < n; i++) {
		j = max(j, i + 1);
 while (j < n && mp[a[j]] > mp[a[j - 1]]) {
			j++;
 }
		ans = min(ans, n - (j - i));
 }
	cout << ans << '\n';
 return ;
}
 
int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 int t; cin >> t; while (t--)
		solve();
 return 0;
}
