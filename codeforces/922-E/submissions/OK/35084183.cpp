#include<bits/stdc++.h>
using namespace std;
signed main()
{
 long long N=10100,M=10000 , n,w,b,x,c[N],cnt[N] , dp[N],m[N] , ans;
	cin>>n>>w>>b>>x     ,   dp[0]=w    ,    m[0]=1;
 for(int i=1;i<=n;i++)   cin>>c[i] ;
 for(int i=1;i<=n;i++)   cin>>cnt[i];
 
 for(int k=1;k<=n;k++)
 for(int i=M;i>=0;i--)
 {
 for(int j=c[k];j>=0;j--)
 if(i-j>=0 &&  m[i-j]==1 &&  dp[i-j]>=cnt[k]*j)
 {
					m[i]=1;
					dp[i]=max(dp[i] , dp[i-j]-cnt[k]*j);
 }
 if(m[i]==1)
				dp[i]=min(dp[i]+x , i*b+w);
 }
 for(int i=0;i<=M;i++)
 if(m[i]==1)
	        ans=i;
 return cout<<ans , 0;
}
