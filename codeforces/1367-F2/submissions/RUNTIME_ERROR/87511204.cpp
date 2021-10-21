#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAX_N=2e5+20;
const int INF=0x3f3f3f3f;
const LL MOD=998244353;
int n;
int a[MAX_N],b[MAX_N];
int l[MAX_N],r[MAX_N];
int pre[MAX_N];
int dp[MAX_N][3];
int t;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("1.in","r",stdin);
    cin>>t;
 while(t--){
        cin>>n;
 map<int,int>M;
 map<int,int>num;
 int tot=1;
 for(int i=1;i<=n;i++){
            cin>>a[i];
            b[i]=a[i];
            dp[i][0]=dp[i][1]=dp[i][2]=0;
 }
        sort(b+1,b+n+1);
 for(int i=1;i<=n;i++){
 if(!M.count(b[i])){
                M[b[i]]=tot++;
 }
 }
 for(int i=1;i<tot;i++){
            l[i]=r[i]=pre[i]=0;
 }
 //离散化
 for(int i=1;i<=n;i++){
            a[i]=M[a[i]];
            num[a[i]]++;
 
 }
 for(int i=1;i<=n;i++){
 if(!l[a[i]])l[a[i]]=i;
 }
 for(int i=n;i>=1;i--){
 if(!r[a[i]])r[a[i]]=i;
 }
 int cnt=0;
 for(int i=1;i<=n;i++){
            dp[i][0]=dp[pre[a[i]]][0]+1;
            dp[i][1]=max(dp[pre[a[i]-1]][0]+1,max(dp[pre[a[i]]][1]+1,dp[pre[a[i]-1]][2]+1));
 if(i==r[a[i]]){
                dp[i][2]=dp[l[a[i]]][1]+num[a[i]]-1;
 }
            pre[a[i]]=i;
            cnt=max(cnt,dp[i][0]);
            cnt=max(cnt,dp[i][1]);
            cnt=max(cnt,dp[i][2]);
 }
 
 int ans=n-cnt;
        cout<<ans<<endl;
 
 }
}
