#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n,t;
 cin>>t;
 while(t--)
 {
  cin>>n;
 map<int,int>pos;
 vector<int>a(n),b(n);
 for(int i=0;i<n;i++)
 {
   cin>>a[i];
   b[i]=a[i];
   pos[a[i]]=i;
 }
  sort(b.begin(),b.end());
 int ans=0,cnt=0,f=0;
 for(int i=0;i<n;i++)
 {
 if(a[i]!=b[i]) f=1;
 if(i-1>=0 && pos[b[i]]>pos[b[i-1]]){ 
                cnt++;
 }
 else cnt=1;
   ans=max(ans,cnt);
 }
  f?cout<<n-ans<<endl:cout<<0<<endl;
 
 }
}
