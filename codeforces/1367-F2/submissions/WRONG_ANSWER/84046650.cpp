#include <bits/stdc++.h>
using namespace std;
 
int main() {
 int t;
    cin>>t;
 while(t--){
 int n;
        cin>>n;
 int a[n];
 unordered_map<int,int> mp;
 for(int i=0;i<n;i++){
            cin>>a[i];
            mp[a[i]] = i;
 }
        sort(a, a+n);
 int dp[n];
        dp[n-1] = 1;
 for(int i=n-2;i>=0;i--){
 int x = mp[a[i]];
 int y = mp[a[i+1]];
 if(x < y){
                dp[i] = dp[i+1] + 1;
 }else{
                dp[i] = 1;
 }
 }
 int maxval = 0;
 for(int i=0;i<n;i++){
            maxval = max(maxval, dp[i]);
 }
        cout<<(n-maxval)<<"\n";
 }
 return 0;
}
