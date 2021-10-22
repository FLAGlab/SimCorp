#include<bits/stdc++.h>
using namespace std;
int dp[1005][10005],c[1005],cost[1005];
int n,w,b,x;
 
signed main(){
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
			dp[i][j]=-2000000000;
	dp[0][0] = w;
 for(int i=1;i<=n;i++){
 for(int j=0;j<=sc;j++){
 int xx=x;
 if(i==1)xx=0;
 for(int k=0;k<=c[i]&&j-k>=0;k++){
				dp[i][j]=max(dp[i][j],min(dp[i-1][j-k]+xx,w+b*(j-k))-cost[i]*k);
 }
 if(dp[i][j]<0)dp[i][j]=-2000000000;
 //printf("%d ",dp[i][j]);
 }
 //printf("\n");
 }
 for(int i=sc;i>=0;i--)
 if(dp[n][i]>=0){
			printf("%d",i);
 return 0;
 }
}
