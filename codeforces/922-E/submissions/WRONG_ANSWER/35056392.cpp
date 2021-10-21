#include<bits/stdc++.h>
using namespace std;
int main(){
 int n,w,b,x,sz=0,turn=0,c[1001],cost[1001];
 long long dp[2][10001];
  scanf("%d%d%d%d",&n,&w,&b,&x);
 for(int i=1;i<=n;i++){
    scanf("%d",&c[i]);
 }
 for(int i=1;i<=n;i++){
    scanf("%d",&cost[i]);
 }
 for(int i=0;i<=10000;i++){
    dp[0][i]=dp[1][i]=-1e12;
 }
  dp[0][0]=w;
 for(int i=1;i<=n;i++){
 for(int j=0;j<=sz;j++){
 for(int k=0;k<=c[i];k++){
        dp[turn^1][j+k]=max(dp[turn^1][j+k],min(w+1LL*j*b,dp[turn][j]+x)-1LL*k*cost[i]);
 }
 }
 for(int j=0;j<=10000;j++){
      dp[turn][j]=-1e12;
 }
    sz += c[i];
    turn^=1;
 }
 for(int j=sz;j>=0;j--){
 if(dp[turn][j]>=0){
      printf("%d\n",j);
 break;
 }
 }
 return 0;
}
