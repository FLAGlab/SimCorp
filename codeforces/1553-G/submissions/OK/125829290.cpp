#include<bits/stdc++.h>
#define re register
using namespace std;
typedef long long ll;
const int N=2e6+10;
const int M=2e6+10;
inline int read()
{
 int s=0,w=1;
 char c=getchar();
 while(c<'0'||c>'9')
 {
 if(c=='-') w=-1;
		c=getchar();
 }
 while(c>='0'&&c<='9') s=s*10+c-'0',c=getchar();
 return s*w;
}
set<pair<int,int> >s;
vector<int> q[M];
int n,m,a[N],ma,f[N],x,y,pl[N];
inline int find(int x)
{
 if(f[x]==x) return x;
 return f[x]=find(f[x]);
}
signed main(){
	n=read();m=read();
 for(re int i=1;i<=n;++i)
 {
		a[i]=read();
 if(a[i]>ma) ma=a[i];
 }
 for(re int i=1;i<=ma+1;++i) f[i]=i;
 for(re int i=2;i<=ma+1;++i)
 {
 if(q[i].empty())
 {
 for(re int j=i;j<=ma+1;j+=i)
				q[j].push_back(i),pl[j]++;
 }
 }
 for(re int i=1;i<=n;++i)
 for(re int j=0;j<pl[a[i]];++j)
			f[find(a[i])]=find(q[a[i]][j]);
 for(re int i=1;i<=n;++i)
 {
 vector<int>p=q[a[i]+1];
		p.push_back(a[i]);
 int nn=p.size();
 for(re int j=0;j<nn;++j)
 for(re int k=j+1;k<nn;++k)
 {
 int x=p[j],y=p[k];
				x=find(x);y=find(y);
 if(x>y) swap(x,y);
 if(x!=y) 
 {
					s.insert(make_pair(x,y));
 }
 }
 }
 while(m--)
 {
		x=read();y=read();
		x=find(a[x]);y=find(a[y]);
 if(x>y) swap(x,y);
 if(x==y) puts("0\n");
 else if(s.count(make_pair(x,y))) puts("1\n");
 else puts("2\n");
 }
 return 0;
}
