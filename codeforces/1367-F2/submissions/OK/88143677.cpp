#include <bits/stdc++.h>
using namespace std;
 
#define deb(x) cout<<#x<<"="<<x<<endl
#define deb2(x,y) cout<<#x<<"="<<x<<", "<<#y<<"="<<y<<endl
#define deb3(x,y,z) cout<<#x<<"="<<x<<", "<<#y<<"="<<y<<", "<<#z<<"="<<z<<endl
#define rng(x) x.begin(), x.end()
#define pb push_back
#define F first
#define S second
#define el '\n'
 
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<bool> vb;
 
void solve(){
 int n; cin>>n;
 map <int , vi> pos;
	vi a(n), DP(n, 1);
 for (int i = 0; i < n; ++i){
		cin>>a[i];
		pos[a[i]].pb(i);
 }
 map <int, int> full;
 
	vi ind = a;
	sort(rng(ind));
	ind.resize(unique(rng(ind)) - ind.begin());
 
 for (int i = n-1; i >= 0; --i){
 
 auto fpos = upper_bound(rng(pos[a[i]]), i);
 if(fpos != pos[a[i]].end()) DP[i] = DP[*fpos] + 1;
 
 auto nxt = upper_bound(rng(ind), a[i]);
 if(nxt!=ind.end()){
 if(pos[*nxt][0] > i)
				DP[i] = max(DP[i], 1 + full[*nxt]);
 else
				DP[i] = max(DP[i], 1 + (int)(pos[*nxt].end() - upper_bound(rng(pos[*nxt]), i)));
 }
 
 if(i == pos[a[i]][0])
			full[a[i]] = pos[a[i]].size() + DP[pos[a[i]].back()] - 1;
 }
 
	cout<<n - *max_element(rng(DP))<<el;
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
 #ifndef ONLINE_JUDGE 
		freopen("input.txt", "r", stdin); 
		freopen("output.txt", "w", stdout); 
 #endif
 int T=1, tc = 1;
	cin>>T; 
 while(T--){
		solve();
 }
 return 0; 
}
