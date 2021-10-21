#include <bits/stdc++.h>
 
using namespace std;
int arr[200005];
vector<pair<int,int> >vec;
set<int>s;
set<int>s1;
int main()
{
 int t;
    cin>>t;
 while(t--) 
 {
 int n;
        cin>>n;
        s.clear();
        s1.clear();
        vec.clear();
 for(int i=0 ; i<n ; i++)
 {
            cin>>arr[i];
            vec.push_back({arr[i],-i});
 }
        sort(vec.begin(),vec.end());
 int c=0,ans=0;
 
 for(int i=0; i<n ; i++) 
 {
 if(vec[i].first!=vec[i-s1.size()].first) 
 {
 set<int> ::iterator u;
 for(u=s1.begin() ; u!=s1.end() ; u++)
                    s.insert(*u);
                s1.clear();
 }
 while(s.size()&&*s.begin()<vec[i].second) {
                s.erase(vec[c].second);
                c++;
 }
            s1.insert(vec[i].second);
            ans=max(ans,(int)s.size()+(int)s1.size());
 }
        cout<<n-ans<<endl;
 }
}
