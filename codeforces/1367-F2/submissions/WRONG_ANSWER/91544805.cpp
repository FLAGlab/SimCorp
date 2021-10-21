#include<bits/stdc++.h>
using namespace std;
 
typedef long long int in;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    in t;
    cin>>t;
 
 while(t--)
 {
        in n,i;
        cin>>n;
 
        in a[n+1],dp[n+5]={0},ans=0,e=0;
 
 set<in> s;
 
 map<in,in> mp;
 
 for(i=1;i<=n;++i)
 {
            cin>>a[i];
            s.insert(a[i]);
 }
 
 for(auto it:s)
 {
            mp[it]=++e;
 }
 
 for(i=1;i<=n;++i)
 {
            a[i]=mp[a[i]];
 }
 
 for(i=1;i<=n;++i)
 {
            dp[a[i]]=max(dp[a[i]],dp[a[i]-1])+1;
            ans=max(ans,dp[a[i]]);
 
 // cout<<dp[a[i]]<<"   ";
 }
 
 // cout<<"\n";
 
 // for(i=1;i<=n;++i)
 // cout<<a[i]<<"   ";
 
 // cout<<"\n";
 
        cout<<n-ans<<"\n";
 
 }
 
 return 0;
}
