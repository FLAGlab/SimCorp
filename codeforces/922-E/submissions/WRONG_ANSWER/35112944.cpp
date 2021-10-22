#include<bits/stdc++.h>
using namespace std;
int n,W,B,X;
int c[1000000];
int cost[1000000];
unordered_map<int,int>dp[1001];
int cal(int i,int current){
if(i==n)return 0;
if(dp[i].find(current)!=dp[i].end())return dp[i][current];
int maxis=0;
for(int j=0;j<=c[i];j++){
 if(current-j*cost[i]>=0){
    maxis=max(maxis,j+cal(i+1,min(current+X+(B*j)-j*cost[i],W)));}
}
return dp[i][current]=maxis;
}
signed main(){
    cin>>n>>W>>B>>X;
 for(int i=0;i<n;i++){cin>>c[i];}
 for(int i=0;i<n;i++)cin>>cost[i];
    cout<<cal(0,W);
 return 0;
}
