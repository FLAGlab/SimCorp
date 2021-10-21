#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define ll long long
using namespace std;
int main()
{ 
   fastio; 
 int t; cin>>t;
 while(t--){
 int n; cin>>n; pair<int,int> a[n];
 unordered_map<int,vector<int>> posns;
 for(int i=0;i<n;i++){
         cin>>a[i].first; a[i].second=i;
         posns[a[i].first].push_back(i);
 }
      sort(a,a+n);
 int ans=INT_MIN;;
 int cnt=1; int prev=a[0].second;
 for(int i=1;i<n;i++){
 if(a[i].second>prev){cnt++;}
 else{
 int index=a[i-1].second; int el=a[i].first;
 int extra=posns[el].size()-(upper_bound(posns[el].begin(),posns[el].end(),index)-posns[el].begin() ); 
            ans=max(ans,extra+cnt); index=a[i].second; el=a[i-1].first;
            cnt=upper_bound(posns[el].begin(),posns[el].end(),index)-posns[el].begin();
            cnt++;
 }
         prev=a[i].second;
 
 }
      ans=max(ans,cnt);
      cout<<n-ans<<"\n";
 }
 
 
 
} 
