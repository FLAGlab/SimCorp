#include<bits/stdc++.h>
#define PI 3.141592653589793238462
#define eps 1e-20
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
set<pii> s;
int n,q,a[150005],p[1000006];
vector<int> c[1000006];
int find(int x){
 if(x==p[x]) return x;
 else return p[x]=find(p[x]);
}
void merge(int x,int y){
    p[find(x)]=find(y);
}
signed main(){
    scanf("%d%d",&n,&q);
 for(int i=1;i<=n;i++) scanf("%d",&a[i]);
 for(int i=2;i<=1000001;i++){
 if(p[i]) continue;
 for(int j=i;j<=1000001;j+=i){
            p[j]=1;c[j].push_back(i);
 }
 }
 for(int i=1;i<=1000001;i++) p[i]=i;
 for(int i=1;i<=n;i++){
 for(auto v:c[a[i]])merge(a[i],v);
 }
 for(int i=1;i<=n;i++){
 vector<ll> d;
        d.push_back(find(a[i]));
 for(auto k:c[a[i]+1]){
            d.push_back(find(k));
 }
 for(ll j=0;j<d.size();j++){
 for(ll k=0;k<d.size();k++){
                s.insert({d[j],d[k]});
                s.insert({d[k],d[j]});
 }
 }
 }
 while(q--){
 int x,y,t=0;
        scanf("%d%d",&x,&y);
        x=find(a[x]);y=find(a[y]);
 if(x==y) printf("0\n");
 else if(s.count({x,y})||s.count({y,x})) printf("1\n");
 else printf("2\n");
 }
} 
