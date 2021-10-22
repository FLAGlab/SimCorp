#include<bits/stdc++.h>
using namespace std;
signed main()
{
 int t,k,mx=-1,p1,p2,p;
  cin>>t;
 map<int,int> m;
 map<int,int> n;
 for(int i=1;i<=t;i++)
 {
    cin>>k;
 if(n[k]==0) n[k]=i;
    m[k]++;
 if(m[k]>mx)
 {
      mx=m[k];
      p=k;
      p2=i;
 }
 }
  p1=n[p];
  cout<<p1<<" "<<p2<<endl;
 return 0;
}
