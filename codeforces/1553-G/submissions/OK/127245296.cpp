#include<bits/stdc++.h>
using namespace std;
inline int read()
{
 char c=getchar();
 int x=0;
 while(c<'0'||c>'9')
		c=getchar();
 while(c>='0'&&c<='9')
 {
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
 }
 return x;
}
int a[150005],fir[150005],fa[1000005],v[10],cnt;
set<int>tg[1000005];
int get(int x)
{
 if(fa[x]!=x)
 return fa[x]=get(fa[x]);
 return x;
}
signed main()
{
 int n=read(),q=read(),i,j,x,m=0;
 for(i=1;i<=n;i++)
 {
		a[i]=read();
		m=max(m,a[i]);
 }
 for(i=1;i<=m;i++)
		fa[i]=i;
 for(i=1;i<=n;i++)
 {
		x=a[i];
 for(j=2;j*j<=x;j++)
 if(x%j==0)
 {
				v[++cnt]=j;
 while(x%j==0)
					x/=j;
 }
 if(x>1)
			v[++cnt]=x;
		fir[i]=v[1];
 for(j=2;j<=cnt;j++)
 for(x=1;x<j;x++)
				fa[get(v[x])]=get(v[j]);
		cnt=0;
 }
 for(i=1;i<=n;i++)
 {
		x=a[i]+1;
 for(j=2;j*j<=x;j++)
 if(x%j==0)
 {
				v[++cnt]=get(j);
 while(x%j==0)
					x/=j;
 }
 if(x>1)
			v[++cnt]=get(x);
		sort(v+1,v+cnt+1);
		cnt=unique(v+1,v+cnt+1)-v-1;
 int tmp=get(fir[i]);
 for(j=1;j<=cnt;j++)
 if(v[j]<tmp)
				tg[v[j]].insert(tmp);
 else
				tg[tmp].insert(v[j]);
 for(j=2;j<=cnt;j++)
 for(x=1;x<j;x++)
				tg[v[x]].insert(v[j]);
		cnt=0;
 }
 while(q--)
 {
		i=read();
		j=read();
 int fi=get(fir[i]),fj=get(fir[j]);
 if(fi==fj)
			puts("0");
 else
 {
 if(fi>fj)
				swap(fi,fj);
 if(tg[fi].count(fj))
				puts("1");
 else
				puts("2");
 }
 }
 return 0;
}
