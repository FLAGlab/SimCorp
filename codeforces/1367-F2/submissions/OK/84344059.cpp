#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll q,n,i,j,k,l,ans;
	cin>>q;
 for (l=0;l<q;l++)
 {
		ans=1;
		cin>>n;
 map<ll,ll> m1,m2,m3,m,count,pos;
		ll a[n];
 vector<ll> v;
 for (i=0;i<n;i++)
 {
			cin>>a[i];
			m[a[i]]++;
 }
 for (auto it : m)
 {
			v.push_back(it.first);
			ans=max(ans,it.second);
 }
		sort(v.begin(),v.end());
 for (i=0;i<v.size();i++)
			pos[v[i]]=i;
 for (i=0;i<n;i++)
 {
			count[a[i]]++;
 if (count[a[i]]==1)
 {
 if (pos[a[i]]==0)
 {
					m1[a[i]]=1;
					m2[a[i]]=1;
 }
 else
 {
 if (count[v[pos[a[i]]-1]]==m[v[pos[a[i]]-1]])
						m1[a[i]]=1+m2[v[pos[a[i]]-1]];
 else
						m1[a[i]]=1+count[v[pos[a[i]]-1]];
 if (count[v[pos[a[i]]-1]]==m[v[pos[a[i]]-1]])
						m2[a[i]]=1+m2[v[pos[a[i]]-1]];
 else
						m2[a[i]]=1+count[v[pos[a[i]]-1]];
 }
 }
 else
 {
 if (pos[a[i]]==0)
 {
					m1[a[i]]+=1;
					m2[a[i]]+=1;
 }
 else
 {
 if (count[v[pos[a[i]]-1]]==m[v[pos[a[i]]-1]])
						m1[a[i]]=1+max(m1[a[i]],m2[v[pos[a[i]]-1]]);
 else
						m1[a[i]]=1+max(m1[a[i]],count[v[pos[a[i]]-1]]);
					m2[a[i]]=1+m2[a[i]];
 }
 }
 }
 for (auto it : m1)
 {
			ans=max(ans,it.second);
 }
 for (auto it : m2)
 {
			ans=max(ans,it.second);
 }
		cout<<n-ans<<"\n";
 }
 return 0;
}
