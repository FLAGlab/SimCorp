#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int f[N],p[N],pcnt,mx,n,q,a[N],fa[N],pd[N],d[N],b[N];
vector<int> ans[N];
inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
inline void merge(int x,int y){
	x=find(x);y=find(y);
 if(x!=y) fa[x]=y; 
}
map<pair<int,int>,bool> mp;
inline void init(int n){
 for(int i=2;i<=n;++i){
 if(!f[i]) p[++pcnt]=i;
 for(int j=1;j<=pcnt&&i*p[j]<=n;++j){
			f[i*p[j]]=1;
 if(i%p[j]==0) break;
 }
 }
 for(int i=1;i<=pcnt;++i){
 int las=-1;
 vector<int> ve;
 for(int j=p[i];j<=n;j+=p[i]){
 if(b[j]) ve.push_back(b[j]);
 if(d[j]){
 if(las==-1) las=d[j];
 else merge(d[j],las),las=d[j];
 }
 }
 if(las!=-1){
//			bel[j]=find(las)
 for(int v:ve) ans[v].push_back(las);
 }
 }
}
signed main(){
	scanf("%d%d",&n,&q);
 for(int i=1;i<=n;++i) fa[i]=i;
 for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);d[a[i]]=i;b[a[i]+1]=i;
 }
	init(1000001);
 for(int i=1;i<=n;++i){
		ans[i].push_back(find(i));
 for(int j=0;j<ans[i].size();++j){
 for(int k=j+1;k<ans[i].size();++k){
 int t=find(ans[i][j]),q=find(ans[i][k]);
 if(t!=q) mp[make_pair(t,q)]=mp[make_pair(q,t)]=1;
 }
 }
 }
 while(q--){
 int x,y;
		scanf("%d%d",&x,&y);
 if(find(x)==find(y)) puts("0");
 else{
 if(mp[make_pair(find(x),find(y))]) puts("1");
 else puts("2");
 }
 }
 return 0;
}
