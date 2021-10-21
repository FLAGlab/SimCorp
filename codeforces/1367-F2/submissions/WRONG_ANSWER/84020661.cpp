#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int mod=1e9+7;
 
int dx[]={-1, 0, 1, 0};
int dy[]={0, -1, 0, 1};
 
 
 
int32_t main()
{
 
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
 
#ifndef ONLINE_JUDGE
freopen("input.txt","rt",stdin);
freopen("output.txt","wt",stdout);
#endif 
 
 
int t;
cin>>t;
while(t--)
{
 
int n;
cin>>n;
vector<int>v(n);
map<int,int>mp;
for(int i=0;i<n;i++)
{
	cin>>v[i]; mp[v[i]]=i;
}
 
int ans=0;
sort(v.begin(),v.end());
 
vector<int>z(n);
for(int i=0;i<n;i++)
{
	z[i]=mp[v[i]];
}
 
 
 
vector<int>cnt(n,1);
for(int i=1;i<n;i++)
{
 if(z[i]>z[i-1])cnt[i]=cnt[i-1]+1;
}
 
 
cout<<n-(*max_element(cnt.begin(),cnt.end()))<<"\n";
 
 
 
 
}
 
 
}
