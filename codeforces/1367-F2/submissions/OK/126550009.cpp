#include <bits/stdc++.h>
using namespace std; 
#define all(c) c.begin(),c.end()
#define sz(x) int(x.size())
#define ar array
typedef long long ll ; 
typedef vector<int> vi;
#define mod 1000000007
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll exp(ll x,ll y){
  x%=mod;
  ll res=1;
 while(y){
 if(y&1)
    res=res*x%mod;
    x=x*x%mod;
    y>>=1;
 }
 return res;
}
ll fact(ll n){
  ll res=1;
 for(ll i=2;i<=n;++i)
 (res*=i)%=mod;
 return res;
}
bool isprime(ll n){
 if(n<=1) return 0;
 for(ll i=2;i*i<=n;++i)
 if(n%i==0) return 0;
 return 1;
}
 
int main() {
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
int t; cin>>t;
while(t--){
 int n; cin>>n;
  vi v(n),b;
 vector<vi> dp(n,vi(2));
 map<int,int> mp,cnt,r;
 for(int i=0;i<n;++i) {
    cin>>v[i];
 if(!mp.count(v[i])) mp[v[i]]=i;
 }
  b=v; sort(all(b));
 int mx=0;
 for(int i=0;i<n;++i){
    dp[i][0]=dp[i][1]=++cnt[v[i]];
 int p=lower_bound(all(b),v[i])-b.begin();
 if(p-1>=0){
 int c=upper_bound(all(b),b[p-1])-lower_bound(all(b),b[p-1]);
 if(c==cnt[b[p-1]]) dp[i][0]=max(dp[i][0],c+dp[mp[b[p-1]]][0]);
 else dp[i][0]=max(dp[i][0],cnt[b[p-1]]+1);
 }
 if(r.count(v[i])) dp[i][1]=max(dp[i][1],max(dp[r[v[i]]][0],dp[r[v[i]]][1])+1);
    r[v[i]]=i;
    mx=max({mx,dp[i][0],dp[i][1]});
 }
  cout<<n-mx<<'\n';
}
return 0;
}
