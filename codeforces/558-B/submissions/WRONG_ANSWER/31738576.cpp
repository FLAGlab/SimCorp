#include<bits/stdc++.h>
using namespace std;
signed main()
{
 int t,k,mx=-1,p1,p2,p;
  cin>>t;
 map<int,int> m;
 map<int,bool> n;
 set<pair<int,int> > s;
 for(int i=1;i<=t;i++)
 {
    cin>>k;
    m[k]++;
 if(n[k]==0) {n[k]=1;s.insert({k,i});}
 if(m[k]>mx)
 {
      mx=m[k];
      p=k;
      p1=i;
 }
 }
 for(auto i:s) if(i.first==p) {cout<<i.second;break;}
  cout<<" "<<p1<<endl;
 return 0;
}
