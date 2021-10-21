#include <bits/stdc++.h>
 
using namespace std;
 
const int NN = 1010101;
 
map<int, int> mp[NN];
int root[NN];
int a[NN], flag[NN];
int n;
 
int find(int u) {
 if(root[u] == u) return u;
 return root[u] = find(root[u]);
}
 
void merge(int u, int v) {
 int U = find(u);
 int V = find(v);
	root[U] = V;
}
 
void pre() {
 for(int i = 1; i < NN; i ++ ) {
		root[i] = i;
 if(i > 1 && !flag[i]) {
 for(int j = i; j < NN; j += i) flag[j] = i;
 }
 }
 for(int i = 1; i <= n; i ++ ) {
 int u = a[i];
 while(u > 1) {
 int v = flag[u];
                        merge(v, a[i]);
 while(u % v == 0) u /= v;
 }
 }
 for(int i = 1; i <= n; i ++ ) {
 vector<int> vec;
 int u = a[i];
 while(u > 1) {
 int v = flag[u];
			vec.push_back(v);
 while(u % v == 0) u /= v;
 }
 
		u = a[i] + 1;
 while(u > 1) {
 int v = flag[u];
			vec.push_back(v);
 while(u % v == 0) u /= v;
 }
 for(int x: vec) {
 for(int y: vec) {
 int u = find(x);
 int v = find(y);
				mp[u][v] = mp[v][u] = 1;
 }
 }
 }
}
 
int solve(int s, int t) {
 int u = find(a[s]);
 int v = find(a[t]);
 if(u == v) return 0;
 if(mp[u][v]) return 1;
 return 2;
}
 
void solve() {
 int s, t;
	cin >> s >> t;
	cout << solve(s, t) << endl;
}
 
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
 
 int m;
	cin >> n >> m;
 for(int i = 1; i <= n; i ++ ) cin >> a[i];
	pre();
 for(int i = 1; i <= m; i ++ ) solve();
}
 
