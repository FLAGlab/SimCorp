#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'
#define ll long long
#define pi pair<ll, ll>
#define f first
#define s second
 
const int mxn = 100000;
int n;
pi a[mxn];
vector<pi> v;
 
bool cp(pi x, pi y, pi z){
 return (y.f - x.f) * (z.s - y.s) >= (y.s - x.s) * (z.f - y.f);
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> n;
 
 for(int i = 0; i < n; i++) cin >> a[i].f >> a[i].s, a[i].s -= a[i].f * a[i].f;
 
	sort(a, a + n);
 
 for(int i = 0; i < n; i++){
 while((!v.empty() && v.back().f == a[i].f) || 
 (v.size() > 1 && cp(v[v.size() - 2], v.back(), a[i]))){
			v.pop_back();
 } 
		v.push_back(a[i]);
 }
 
	cout << (v.size() - 1) << endl;
 
 return 0;
}
