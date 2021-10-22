#include<bits/stdc++.h>
using std::multiset;
using std::pair;
//using AK::IOI;
#define re register
#define pr pair<int,int>
inline int min(int x,int y){return x<y?x:y;}
inline int max(int x,int y){return x>y?x:y;}
inline void swp(int &x,int &y){x^=y^=x^=y;}
inline int win(){
 int x=0;char c=getchar();
 while(c>'9'||c<'0') c=getchar();
 while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
 return x;
}
 
const int N=150050,P=1000050;
int n,fa[N],a[N],nod[P];
struct primes{int c,p[11];}t[P];
int get(int x){return x==fa[x]?x:fa[x]=get(fa[x]);}
inline void merge(int x,int y){
	x=get(x),y=get(y);
 if(x!=y) fa[x]=y;
}
inline void init(){
 int m=0;
 for(re int i=1;i<=n;i++) fa[i]=i,m=max(m,a[i]=win());
 ++m;
 for(re int i=2;i<=m;i++)
 if(!t[i].c) for(re int j=i;j<=m;j+=i) t[j].p[++t[j].c]=i;
 for(re int i=1,aa;i<=n;i++){
		aa=a[i];
 for(re int j=1,p;j<=t[aa].c;j++)
 if(nod[p=t[aa].p[j]]) merge(nod[p],i);
 else nod[p]=i;
 }
 for(re int i=2;i<=m;i++) if(nod[i]) nod[i]=get(nod[i]);
}
multiset<pr> edges;
inline void filltheset(){
 int pn[11],cnt;
 for(re int i=1,newa;i<=n;i++){
		cnt=0,newa=a[i]+1,pn[0]=get(i);
 for(re int j=1,p;j<=t[newa].c;j++)
 if((p=t[newa].p[j])!=a[i]) pn[++cnt]=nod[p];
 for(re int j=1;j<=cnt;j++)
 for(re int k=0;k<j;k++)
				edges.insert((pr){pn[j],pn[k]}),edges.insert((pr){pn[k],pn[j]});
 }
}
signed main(){
	n=win();int q=win(),s,t;
	init(),filltheset();
 while(q--){
		s=get(win()),t=get(win());
 if(s==t) putchar('0');
 else if(edges.count((pr){s,t})) putchar('1');
 else putchar('2');
		putchar('\n');
 }
 return 0;
}
