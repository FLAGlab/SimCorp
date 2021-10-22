#include<bits/stdc++.h>
using namespace std;
signed main()
{
 int n,low,high,ans,maxi=0;
 map<int,int>mp;
    cin>>n;
 int a[n];
 for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
 if(mp[a[i]]>maxi){
            maxi=mp[a[i]];
            ans=a[i];
            high=i;
 }
 }
 for(int i=0;i<n;i++){
 if(a[i]==ans){
            low=i;
 break;
 }
 }
    cout<<low+1<<" "<<high+1<<endl;
}
