#include<bits/stdc++.h>
using namespace std;
#define MAXN 210005
#define ll long long
int dp[MAXN][4];
int a[MAXN];
int cnt[MAXN];
int Count[MAXN];
int n;
vector<int>v;
int id(int x)
{
 return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
int main()
{
 int t;
    cin>>t;
 while(t--)
 {
        scanf("%d",&n);
        v.clear();
 for(int i=1;i<=n;i++) {
            scanf("%d", a + i);
            v.push_back(a[i]);
            dp[i][1]=dp[i][2]=dp[i][3]=0;
            cnt[i]=Count[i]=0;
 }
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
 int ans=n;
 for(int i=1;i<=n;i++)
            cnt[id(a[i])]++;
 for(int j=1;j<=n;j++)
 {
 int i=id(a[j]);
            dp[i][3]++;
            dp[i][3]=max(dp[i][3],dp[i-1][1]+1);
 if (Count[i - 1] == cnt[i - 1])
            dp[i][3]=max(dp[i-1][2]+1,dp[i][3]);
            dp[i][3]=max(dp[i][2]+1,dp[i][3]);
 if(dp[i][2])dp[i][2]++;
 else if (Count[i] == 0 && Count[i - 1] == cnt[i - 1])
                dp[i][2] =max(dp[(i - 1)][2] + 1,dp[i-1][1]+1);
 else
                dp[i][2]=dp[(i - 1)][1] + 1;
            dp[i][1]++;
 Count[i]++;
            ans=min(ans,n-dp[i][3]);
 
 }
        cout<<ans<<endl;
 }
}
