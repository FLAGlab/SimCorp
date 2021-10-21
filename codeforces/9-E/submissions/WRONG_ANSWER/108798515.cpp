#include<bits/stdc++.h>
using namespace std;
 
const int N=10005;
int n,m,fa[N],d[N],ok[N],tot;
int r[N][2],cnt;
vector<int> v[N],p;
 
int findfa(int x)
{
 return x==fa[x]?x:fa[x]=findfa(fa[x]);
}
 
int main()
{
	scanf("%d%d",&n,&m);
 if(m>n)
 {
		printf("NO\n");
 return 0;
 }
 for(int i=1;i<=n;i++) fa[i]=i;
 for(int i=1;i<=m;i++)
 {
 int x,y,fx,fy;
		scanf("%d%d",&x,&y);
		d[x]++,d[y]++;
 if(d[x]>2||d[y]>2||x==y)
 {
			printf("NO\n");
 return 0;
 }
		fx=findfa(x),fy=findfa(y);
 if(fx!=fy) fa[fx]=fy;
 }
 for(int i=1;i<=n;i++)
 {
 int ff=findfa(i);
 if(!ok[ff]) ok[ff]=++tot;
		v[ok[ff]].push_back(i);
 }
 for(int i=1;i<=tot;i++)
 {
 int jd=0,b[2],fx,fy;
 if(v[i].size()==1)
 {
			p.push_back(v[i][0]);
 continue;
 }
 for(int j=0;j<v[i].size();j++)
 {
 if(d[v[i][j]]==1)
 {
				b[jd++]=v[i][j];
 }
 }
//		cout<<i<<' '<<v[i].size()<<' '<<jd<<endl;
 if(jd!=2)
 {
			printf("NO\n");
 return 0;
 }
		fx=findfa(b[0]),fy=findfa(b[1]);
 if(fx!=fy) fa[fx]=fy;
		p.push_back(b[0]),p.push_back(b[1]);
 }
	sort(p.begin(),p.end());
 for(int i=0;i<p.size();i++)
 {
 if(d[p[i]]==2) continue;
 int fx,fy;
 for(int j=i+1;j<p.size();j++)
 {
			fx=findfa(p[i]),fy=findfa(p[j]);
 if(d[p[j]]==2||fx==fy&&cnt<n-m-1) continue;
//			cout<<p[i]<<' '<<p[j]<<' '<<fx<<' '<<fy<<endl;
//			printf("%d %d\n",p[i],p[j]);
			d[p[i]]++,d[p[j]]++;
			r[++cnt][0]=p[i],r[cnt][1]=p[j];
 if(fx!=fy) fa[fx]=fy;
 if(d[p[i]]==2) break;
 }
 }
 if(cnt!=n-m) printf("NO\n");
 else
 {
		printf("YES\n%d\n",n-m);
 for(int i=1;i<=cnt;i++) printf("%d %d\n",r[i][0],r[i][1]);
 }
}
