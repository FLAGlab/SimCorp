#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;
 
int main() {
  ll t;
  cin >> t;
 while(t--) {
    ll n;
    cin >> n;
    vec a(n);
 vector<pll> b(n);
 for(ll i=0;i<n;i++) {
      cin >> a[i];
      b[i]={a[i],i};
 }
    sort(b.begin(),b.end());
    vec p(n);
    ll j=0;
 unordered_multiset<ll> next;
 for(ll i=0;i<n;i++) {
 if(i&&b[i].first!=b[i-1].first) {
        j++;
 }
      p[b[i].second]=j;
      next.insert(j);
 }
 unordered_map<ll,ll> d;
    vec dp1(n),dp2(n),dp3(n),cnt(n);
 for(ll i=0;i<n;i++) {
 if(next.count(p[i])) {
        next.erase(next.find(p[i]));
 }
 if(d.count(p[i]-1)) {
 if(!d.count(p[i])) {
          dp2[i]=max(dp2[i],dp1[d[p[i]-1]]+1);
 if(!next.count(p[i]-1)) {
            dp2[i]=max(dp2[i],dp2[d[p[i]-1]]+1);
 }
 }
 if(!next.count(p[i]-1)) {
          dp3[i]=max(dp3[i],dp2[d[p[i]-1]]+1);
 }
        dp3[i]=max(dp3[i],dp1[d[p[i]-1]]+1);
 }
 if(d.count(p[i])) {
        dp3[i]=max(dp3[i],dp3[d[p[i]]]+1);
        dp2[i]=max(dp2[i],dp2[d[p[i]]]+1);
        dp1[i]=dp1[d[p[i]]]+1;
 }
 else {
        dp1[i]=1;
 }
      dp2[i]=max(dp2[i],dp1[i]);
      dp3[i]=max(dp3[i],dp2[i]);
      d[p[i]]=i;
 }
    cout << n-*max_element(dp3.begin(),dp3.end()) << endl;
 }
}
