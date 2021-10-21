#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e5+10;
struct node{
 int nxt,ver,wei;
}e[M<<1];
int head[M],tot=0;
void add(int x,int y,int z){
	e[++tot].ver=y;
	e[tot].wei=z;
	e[tot].nxt=head[x];
	head[x]=tot;
}
int dep[M],d[M],size[M],f[M];
bool vis[M];
int root=0,S=0,n=0,k=0,ans=0;
void getroot(int u,int fa){
	size[u]=1;
	f[u]=0;
 for (int i=head[u];i;i=e[i].nxt){
 int v=e[i].ver;
 if (fa!=v&&!vis[v]){
			getroot(v,u);
			size[u]+=size[v];
			f[u]=max(f[u],size[v]);
 }
 }
	f[u]=max(f[u],S-size[u]);
 if (f[u]<f[root]){
		root=u;
 }
}
void getdep(int u,int fa){
	dep[++dep[0]]=d[u];
 for (int i=head[u];i;i=e[i].nxt){
 int v=e[i].ver;
 if (fa!=v&&!vis[v]){
			d[v]=d[u]+e[i].wei;
			getdep(v,u);
 }
 }
}
int getsum(int u,int dis){
	d[u]=dis;
	dep[0]=0;
	getdep(u,0);
	sort(dep+1,dep+1+dep[0]);
 int l=1,r=dep[0],sum=0;
 while (l<r){
 if (dep[l]+dep[r]<k){
			l++;
 }
 else if (dep[l]+dep[r]>k){
			r--;
 }
 else {
 if (dep[l]==dep[r]){
				sum+=(r-l)*(r-l+1)/2;
 break;
 }
 else {
 int x=1,y=1,s=l,t=r;
 while (dep[t]==dep[t-1]){
					x++;
					t--;
 }
 while (dep[s]==dep[s+1]){
					y++;
					s--;
 }
				sum+=x*y;
				l=s+1;
				r=t-1;
 }
 }
 }
 return sum;
}
void slv(int u){
	vis[u]=1;
	ans+=getsum(u,0);
 for(int i=head[u];i;i=e[i].nxt){
 int v=e[i].ver;
 if (!vis[v]){
			ans-=getsum(v,e[i].wei);
			root=0;
			S=size[v];
			getroot(v,u);
			slv(root);
 }
 }
}
signed main(){
 ::std::ios::sync_with_stdio(false);
 ::cin.tie(0);
 ::cout.tie(0);
	cin>>n>>k;
	memset(vis,0,sizeof(vis));
 int x,y;
 for (int i=1;i<n;i++){
		cin>>x>>y;
		add(x,y,1);
		add(y,x,1);
 }
	root=0;
	ans=0;
	f[0]=0x7fffffff;
	S=n;
	getroot(1,0);
	slv(root);
	cout<<ans<<endl;
 return 0;
}
/*
10 3
2 1
3 1
4 3
5 4
6 5
7 1
8 6
9 2
10 6
 
 
expected 8
found 7
*/
