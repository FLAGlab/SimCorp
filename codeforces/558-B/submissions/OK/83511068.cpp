#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int m[1000005],l[1000005];
int main()
{
 int n,x,maxi=0,mini=INT_MAX,ch=-1;
 
 cin>>n;
 for(int i=0;i<n;i++)
 {
   cin>>x;
 if(m[x]==0)
 {
     l[x]=i;
     m[x]=1;
 }
 else
   m[x]++;
 
 if(m[x]>maxi)
 {
     maxi=m[x];
     mini =i-l[x]+1;
     ch=l[x]+1;
 }
 else if(m[x]==maxi &&i-l[x]+1<mini)
 {
     mini =i-l[x] +1;
     ch=l[x]+1;
 }
 
 
 }
 cout<<ch<<" "<<ch+mini-1;
}
