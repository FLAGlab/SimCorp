#include<bits/stdc++.h>
 
#define set(a,b) memset(a,(b),sizeof(a))
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
 
const int maxn=1e3+5;
const int maxc=1e4+5;
const int maxt=16384+5;
 
struct Segtree{
 int l,r,v,tag;
}tr[maxt];
 
int f[maxn][maxc];
int a[maxn],c[maxn];
int n,W,B,X,sum,ans;
 
void Build(int x,int l,int r){
  tr[x].l=l,tr[x].r=r,tr[x].tag=INT_MIN,tr[x].v=INT_MIN;;
 if( l==r ) return ;
 Build(x<<1,l,(l+r)/2),Build(x<<1^1,(l+r)/2+1,r);
}
 
void Pushdown(int x){
 if( tr[x].tag!=INT_MIN ){
    tr[x<<1].tag=max(tr[x<<1].tag,tr[x].tag);
    tr[x<<1].v=max(tr[x<<1].v,tr[x].tag);
    tr[x<<1^1].tag=max(tr[x<<1^1].tag,tr[x].tag);
    tr[x<<1^1].v=max(tr[x<<1^1].v,tr[x].tag);
    tr[x].tag=INT_MIN;
 }
}
 
void Modify(int x,int l,int r,int v){
 if( l<=tr[x].l && tr[x].r<=r ){
    tr[x].tag=max(tr[x].tag,v);
    tr[x].v=max(tr[x].v,v);
 return ;
 }
 if( l<=(tr[x].l+tr[x].r)/2 ) Modify(x<<1,l,r,v);
 if( (tr[x].l+tr[x].r)/2<r ) Modify(x<<1^1,l,r,v);
}
 
int Query(int x,int p){
 if( tr[x].l==tr[x].r ) return tr[x].v;
 Pushdown(x);
 if( p<=(tr[x].l+tr[x].r)/2 )
 return Query(x<<1,p);
 else return Query(x<<1^1,p);
}
 
void DP(){
 set(f,-1);
  f[0][0]=W;
 for(int i=1;i<=n;i++){
 Build(1,0,sum);
 for(int j=0;j<=sum;j++){
 if( f[i-1][j]!=-1 ){
 int p;
 if( c[i]==0 ) p=j+a[i];
 else p=j+min(a[i],min(f[i-1][j]+X,W+j*B)/c[i]);
 Modify(1,j,p,min(f[i-1][j]+X,W+j*B)+j*c[i]);
 }
 int w=Query(1,j);
 if( w!=INT_MIN ) f[i][j]=min(w-j*c[i],W+j*B);
 }
 }
 for(int i=sum;i>=0;i--)
 if( f[n][i]!=-1 ){
      ans=i;
 break;
 }
}
 
signed main(){
  cin >> n >> W >> B >> X ;
 for(int i=1;i<=n;i++) cin >> a[i] ;
 for(int i=1;i<=n;i++) cin >> c[i] ;
 for(int i=1;i<=n;i++) sum+=a[i];
  DP();
  cout << ans << endl ;
 return 0;
}
