#include <bits/stdc++.h>
 
using namespace std;
 
long long i,j,k,z1,c,n,t,a[1000005],q,p1,l,r,x,y,pi[1000005],nu,ex,re,ii,ans,ma=-1000;
map<long long ,long long> mp , mp1 ;
 
int main()
{
  cin >> n;
for(i=1;i<=n;i++)
{
    cin >> a[i];
    mp[a[i]]++;
 if(mp1[a[i]]==0) mp1[a[i]]=i;
 if(mp[a[i]]>ma)
 {
        ma=mp[a[i]];
        t=i;
 }
}
cout<<mp1[a[t]]<<" "<<t;
 
 
 return 0;
}
