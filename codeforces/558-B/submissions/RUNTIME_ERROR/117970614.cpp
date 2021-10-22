#include<bits/stdc++.h>
using namespace std;
signed main()
{
 long long int n,i,m=0,freq[100001]={0},d=1e7,p,k;
	cin>>n;
 long long int a[n+1];
 vector<pair<long long int,long long int> >v;
	v.push_back(make_pair(0,0));
 for (i=1;i<=100000;i++)
		v.push_back(make_pair(0,0));
 for (i=1;i<=n;i++)
 {
		cin>>a[i];
		freq[a[i]]++;
 }
 for (i=1;i<=n;i++)
 {
 if (v[a[i]].first==0)
 {
			v[a[i]].first=i;
 }
 }
 for (i=n;i>=1;i--)
 {
 if (v[a[i]].second==0)
 {
			v[a[i]].second=i;
 }
 }
 for (i=1;i<=100000;i++)
 {
		m=max(m,freq[i]);
 }
 for (i=1;i<=100000;i++)
 {
 if (m==freq[i])
 {
 if (d>v[i].second-v[i].first+1)
 {
				d=v[i].second-v[i].first+1;
				p=v[i].first;
				k=v[i].second;
 }
 }
 }
	cout<<p<<" "<<k<<'\n';
}
