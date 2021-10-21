#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
 {
    ll i,j,k,l,m,n,o,e,t,a[300001],dp[300001],last[300001],start[300001],freq[300001],cnt[300001];
    cin>>t;
 while(t--)
 {
       cin>>n;
       memset(dp,0LL,sizeof(ll)*(n+1));
       memset(last,0LL,sizeof(ll)*(n+1));
       memset(freq,0LL,sizeof(ll)*(n+1));
       memset(start,0LL,sizeof(ll)*(n+1));
       memset(cnt,0LL,sizeof(ll)*(n+1));
 map<ll,ll> mp;
 set<ll> se;
 for(i=1;i<=n;i++)
 {
           cin>>a[i];
           se.insert(a[i]);
 }
       k=1;
 for(auto it:se)
 {
         mp[it]=k;
 // cout<<it<<" "<<mp[it]<<endl;
         k++;
 }
       last[0]=0;
 for(i=1;i<=n;i++)
 {
           a[i]=mp[a[i]];
           last[a[i]]=0;
           freq[a[i]]++;
           start[a[i]]=0;
 }
 //ok compression done.
       dp[0]=0;
       ll ans=0;
 for(i=1;i<=n;i++)
 {
 if(start[a[i]]==0)
 {
               start[a[i]]=i;
 }
           dp[i]=max(dp[last[a[i]]]+1,cnt[a[i]-1]+1);
 if(cnt[a[i]-1]==freq[a[i]-1])
 {
               dp[i]=max(dp[i],freq[a[i]-1]+dp[start[a[i]-1]]);
 }
           ans=max(ans,dp[i]);
           last[a[i]]=i;
           cnt[a[i]]++;
 }
       cout<<n-ans<<endl;
 }
 return 0;
}
