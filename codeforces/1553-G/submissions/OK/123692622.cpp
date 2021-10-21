#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5,M=1e6+5;
int n,m,q,a[N],b[2][M],f[M],c[N],g[15],vis[M];
vector<int>d[N];
set<pair<int,int> >E;
int get(int x){
 if (x==f[x]) return x;
 return f[x]=get(f[x]);
}
int main(){
	scanf("%d%d",&n,&q);
 for (int i=1;i<=n;i++)
		scanf("%d",&a[i]),
		m=max(m,a[i]+1),
		b[0][a[i]]=i,
		b[1][a[i]+1]=i;
 for (int i=1;i<=m;i++) f[i]=i;
 for (int i=2,v;i<=m;i++) if (!vis[i]){
 for (int j=i;j<=m;j+=i){
 if (v=b[0][j]){
 if (!c[v]) c[v]=i;
 else f[get(c[v])]=i,c[v]=i;
 }
			vis[j]=1;
 }
 }
 for (int i=2,v;i<=m;i++) if (vis[i]){
 for (int j=i;j<=m;j+=i){
 if (v=b[1][j])
				d[v].push_back(i);
			vis[j]=0;
 }
//		cout<<i<<" "<<get(i)<<endl;
 }
 for (int i=1,j,v,u;i<=n;i++){
//		cout<<c[i]<<endl;
		j=d[i].size();u=0;
 for (int k=0;k<j;k++){
			v=get(d[i][k]);
 if (vis[v]<i) g[++u]=v,vis[v]=i;
 }
		v=get(c[i]);
 if (vis[v]<i) g[++u]=v;
//		for (int k=1;k<=u;k++) cout<<g[k]<<" ";puts("");
 for (int k=1;k<=u;k++)
 for (int l=1;l<k;l++)
				E.insert(make_pair(min(g[k],g[l]),max(g[k],g[l])));//,cout<<"link:"<<g[k]<<" "<<g[l]<<endl;
 }
 for (int u,v;q--;){
		scanf("%d%d",&u,&v);
		u=get(c[u]);v=get(c[v]);
 if (u==v) puts("0");
 else if (E.count(make_pair(min(u,v),max(u,v)))) puts("1");
 else puts("2");
 }
 return 0;
}
 
