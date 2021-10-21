#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define PB push_back
#define MP make_pair
 void solve()
 {
 	ll n;
 	cin>>n;
 	ll i,j;
 	ll ara[n+10],sec[n+10]={0};
 for(i=1;i<=n;i++)
 {
 		cin>>ara[i];
 		sec[i]=ara[i];
 }
 	sort(sec+1,sec+n+1);
 //for(i=1;i<=n;i++) cout<<sec[i]<<" ";
 //	cout<<endl;
 for(i=1;i<=n;i++)
 {
 		ll lo=1,hi=n;
 while(lo<=hi)
 {
 			ll mid=(lo+hi)/2;
 if(ara[i]==sec[mid])
 {
 				ara[i]=mid;
 break;
 }
 else if(ara[i]>sec[mid]) lo=mid+1;
 else hi=mid-1; 
 }
 }
 	ll dp[n+10]={0};
 for(i=1;i<=n;i++)
 {
 		dp[i]=1;
 }
 	ll res[n+10]={0};
 for(i = 1; i <= n; i++) {
  	dp[i] = res[ara[i] - 1] + 1;
  	res[ara[i]] = max(res[ara[i]], dp[i]);
 }
 	ll ans=0;
 for(i=1;i<=n;i++)
 {
 		ans=max(ans,res[ara[i]]);
 }
 	cout<<n-ans<<endl;
 
 }
 int main()
 {
 //freopen("in.txt","r",stdin);
 //freopen("out.txt","w",stdout);
 	IOS;
 	ll t;
 	cin>>t;
 while(t--) solve();
 return 0;
 }
