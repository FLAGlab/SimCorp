#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
vector<int> a, f(1e5 + 100);
vector<int>v[N];
signed main() {
 int n;
	cin >> n;
	a.resize(n);
 int mx = -1;
 for (int i = 0; i < n; i++) {
		cin >> a[i];
		f[a[i]]++;
		v[a[i]].push_back(i);
		mx = max(mx, f[a[i]]);
 }
 for (int i = 0; i < 5; i++) {
		sort(v[i].begin(), v[i].end());
 }
 int diff = INT_MAX;
 int ans[2];
 for (int i = 0; i < 5; i++) {
 if (f[i] == mx) {
 int temp = v[i][v[i].size()-1] - v[i][0];
 if (diff > temp) {
				diff = temp;
				ans[0] = v[i][0];
				ans[1] = v[i][v[i].size()-1];
 }
 }
 }
	cout << ans[0] +1<< " " << ans[1]+1;
 
}
