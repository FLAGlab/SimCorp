#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
struct BIT{
 vector<ll> tree;
 int n;
 void init(int N){
		n = N;
		tree = vector<ll> (n+1,0);
 }
 void update(int x,ll val){
 while(x <= n){
			tree[x]+=val;
			x += x&(-x);
 }
 }
	ll get(int x){
		ll res = 0;
 while(x){
			res += tree[x];
			x -= x&(-x);
 }
 return res;
 }
	ll get(int l,int r){
 if(l > r)return 0;
 return get(r) - get(l-1);
 }
};
 
void solve(){
 int n;
	cin>>n;
	BIT t;
	t.init(n);
 vector<pair<int,int>> a(n);
 
 for(int i=0;i<n;i++){
		cin>>a[i].first;
		a[i].second = -(i + 1);
 }
	sort(all(a));
 int ans = 0,l = 0;
 vector<int> add;
 
 for(int r=0;r<n;r++){
 if(r && a[r].first != a[r-1].first){
 for(int i : add){
				t.update(i , 1);
 }
			add.clear();
 }
 int af = t.get(-a[r].second , n);
 while(l < r && af){
			t.update(-a[l].second , -1);
			l++;
			af = t.get(-a[r].second , n);
 }
		add.push_back(-a[r].second);
		ans = max((ll)ans , t.get(n) + (int)add.size());
 }
	cout << n - ans << '\n';
}
 
int main(){
	fast
 int t;
	cin>>t;
 while(t--)solve();
}
