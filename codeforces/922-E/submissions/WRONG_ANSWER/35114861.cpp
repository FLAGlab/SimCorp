#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll DP[1001][10001];
 
signed main()
{
    ios::sync_with_stdio(0);
    ll n,W,B,X;
    cin>>n>>W>>B>>X;
 vector<ll>C(n),cost(n),P(n+1);
 for(ll&x:C)cin>>x;
 for(ll&x:cost)cin>>x;
 for(int i=1;i<=n; i++)P[i]=P[i-1]+C[i-1];
    DP[0][0]=W;
 
 for(ll i=1; i<=n; i++)
 for(ll j=0; j<=P[i]; j++)
 for(ll k=0; k<=min(C[i-1],j); k++)
 if(DP[i-1][j-k]!=0 && DP[i-1][j-k] - cost[i-1]*k >=0)
            DP[i][j] = max(DP[i][j], min(W+B*j,DP[i-1][j-k] - k*cost[i-1] + X));
 
    ll ats = 0;
 for(int j=0; j<=P[n]; j++)
 if(DP[n][j]!=0)ats=j;
 
    cout<<ats<<"\n";
}
