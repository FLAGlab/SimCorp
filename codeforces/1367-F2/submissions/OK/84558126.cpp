#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+5;
const int mod=1e9+7;
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int,int> pii;
ll qpow(ll a,ll b){ll ans=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)ans=ans*a%mod;a=a*a%mod;}return ans;}
ll gcd(ll a,ll b){return b>0?gcd(b,a%b):a;}
int n,m,T;
int a[maxn];
vi v;
int getId(int x){
 return lower_bound(all(v),x)-v.begin()+1;
}
int dp[maxn];
int st[maxn];
int ed[maxn];
int f[maxn];
int g[maxn];
int cnt[maxn];
int main(){
	cin>>T;
 while(T--){
		cin>>n;
		v.clear();
 for(int i=1;i<=n;i++){
			cin>>a[i];
			v.pb(a[i]);
			st[i]=ed[i]=cnt[i]=0;
 }
		sort(all(v));
		v.erase(unique(all(v)),v.end());
 for(int i=1;i<=n;i++){
			a[i]=getId(a[i]);
			g[a[i]]=0;
			ed[a[i]]=i;
 if(!st[a[i]])st[a[i]]=i;
 }
 int ans=0;
 for(int idx,i=1;i<=n;i++){
			f[i]=1;
			f[i]=max(f[i],g[a[i]]+1);
			f[i]=max(f[i],g[a[i]]+1);
 if(a[i]>1){
				f[i]=max(f[i],cnt[a[i]-1]+1);
 if(ed[a[i]-1]<i){
					f[i]=max(f[i],f[st[a[i]-1]]+cnt[a[i]-1]);
 }
 }
			cnt[a[i]]++;
			g[a[i]]=f[i];
			ans=max(f[i],ans);
 }
		cout<<n-ans<<"\n";
 }
//	cin>>n>>m;
 
 return 0;
}
/*
1
4
0 1 0 2
*/
 
