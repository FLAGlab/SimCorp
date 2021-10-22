#include<bits/stdc++.h>
#define ll long long
 
using namespace std;
signed main()
{
   ll n;cin>>n; ll st=0,end=0;
   ll arr[n],mp[100005]={0},tmp[100005],freq=0;
 for(int i=0;i<n;i++)
 {
   	 cin>>arr[i];
 if(mp[arr[i]]==0)
 {
   	    mp[arr[i]]++;
     	tmp[arr[i]]=i; 
     	freq=max(freq,mp[arr[i]]);
 }
 else if( mp[arr[i]]>=1)
 {
  	 	mp[arr[i]]++;
 if(mp[arr[i]]>freq){
  	 		st=tmp[arr[i]];
  	 		end=i;
  	 		freq=mp[arr[i]];
 }
 }
 }
   cout<<st+1<<" "<<end+1<<endl;
}
