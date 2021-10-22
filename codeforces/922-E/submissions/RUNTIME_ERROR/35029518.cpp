#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1001;
 
int n, c[maxn], cost[maxn], b, x;
map<pair<int, int>, int> d; 
 
int func(int k, int w, int s) {
 if(d.find({k, min(s / cost[k], c[k])}) != d.end()) return d[{k, min(s / cost[k], c[k])}];
 int bestans = 0;
 for(int i = 0; i <= c[k]; i++) {
 
 if(cost[k] * i <= s) {
			bestans =  max(bestans, i + (k!= n - 1? func(k + 1, w + b * i, s - cost[k] * i + x) : 0));
 }
 else break;
 }
	d[{k, min(s / cost[k], c[k])}] = bestans;
 
 return bestans;
}
 
signed main() {
	ios::sync_with_stdio(0);
 int w;
	cin >> n >> w >> b >> x;
 for(int i = 0; i < n; i++) {
		cin >> c[i];
 }
 for(int i = 0; i < n; i++) {
		cin >> cost[i];
 }
	cout << func(0, w, w) << endl;
 return 0;
}
