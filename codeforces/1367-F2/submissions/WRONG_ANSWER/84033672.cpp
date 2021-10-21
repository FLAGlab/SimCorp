#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define int ll
#define pb push_back
#define setbits(x)          __builtin_popcountll(x)
#define endl "\n"
typedef long long ll;
int32_t main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--)
{
 int n;
    cin>>n;
 int arr[n];
 for(int i=0;i<n;i++)
        cin>>arr[i];
 vector<int> a;
 for(int i=0;i<n;i++)
 {
       a.pb(arr[i]);
 }
 
 
   sort(a.begin(),a.end());
 map<int,vector<int> > mp;
 for(int i=0;i<n;i++)
 {
      mp[arr[i]].pb(i);
 }
 int ans=0;
 int cnt=1;
 int prev=mp[a[0]][0];
 for(int i=1;i<a.size();i++)
 {
 ///mp[arr[i]]==0.
 
 int pos=upper_bound(mp[a[i]].begin(),mp[a[i]].end(),prev)-mp[a[i]].begin();
 if(pos==mp[a[i]].size())
 {
            prev=mp[a[i]][0];
            ans=max(ans,cnt);
            cnt=1;
 continue;
 }
        prev=mp[a[i]][pos];
 
        cnt+=1;
        ans=max(ans,cnt);
 
 }
   ans=max(ans,cnt);
 
   cout<<n-ans<<endl;
 
 
 
 
 
 
 
 
 
 
 
 
 
 
}
 return 0;
}
