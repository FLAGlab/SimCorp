#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=10000000000000000ll;
ll f[1001][10005];
ll cost[1001],num[1001],W,B,X,n;
signed main()
{
	cin>>n>>W>>B>>X;
 for(int i=1;i<=n;i++) cin>>num[i];
 for(int i=1;i<=n;i++) cin>>cost[i];
 for(int i=0;i<=n;i++)
 for(int j=0;j<=10000;j++)
	  f[i][j]=-INF;
	f[0][0]=W;
 for(int i=0;i<n;i++)
 for(int j=0;j<=10000;j++)
 {
 if(f[i][j]==-INF) break;
 int now=min(W+j*B,f[i][j]+X);
 for(int k=0;k<=num[i+1];k++)
 if(k*cost[i+1]<=now)
	 	  f[i+1][j+k]=max(f[i+1][j+k],now-k*cost[i+1]);
 }
 int ans=0;
 for(int i=0;i<=10000;i++) if(f[n][i]!=-INF) ans=i;
	cout<<ans<<endl;
 
 return 0;
}
 
