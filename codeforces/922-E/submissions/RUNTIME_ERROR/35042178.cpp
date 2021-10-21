#include<iostream>
#include<cstdio>
typedef long long ll;
const int N=1e4+5;
ll dp[2][N];
int q[N],head,tail,n,c[N],sum[N];
ll w,b,x,cost[N];
int main() {
    scanf("%d%lld%lld%lld",&n,&w,&b,&x);
 for(int i=1;i<=n;i++) scanf("%d",c+i),sum[i]=c[i]+sum[i-1];
 for(int i=1;i<=n;i++) scanf("%lld",cost+i);
 for(int i=1;i<=sum[n];i++) dp[0][i]=-1;
    dp[0][0]=w;
 for(int i=1;i<=n;i++) {
 int t=i&1;
        dp[t][0]=w;q[tail++]=0;
 for(int j=1;j<=sum[i];j++) {
 if(dp[t^1][j]!=-1&&j<=sum[i-1]) {
 while(head<tail&&std::min(dp[t^1][j]+x,w+b*j)>=std::min(dp[t^1][q[tail-1]]+x,w+b*q[tail-1])-(j-q[tail-1])*cost[i]) tail--;
                q[tail++]=j;
 }
 while(head<tail&&(q[head]+c[i]<j||std::min(dp[t^1][q[head]]+x,w+b*q[head])<(j-q[head])*cost[i])) head++;
 if(head==tail) dp[t][j]=-1;
 else dp[t][j]=std::min(dp[t^1][q[head]]+x,w+b*q[head])-(j-q[head])*cost[i];
 }
 }
 int ans=0,t=n&1;
 for(int i=0;i<=sum[n];i++) if(dp[t][i]>=0) ans=i;
    printf("%d\n",ans);
 return 0;
}
