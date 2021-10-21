#include<cstdio>
#include<algorithm>
using namespace std;
int dp[1005][10005],c[1005],cost[1005];
int n,w,b,x;
 
int main(){
	scanf("%d %d %d %d",&n,&w,&b,&x);
 int sc=0;
 for(int i=0;i<n;i++){
		scanf("%d",c+i+1);
		sc+=c[i+1];
 }
 for(int i=0;i<n;i++)
		scanf("%d",cost+i+1);
 for(int i=0;i<=n;i++)
 for(int j=0;j<=sc;j++)
			dp[i][j]=1000000000;
	dp[0][0] = 0;
 for(int i=1;i<=n;i++){
 for(int j=0;j<=sc;j++){
 if(j==0)dp[i][j]=0;
 for(int k=0;k<=c[i]&&j-k>=0;k++)
				dp[i][j]=min(dp[i][j],max(w+(j-k)*b,dp[i-1][j-k]+cost[i]*k));
 if(i!=1)dp[i][j]-=x;
 //printf("%d ",dp[i][j]);
 }
 //printf("\n");
 }
 for(int i=sc;i>=0;i--)
 if(dp[n][i]<=w){
			printf("%d",i);
 return 0;
 }
}
