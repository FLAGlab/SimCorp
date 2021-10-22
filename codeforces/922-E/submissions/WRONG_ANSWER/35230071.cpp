#include<bits/stdc++.h>
using namespace std;
int f[1001][10010],c[1010],cost[1010];
signed main()
{
 int n,w,b,x,sum=0;
	scanf("%d%d%d%d",&n,&w,&b,&x);
 for(int i=1;i<=n;i++) scanf("%d",&c[i]),sum+=c[i];
 for(int i=1;i<=n;i++) scanf("%d",&cost[i]);
 for(int i=0;i<=n;i++)
 for(int j=0;j<=sum;j++)
			f[i][j]=-1e8;
	f[0][0]=w-x;
 for(int i=1;i<=n;i++)
 {
 for(int j=0;j<=sum;j++)
 {
 for(int k=0;k<=c[i];k++)
 {
 if(j-k>=0) f[i][j]=max(f[i][j],f[i-1][j-k]-cost[i]*k+x);
 }
 
 if(f[i][j]<0) f[i][j]=-1e8;
			f[i][j]+=b;
 if(f[i][j]>w) f[i][j]=w;
 }
 }
 int ans=0;
 for(int j=0;j<=sum;j++)
 if(f[n][j]>=0) ans=max(ans,j);
	printf("%d",ans);
 return 0;
}
