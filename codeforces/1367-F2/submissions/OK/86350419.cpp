#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
 
 //typedef tree<
 //int,
 //null_type,
 //less<int>,
 //rb_tree_tag,
 //tree_order_statistics_node_update>
 //ordered_set;
 
 
//#define REP(i,m) for(int i=0;i<(m);++i)
//struct dsu{
 //static const int MAXN=105;
 //int par[MAXN];
 //int size[MAXN];
 //void init(){
 //memset(par,-1,sizeof(par));
 //REP(i,MAXN) size[i]=1;
 //}
 //int root(int a){
 //if(par[a]==-1) return a;
 //return par[a]=root(par[a]);
 //}
 //void unite(int a,int b){
 //a=root(a);b=root(b);
 //if(a==b) return;
 //if(size[a]<size[b]) swap(a,b);
 
 //par[b]=a;
 //size[a]+=size[b];
 //}
 //bool same(int a,int b){
 //return root(a)==root(b);
 //}
//};	
 
#define ll long long 
 
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	ll t;cin>>t;
 while(t--){
		ll n;cin>>n;
 vector <pair<ll,ll>> vecs;
 for(int i=0;i<n;i++){
			ll temp;cin>>temp;
			vecs.push_back({temp,-i});
 }
		sort(vecs.begin(),vecs.end());
		ll cur=0;
		ll ans=0;
 set <ll> set1;
 set <ll> set2;
 for(int i=0;i<n;i++){
 if(i>0 && vecs[i].first!=vecs[i-1].first/*vecs[i].first!=vecs[i-set1.size()].first*/){
 for(ll x:set1){
					set2.insert(x);
 }
				set1.clear();
 }
 while(set2.size() && (*set2.begin()<vecs[i].second)){
				set2.erase(vecs[cur].second);
				cur++;
 }
			set1.insert(vecs[i].second);
			ans=max(ans,(ll)set1.size() + (ll)set2.size());
 }
		cout<<n-ans<<endl;
 }
 return 0;
 
}
