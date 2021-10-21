#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
 // int n; cin>>n;
 // int n, k; cin>>n>>k;
 
 int t; cin>>t;
 while(t--){
 int n; cin>>n;
 
 vector<int> a(n);
 for(int i = 0; i < n; i++)
            cin>>a[i];
 
 vector<int> b(a);
 
        sort(a.begin(), a.end());
 
 unordered_map<int, int> mp;
 for(int i = 0; i < n; i++)
            mp[a[i]] = i+1;
 
 for(int i = 0; i < n; i++)
            b[i] = mp[b[i]];
 
 vector<int> c(n+1, 0);
 int ans{};
 for(int i = 0; i < n; i++){
            c[b[i]] = c[b[i]-1]+1;
            ans = max(ans, c[b[i]]);
 }
 
        cout<<n-ans<<'\n';
 }
 
 return 0;
}
