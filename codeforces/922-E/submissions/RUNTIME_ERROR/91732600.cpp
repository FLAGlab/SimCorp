#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define pb push_back
using namespace std;
const int N1=1e3+1;
const int N2=1e4+1;
int n;
ll cost[N1], W, B, X, c[N1], dp[2][N2];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie();
 //freopen("read.inp", "r", stdin);
 //freopen("read.out", "w", stdout);
	cin>>n>>W>>B>>X;
 for(int i=1; i<=n; i++){
        cin>>c[i];
 }
 for(int i=1; i<=n; i++){
        cin>>cost[i];
 }
	memset(dp, -1, sizeof dp);
 for(int i=0; i<=min(c[1], W/cost[1]); i++){
        dp[1][i]=W-cost[1]*(ll)i;
 }
 int sum=c[1];
 for(int i=2; i<=n; i++){
 int cur=i&1, pre=cur^1;
        deque<pair<ll, int>> dq;
        sum+=c[i];
 for(int j=0; j<=sum; j++){
 if(dp[pre][j]!=-1){
                ll tmp=min(dp[pre][j]+X, W+B*(ll)j)+cost[i]*(ll)j;
 while(!dq.empty()&&tmp>=dq.back().fi) dq.pop_back();
                dq.push_back({tmp, j});
 }
 while(!dq.empty()&&j-dq.front().se>c[i]) dq.pop_front();
 if(!dq.empty()&&dq.front().fi>=cost[i]*(ll)j)
                dp[cur][j]=dq.front().fi-cost[i]*(ll)j;
 }
 }
 int ans=0, cur=n&1;
 for(int i=sum; i>=0; i--){
 if(dp[cur][i]!=-1){
            ans=i;
 break;
 }
 }
	cout<<ans<<endl;
}
