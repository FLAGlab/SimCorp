#include<bits/stdc++.h>
using namespace std;
#define N 55
#define For(i,x,y)for(i=x;i<=(y);i++)
int deg[N],x[N],y[N],fa[N],dep[N];
int find(int p)
{
 if(p!=fa[p])fa[p]=find(fa[p]);
 return fa[p];
}
inline void unite(int p,int q)
{
 if(dep[p]>dep[q])fa[q]=p;
 else fa[p]=q;
 if(dep[p]==dep[q])dep[q]++;
}
int main()
{
 int n,m,i,u,v,j,cnt=0;
	cin>>n>>m;
 For(i,1,n)fa[i]=i;
 For(i,1,m)
 {
		cin>>u>>v;
		deg[v]++;
		deg[u]++;
		unite(find(v),find(u));
 }
 For(i,1,n-1)
 For(j,i+1,n)
 while(deg[i]<2&&deg[j]<2)
 {
 if(m+cnt<n-1&&find(i)==find(j))break;
		unite(find(i),find(j));
		x[++cnt]=i;
		y[cnt]=j;
		deg[i]++;
		deg[j]++;
 }
 if(n==1&&!deg[1])x[1]=y[1]=cnt=1,deg[1]=2;
 For(i,1,n)
 if(find(i)!=find(1)||deg[i]>2)puts("NO"),exit(0);
	puts("YES");
	cout<<cnt;
 For(i,1,cnt)cout<<endl<<x[i]<<' '<<y[i];
 return 0;
}
