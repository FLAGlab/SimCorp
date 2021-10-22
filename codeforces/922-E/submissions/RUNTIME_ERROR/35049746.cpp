#include<bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
 
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)
 
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
 
#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
 
template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}
 
template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}
 
template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}
 
template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}
 
const ll INF = 1LL << 50;
 
const int N = 1010;
const int M = 10100;
 
int c[N];
ll cost[N];
 
ll dp[N];
 
signed main(){ _
 int n;
  ll W, B, X;
  cin >> n >> W >> B >> X;
 
 int tot = 0;
 for(int i = 1; i <= n; i++){
    cin >> c[i];
    tot += c[i];
 }
 
 for(int i = 1; i <= n; i++){
    cin >> cost[i];
 }
 
  dp[0] = W;
 for(int i = 1; i <= c[1]; i++){
 if(cost[1] * i <= W)
      dp[i] = W - cost[1] * i;
 else
      dp[i] = -INF;
 }
 
 for(int i = c[1] + 1; i <= tot; i++){
    dp[i] = -INF;
 }
 
 int cur = c[1];
 for(int i = 2; i <= n; i++){
    cur += c[i];
 
 for(int j = 0; j <= cur; j++) dp[j] = min(dp[j] + X, W + B * j);
 for(int j = cur; j > 0; j--){
 for(int k = max(j-c[i], 0); k < j; k++){
        ll cap = min(dp[k], W + B * k);
 if(cap < cost[i] * (j-k)) continue;
        dp[j] = max(dp[j], cap - cost[i] * (j-k)); 
 }
 }
 }
 
 int ans = 0;
 for(int i = 1; i <= tot; i++){
 if(dp[i] >= 0) ans = i;
 }
 
  cout << ans << endl;
 
 
 return 0;
}
