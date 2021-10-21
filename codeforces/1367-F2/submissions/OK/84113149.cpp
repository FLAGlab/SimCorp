#include <bits/stdc++.h>
using namespace std;
#define x first 
#define y second
int main(){
 int n,t;
    cin>>t;
 while(t--){
        cin>>n;
 vector<int> nums(n);
 for(auto &c:nums)cin>>c;
 vector<pair<int,int>>v(n);
 for(int i = 0;i<n;i++){
            v[i] = {nums[i],-i};
 }
        sort(v.begin(),v.end());
 int l = 0;
 set<int> s1,s2; 
 int mx = -1;
 for(int r = 0;r<n;r++){
 if(v[r].x != v[r-s2.size()].x){
 for(auto c:s2)
                    s1.insert(c);
                s2.clear();
 }
 while(s1.size() && *s1.begin()<v[r].y)
                s1.erase(v[l++].y);
            s2.insert(v[r].y);
            mx = max(mx,(int)(s1.size()+s2.size()));
 // cout<<mx<<" ";
 }
 // cout<<endl;
        cout<<n-mx<<endl;
 }
 return 0;
}
