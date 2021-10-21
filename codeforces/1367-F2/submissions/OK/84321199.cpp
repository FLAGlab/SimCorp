#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
 int t;
    cin>>t;
 while(t--) {
 int n,arr[200009];
        cin>>n;
 vector<pair<int,int> >v;
 for(int f=0;f<n;f++) {
            cin>>arr[f];
            v.push_back({arr[f],-f});
 }
        sort(v.begin(),v.end());
 int i=0,ans=0;
 set<int>s;
 set<int>s1;
 for(int f=0;f<n;f++) {
 if(v[f].first!=v[f-s1.size()].first) {
 for(int x:s1)
                    s.insert(x);
                s1.clear();
 }
 while(s.size()&&*s.begin()<v[f].second) {
                s.erase(v[i].second);
                i++;
 }
            s1.insert(v[f].second);
            ans=max(ans,(int)s.size()+(int)s1.size());
 }
        cout<<n-ans<<endl;
 }
}
