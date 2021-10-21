#include <bits/stdc++.h>
#define MAX (ll)(2e5 + 7)
#define INF (ll)(1e18)
#define MOD (ll)(1e9 + 7)
 
using namespace std;
using ll = long long;
using cd = complex<double>;
using p = pair<int, int>;
using pp = pair<pair<int, int>, pair<int, pair<int, int>>>;
 
int main () {
	ios_base :: sync_with_stdio (false);
	cin.tie (nullptr);
 int t;
	cin >> t;
 while (t--) {
 int n;
		cin >> n;
 int ar[n], br[n];
 for (int i = 0; i < n; i++) {
			cin >> ar[i];
			br[i] = ar[i];
 }
		sort (ar, ar + n);
 int x = unique (ar, ar + n) - ar, cc = 0;
 map <int, int> ma;
 for (int i = 0; i < x; i++) {
			ma[ar[i]] = ++cc;
 }
 for (int i = 0; i < n; i++) {
			br[i] = ma[br[i]];
			ar[i] = br[i];
 }
 int pure[cc + 1] = {}, mm = 0, cur[cc + 1] = {}, end[cc + 1] = {};
 vector<int> mr[cc + 1];
 for(int i = 0; i < n; i++) {
			mr[ar[i]].push_back (i); 
 }
 for (int i = 0; i < n; i++) {
			pure[ar[i]]++;
			cur[ar[i]]++;
 if (i == mr[ar[i]][0]) {
				cur[ar[i]] = max (cur[ar[i]], pure[ar[i] - 1] + 1);
 if (ar[i] > 1 && i >= mr[ar[i] - 1].back ()) {
					cur[ar[i]] = max (cur[ar[i]], cur[ar[i] - 1] + 1);
 }
 }
			end[ar[i]] = max (end[ar[i]] + 1, cur[ar[i]]);
 if (ar[i] > 1 && i >= mr[ar[i] - 1].back ()) {
				end[ar[i]] = max (end[ar[i]], cur[ar[i] - 1] + 1);
 }
			end[ar[i]] = max (end[ar[i]], pure[ar[i] - 1] + 1);
			mm = max (mm, end[ar[i]]);
 }
		cout << n - mm << "\n";
 }
}
