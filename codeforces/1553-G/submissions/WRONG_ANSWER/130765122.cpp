#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
#define endl '\n'
#define ll long long
#define pi pair<int, int>
#define f first
#define s second
 
const int m = 1000003;
int n, q;
int a[m], p[m], r[m];
vector<int> v[m];
set<pi> s;
 
int fnd(int x){ return x == p[x] ? x : p[x] = fnd(p[x]);}
 
void add(int x, int y){ s.insert({fnd(x), fnd(y)});}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> n >> q;
 
 for(int i = 2; i < m; i++){
		p[i] = i;
 if(v[i].empty()) for(int j = i; j < m; j += i){
			v[j].push_back(i);
 }
 }
 
 for(int i = 0; i < n; i++){
		cin >> a[i];
 for(int j : v[a[i]]){
 int x = fnd(j), y = fnd(a[i]);
 if(x != y){
 if(r[x] < r[y]) swap(x, y);
				r[x] += r[x] == r[y], p[y] = x;
 }
 }
 for(int j : v[a[i] + 1]){
			add(j, a[i]), add(a[i], j);
 for(int l : v[a[i] + 1]) add(j, l);
 }
 }
 
 while(q--){
 int x, y;
		cin >> x >> y;
		x = fnd(a[--x]), y = fnd(a[--y]);
		cout << (x == y ? 0 : s.count({x, y}) ? 1 : 2) << endl;
 }
 
 return 0;
}
