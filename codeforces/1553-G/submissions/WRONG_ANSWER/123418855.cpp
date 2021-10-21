#include<bits/stdc++.h>
#define PI 3.141592653589793238462
#define eps 1e-30
#define fi first
#define se second
using namespace std;
using cd = complex<double>;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdd;
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
//rnd()%n,shuffle(a+1,a+n+1,rnd);
ll a[200005],n,tree[600005][2],pre,ans,m=3e5;
void add(ll x,ll v,ll t){
 while(x<=m*2){
        tree[x][t]+=v;
        x+=x&(-x);
 }
}
ll query(ll x,ll t){
    ll res=0;
 while(x){
        res+=tree[x][t];
        x-=x&(-x);
 }
 return res;
}
int main(){
    cin>>n;
 for(ll i=1;i<=n;i++) cin>>a[i];
 for(ll i=1;i<=n;i++){
        ans+=a[i]*(i-1)+pre;
        ans+=query(a[i],0);pre+=a[i];
 for(ll j=a[i];j<=m;j+=a[i]){
            ans-=(query(j+a[i]-1,1)-query(j-1,1))*j;
            add(j,-a[i],0);
 }
        add(a[i],1,1);cout<<ans<<" ";
 }cout<<endl;
}
