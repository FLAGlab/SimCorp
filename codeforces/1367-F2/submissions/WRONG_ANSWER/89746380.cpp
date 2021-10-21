#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll t;
	cin>>t;
 while(t--)
 {
		ll n,i,j;
		cin>>n;
		ll ar[n+1],br[n+1];
 unordered_map<ll,ll> mp;
 for(i=1;i<=n;i++)
 {
			cin>>ar[i];
			br[i]=ar[i];
 }
		sort(br+1,br+n+1);
		ll max1=0;
 for(i=1;i<=n;i++)
 {
			ll z=lower_bound(br+1,br+n+1,ar[i])-br;
			z--;
 if(z!=0)
				mp[ar[i]]=max(mp[ar[i]]+1,mp[br[z]]+1);
 else
				mp[ar[i]]+=1;
 //cout<<i<<" "<<mp[ar[i]]<<"\n";
			max1=max(max1,mp[ar[i]]);
 }
		cout<<n-max1<<"\n";
 }
}
