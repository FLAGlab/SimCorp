#include<bits/stdc++.h>
using namespace std;
map<long long,long long> mp;
long long a[100005];
long long vis[100005];
int main()
{
 int n;
 while(cin>>n)
 {
		memset(vis,0,sizeof(vis));
		mp.clear();
 for(int i=1;i<=n;i++)
 {
			cin>>a[i];
			mp[a[i]]++; 
 }
 long long max1=-1;
 for(auto it:mp)
 { 
			max1=max(max1,it.second);
 }
 long long l=-1;
 long long r=-1;
 long long len=10000005;
 for(int i=1;i<=n;i++)
 {
 if(mp[a[i]]==max1&&vis[a[i]]==0)
 {
 for(int j=n;j>=i;j--)
 {
 if(a[j]==a[i]&&vis[a[j]]==0)
 {
						vis[a[j]]=1;
 if(j-i<len)
 {
							len=j-i;
							l=i;
							r=j;
 }
 break;
 }
 }
 }
 }
		cout<<l<<" "<<r<<endl;
 }
 return 0;
}
 
