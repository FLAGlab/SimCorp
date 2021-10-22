#include<bits/stdc++.h>
#define ll long long
#define pa pair<int,int>
#define mkp make_pair
#define pb push_back
#define int long long
using namespace std;
ll f[1010][20010];
bool g[1010][20010];
ll c[2010],cost[2010];
ll n,w,b,x,cnt,tot;
bool mrk;
inline void refresh(int i,int mx,int s)
{
 for (int j=mx;j>=cnt;j--)
 {
 if (g[i][j])f[i][j]=max(f[i][j],f[i][j-s]-cost[i]*s);
 else if (f[i][j-s]>=cost[i]*s)
 {
            g[i][j]=1;
            f[i][j]=f[i][j-s]-cost[i]*s;
 }
 }
}
int lowbit(int x){return x&(-x);}
inline void work()
{
    scanf("%lld%lld%lld%lld",&n,&w,&b,&x);
 for (int i=1;i<=n;i++)scanf("%lld",c+i);
 for (int i=1;i<=n;i++)scanf("%lld",cost+i);
 for (int i=1;i<=n;i++)
 {
 if (i==1)
 {
            f[1][0]=w;
 for (int j=1;j<=c[1];j++)
 if (w>=j*cost[1])
 {
                tot++;
                f[1][j]=w-j*cost[1];
                g[1][j]=1;
 }
 continue;
 }
 for (int j=0;j<=tot;j++)f[i][j]=min(f[i-1][j]+x,w+b*j),g[i][j]=1;
 while (f[i][cnt]==w+b*cnt)cnt++;
 int s=1,mx=tot;
 if (c[i])
 {
 int tmp=c[i];while (lowbit(tmp)!=tmp)tmp-=lowbit(tmp);
            tmp--;
            c[i]-=tmp;
            refresh(i,mx+c[i],c[i]);mx+=c[i];
 while (tmp)
 {
 if (tmp&1)refresh(i,mx+s,s);
                mx+=s;
                s<<=1;
                tmp>>=1;
 }
 }
 while (g[i][tot+1])tot++;
 }
    printf("%lld\n",tot);
}
signed main()
{
 //int T;scanf("%d",&T);
 int T=1;
 while (T--)work();
}
