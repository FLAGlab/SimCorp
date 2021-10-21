#include<bits/stdc++.h>
#define rep(i,l,r) for(register int i=l;i<=r;i++)
#define per(i,r,l) for(register int i=r;i>=l;i--)
using namespace std;
inline int read() {
 int x=0;char c=getchar();
 while(c>'9'||c<'0')c=getchar();
 while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
 return x;
}
const int N=1e6+5;
int n,q,last,tot,a[N],pos[N],pre[N],bel[N],divv[N];
vector<pair<int,int> >link;
namespace union_set {
 int fa[N];
 void csh(int n) {
		rep(i,1,n) fa[i]=i; return ; 
 }
 int find(int u) {
 return fa[u]==u?u:find(fa[u]);
 }
 void megre(int u,int v) {
		fa[find(u)]=find(v); return ;
 }
} 
int main() {
	n=read(),q=read(); union_set::csh(n);
	rep(i,1,n) a[i]=read(),pos[a[i]]=i; 
	rep(i,2,N-1) {
 if(pre[i]) continue; last=-1;
 for(int j=i;j<=N;j+=i) {
 if(pos[j]) {
 if(!last) bel[i]=union_set::find(pos[j]);
 else union_set::megre(last,pos[j]);
 } pos[j]=i;
 }
 }
	rep(i,2,N-1) if(pre[i]==i) bel[i]=union_set::find(bel[i]);
 for(int i=1,k=a[1]+1;i<=n;k=a[++i]+1) {
		tot=0; divv[++tot]=union_set::find(i); while(k) divv[++tot]=bel[pre[k]],k/=pre[k];
		 sort(divv+1,divv+1+tot); tot=unique(divv+1,divv+tot+1)-divv-1;
		 rep(j,1,tot-1) rep(t,j+1,tot) link.push_back({divv[i],divv[j]}); 
 } sort(link.begin(),link.end());
	rep(i,1,q) {
 int x=union_set::find(read()),y=union_set::find(read());
 if(x==y) printf("0\n");
 else {
			pair<int,int> now={min(x,y),max(x,y)};
 auto ite=lower_bound(link.begin(),link.end(),now);
 if(ite!=link.end()&&*ite==now) printf("1\n");
 else printf("2\n");
 } 
 } 
}
