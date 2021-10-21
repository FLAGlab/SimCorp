#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define all(a) a.begin(),a.end()
#define lb lower_bound
#define ub upper_bound
#define owo ios_base::sync_with_stdio(0);cin.tie(0);
#define MOD (ll)(1e6+3)
#define INF (ll)(1e18)
#define debug(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false);\
debug("%s time : %.4fs\n", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> PII;
typedef pair<int,int> pii;
typedef vector<vector<int>> vii;
typedef vector<vector<ll>> VII;
int main()
{
	owo
 int t,n;
	cin>>t;
 while(t--){
		cin>>n;
 vector<ll>a(n+1);
 set<int>s;
 for(int i=1;i<=n;i++){
			cin>>a[i];
			s.insert(a[i]);
 }
 map<int,int>mp;
 int id = 1;
 for(int x:s){mp[x] = id;id++;}
 for(int i=1;i<=n;i++)a[i] = mp[a[i]];
 vector<int>cnt(n+1,0),first(n+1,0),last(n+1,0);
 vector<int>now(n+1,0),dp(n+1,0),dp2(n+1,0);
 for(int i=n;i>0;i--)first[a[i]] = i;
 for(int i=1;i<=n;i++)cnt[a[i]]++;
 int ans = 0;
 for(int i=1;i<=n;i++)
 {
			dp[i] = max(dp[last[a[i]]],now[a[i]-1])+1;//take all prev + one now
 if(now[a[i]-1] == cnt[a[i]-1])dp[i] = max(dp[i],dp2[a[i]-1]+1);//take all + 1
			last[a[i]] = i;
			now[a[i]]++;
			ans = max(dp[i],ans);
 if(now[a[i]] == cnt[a[i]])dp2[a[i]] = dp[first[a[i]]]+cnt[a[i]]-1;
 }
		cout<<n-ans<<'\n';
 
 }
 
}
