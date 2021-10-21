#include<bits/stdc++.h>
 
using namespace std;
 
using INT = long long;
 
const int NN = 2e5 + 10;
int a[NN];
vector<int> num[NN];
 
inline int calcup(const vector<int> &p, const int &mn) {
 return p.size() - (lower_bound(p.begin(), p.end(), mn) - p.begin());
}
 
inline int calcdn(const vector<int> &p, const int &mx) {
 return upper_bound(p.begin(), p.end(), mx) - p.begin();
}
 
int calc(const vector<int> &L, const vector<int> &R) {
 int ans = R.size();
 for(int i=0; i<L.size(); i++) {
		ans = max(ans, i + 1 + calcup(R, L[i]));
 }
 return ans;
}
 
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
 int T; cin >> T;
 
 while(T--) {
 int n; cin >> n;
 vector<int> sot;
 for(int i=1; i<=n; i++) {
			scanf("%d", a+i);
			sot.push_back(a[i]);
 }
		sort(sot.begin(), sot.end());
		sot.resize(unique(sot.begin(), sot.end()) - sot.begin());
 int mx = 0, ans = 0;
 for(int i=1; i<=n; i++) {
			a[i] = upper_bound(sot.begin(), sot.end(), a[i]) - sot.begin();
			mx = max(mx, a[i]);
			num[a[i]].push_back(i);
			ans = max(ans, (int) num[a[i]].size());
 }
 for(int i=1; i<mx; i++) {
			ans = max(ans, calc(num[i], num[i+1]));
 }
 int sum = num[mx].size(), nt = mx;
 for(int i=mx-1; i; i--) {
 if(num[i].back() > num[i+1][0]) sum = 0, nt = i;
			sum += num[i].size();
			ans = max(ans, sum + calcdn(num[i-1], num[i][0]) + calcup(num[nt+1], num[nt].back()));
 }
		printf("%d\n", n - ans);
 for(int i=0; i<mx+10; i++) num[i].clear();
 }
 
}
 
 
