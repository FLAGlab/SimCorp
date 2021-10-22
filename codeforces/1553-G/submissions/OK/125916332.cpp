#include<bits/stdc++.h>
#define rg register
using namespace std;
const int N=15e4+5,MAX=1e6+5;
 
int n,q,a[N],fa[N],upb,node[MAX];
set<pair<int,int> > s;
 
struct factorer{
 int tot,p[9];
}fct[MAX];
 
int find(int u){
 return fa[u]==u?u:fa[u]=find(fa[u]);
}
 
void merge(int u,int v){
	u=find(u),v=find(v);
 if(u!=v) fa[u]=v;
}
 
void read(int &x){
 int res=0;char ch=getchar();
 while(!isdigit(ch)) ch=getchar();
 while(isdigit(ch)) res=res*10+ch-'0',ch=getchar();
	x=res;
}
 
void init(){
 for(rg int i=2;i<=upb;++i)
 if(!fct[i].tot)
 for(int j=1;j*i<=upb;++j)
		    	fct[i*j].p[++fct[i*j].tot]=i;
 for(rg int i=1;i<=n;++i)
 for(int j=1,num;j<=fct[a[i]].tot;++j)
 if(!node[num=fct[a[i]].p[j]]) node[num]=i;
 else merge(node[num],i);
 for(rg int i=1;i<=n;++i){
 int newnum=a[i]+1,cnt=0,mem[9]={find(i)};
 for(int j=1;j<=fct[newnum].tot;++j){
			mem[++cnt]=find(node[fct[newnum].p[j]]);
 }
 for(rg int j=1;j<=cnt;++j)
 for(int k=0;k<j;++k){
				s.insert({mem[j],mem[k]}),s.insert({mem[k],mem[j]});
 }
 }
}
 
signed main(){
    read(n),read(q);
 for(rg int i=1;i<=n;++i)
		read(a[i]),fa[i]=i,upb=max(upb,a[i]+1);
    init();
 for(rg int i=1,u,v;i<=q;++i){
    	read(u),read(v);
    	u=find(u),v=find(v);
 if(u==v) puts("0");
 else if(s.count({u,v})) puts("1");
 else puts("2");
 }
 return 0;
}
