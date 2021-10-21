#include<cstdio>
#include<iostream>
#include<cstring>
 
using namespace std;
const int N=1e3+10,M=1e4;
typedef long long ll;
 
int n,w,a,b;
ll c[N],cost[N],dp[N][M+10];
int main(){
	scanf("%d%d%d%d",&n,&w,&a,&b);
 for(int i=1;i<=n;i++)scanf("%lld",c+i);
 for(int i=1;i<=n;i++)scanf("%lld",cost+i);
	memset(dp,-0x3f,sizeof(dp)); 
	dp[0][0]=w;
 for(int i=1;i<=n;i++){
 for(int k=0;k<=c[i];k++){
 for(int j=M;j>=k;j--){
				ll mg=min(dp[i-1][j-k]+b,1ll*(j-k)*a+w)-k*cost[i];
 if(mg>=0)dp[i][j]=max(dp[i][j],mg);
 }
 }
 }
 int ans=0;
 for(int i=1;i<=M;i++)if(dp[n][i]>=0)ans=max(ans,i);
	printf("%d\n",ans);
 return 0;
}
