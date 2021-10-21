#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[1001][10001],a[10001],cost[10001];
int main()
{
    ll n,W,B,X,i,j,g;
    cin>>n>>W>>B>>X;
 for(i=1;i<=n;i++)
        cin>>a[i];
 for(i=1;i<=n;i++)
        cin>>cost[i];
 for(i=0;i<=n+1;i++)
 for(j=0;j<=10001;j++)
            dp[i][j]=-1;
    dp[0][0]=W;
 for(i=0;i<=n;i++)
 for(j=0;(j<=10000 && dp[i][j]!=-1);j++)
 for(ll g=0;(g<=a[i] && g*cost[i]<=dp[i][j]);g++)
                dp[i+1][j+g]=max(dp[i+1][j+g],min(dp[i][j]-(g*cost[i])+X,W+(B*(j+g))));
 //cout<<dp[n][6]<<" ";
 for(i=10000;i>=0;i--)
 if (dp[n+1][i]>=0)
 {
            cout<<i;
 return 0;
 }
 return 0;
}
