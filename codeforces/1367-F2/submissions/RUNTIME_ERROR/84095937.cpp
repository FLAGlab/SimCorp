#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef double dd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef pair<int, ll> il;
typedef pair<ll , ll> lli;
typedef vector<ii> vii;
typedef vector<il> vil;
typedef vector<li> vli;
typedef vector<lli> vlli;
 
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define in insert
#define f0(b) for(int i=0;i<(b);i++)
#define f00(b) for(int j=0;j<(b);j++)
#define f1(b) for(int i=1;i<=(b);i++)
#define f11(b) for(int j=1;j<=(b);j++)
#define f2(a,b) for(int i=(a);i<=(b);i++)
#define f22(a,b) for(int j=(a);j<=(b);j++)
#define sf(a) scanf("%lld",&a)
#define sff(a,b) scanf("%lld %lld", &a , &b)
#define pf(a) printf("%lld\n",a)
#define pff(a,b) printf("%lld %lld\n", a , b)
#define PI 3.14159265359
#define bug printf("**!\n")
#define mem(a , b) memset(a, b ,sizeof(a))
#define front_zero(n) __builtin_clzll(n)
#define back_zero(n) __builtin_ctzll(n)
#define total_one(n) __builtin_popcountll(n)
 
const ll mod = (ll)998244353;
const ll maxn = (ll)5e5+5;
const int nnn = 1048590;
const int inf = numeric_limits<int>::max()-1;
//const ll INF = numeric_limits<ll>::max()-1;
const ll INF = 1e18;
 
ll dx[]={0,1,0,-1};
ll dy[]={1,0,-1,0};
ll dxx[]={0,1,0,-1,1,1,-1,-1};
ll dyy[]={1,0,-1,0,1,-1,1,-1};
 
void solve(){
 
 vector < ll > v;
	ll n;
	cin >> n;
	ll a[n+5];
	f0(n) cin >> a[i] , v.pb(a[i]); 
	ll b[n+5];
	mem(b,0);
	sort(v.begin() , v.end());
 map < ll , ll > m;
 priority_queue < ll > p[n+5] , pp[n+5];
	ll cnt = 0;
 for(ll i = 0; i < n; i++){
 if(m[v[i]] == 0) m[v[i]] = ++cnt;
 }
	ll dp[n+5];
	ll pre[n+5];
	mem(dp,0);
	mem(pre,-1);
 for(ll i = 0; i < n ; i++){
		dp[m[a[i]]] = i;
 }
	ll ans = 1;
 bool ok[n+5];
	mem(ok , 0);
 for(ll i = 0; i < n; i++){
		ll use = m[a[i]];
 //printf("%lld\n", i);
 if(use == 1){
 if(p[1].size() == 0) p[1].push(1) , b[i] = 1;
 else p[1].push( (p[1].top() )+1) , b[i] = p[1].top();
			pp[1].push(b[i]);
 }else{
 if(use == 2) ans = max(ans , (ll)p[1].size()+1);
 if(p[use].size() != 0){
 if(dp[use-1] < i){
		 	b[i] = p[use].top()+1;
		 	p[use].push(b[i]);
 if(!ok[use])pre[i] =  pp[use-1].top()+1;
		 	pp[use].push(b[i]);
		 	pp[use].push(pre[i]); 
 }else{
 if(!ok[use])pre[i] = pp[use].top()+1;
		 	b[i] = p[use].top()+1;
		 	p[use].push(b[i]);
		 	pp[use].push(pre[i]);
 if(dp[use]!=i)ok[use+1] = 1;
 }
 }else{
 if(p[use-1].size() == 0) p[use].push(1) , b[i] = 1, pp[use].push(1);
 else{
 if(dp[use-1] < i){
 if(p[use-1].size() != 0)b[i] = p[use-1].top()+1, p[use].push(b[i]);
 else p[use].push(1) , b[i] = 1;
					pp[use].push(b[i]);
 if(!ok[use])pre[i] = pp[use-1].top()+1;
 if(!ok[use]) pp[use].push(pre[i]);
 }else{
 if(p[use-1].size()!=0)pre[i] = p[use-1].top()+1, b[i] = 1;
 else b[i] = 1;
 if(!ok[use])pp[use].push(pre[i]);
					p[use].push(b[i]);
 if(dp[use] != i)ok[use+1] = 1;
 }
 }
 }
 }
 //cout << i << ' ' << b[i] << ' ' << pre[i] << '\n';
 		ans= max(ans , max(pre[i] , b[i]) );
 }
	cout << n -ans << '\n';
 return;
}
 
 
int main() {
 
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll T;
    T=1;
    cin >> T;
 //scanf("%lld",&T);
    ll CT = 0;
 //work();
 while(T--){
 //cout << "Case " << ++CT <<": " ;
 //printf("Case %lld: ",++CT);
		solve();
 }
 
 return 0;
}
 
