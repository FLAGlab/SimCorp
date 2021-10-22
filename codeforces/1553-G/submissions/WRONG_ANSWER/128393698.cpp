#include<bits/stdc++.h>
using namespace std;
#define Maxn 150005
#define Maxm 1000005
typedef long long ll;
inline int rd()
{
 int x=0;
 char ch,t=0;
 while(!isdigit(ch = getchar())) t|=ch=='-';
 while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
 return x=t?-x:x;
}
int n,q,m=1000001,cnt;
int a[Maxn],fa[Maxm],app[Maxn];
bool exist[Maxm],hav[Maxm];
int Find(int x) { return (fa[x]==x)?x:(fa[x]=Find(fa[x])); }
bool solve(int x,int k)
{
 for(int i=1;i<=cnt;i++) hav[app[i]]=false;
	 cnt=0;
 for(int i=2;i*i<=x;i++) if(x%i==0)
	 	 app[++cnt]=Find(i),hav[app[cnt]]=true;
	 app[++cnt]=Find(x);
 if(hav[k]) return true;
 return false;
}
signed main()
{
 //ios::sync_with_stdio(false); cin.tie(0);
 //freopen(".in","r",stdin);
 //freopen(".out","w",stdout);
	 n=rd(),q=rd();
 for(int i=1;i<=n;i++) a[i]=rd(),exist[a[i]]=true;
 for(int i=1;i<=m;i++) fa[i]=i;
 for(int i=2;i<=m;i++) for(int j=i+i;j<=m;j+=i)
 if(exist[j] && Find(i)!=Find(j)) fa[Find(j)]=Find(i);
 for(int i=1,l,r;i<=q;i++)
 {
	 	 l=rd(),r=rd();
 if(Find(a[l])==Find(a[r])) printf("0\n");
 else if(solve(a[l]+1,Find(a[r])) || solve(a[r]+1,Find(a[l])))
		  	 printf("1\n");
 else printf("2\n");
 }
 //fclose(stdin);
 //fclose(stdout);
 return 0;
}
