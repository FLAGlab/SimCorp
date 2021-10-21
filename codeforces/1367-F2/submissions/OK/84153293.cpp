#include<bits/stdc++.h>
using namespace std;
int t,n,a[202020],b[202020],ans,dp[202020][3];
map<int,int>mp,nm;
int main()
{
	cin>>t;
 while(t--)
 {
		ans=0;
		mp.clear();
		nm.clear();
		cin>>n;
 for(int i=1;i<=n;i++)
 {
			cin>>a[i];
			b[i]=a[i];
			dp[i][0]=0;
			dp[i][1]=0;
			dp[i][2]=0;
			nm[i]=0;
 }
		sort(a+1,a+n+1);
		a[0]=-1;
 int p=0;
 for(int i=1;i<=n;i++)
 {
 if(a[i]!=a[i-1])
 {
				p++;
				mp[a[i]]=p;
 }
 }
 for(int i=1;i<=n;i++)
 {
			nm[mp[b[i]]]++;
 }
 for(int i=1;i<=n;i++)
 {
 int x=mp[b[i]];
 if(!dp[x][0])
 {
 if(dp[x-1][0]==nm[x-1])
 {
					dp[x][1]=dp[x-1][1];
					dp[x][2]=dp[x-1][1];
 }
 else
 {
					dp[x][1]=dp[x-1][0];
 }
 }
			dp[x][2]=max(dp[x-1][0],dp[x][2]);
 if(dp[x-1][0]==nm[x-1])
 {
				dp[x][2]=max(dp[x][2],dp[x-1][1]);
 }
 for(int j=0;j<3;j++)
 {
				dp[x][j]++;
 }
 }
 for(int i=1;i<=n;i++)
 {
 for(int j=0;j<3;j++)
 {
				ans=max(ans,dp[mp[b[i]]][j]);
 }
 }
		cout<<n-ans<<endl;
 }
 return 0;
}
