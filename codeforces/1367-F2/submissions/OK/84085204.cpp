#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
 
const int MAX = 1e6 + 6;
int main()
{
    fastRead;
 int t;
    cin>>t;
 while(t--) {
 
 int n;
        cin>>n;
 vector<int>vec(n+1);
 map<int, int>mp;
 for(int i =1 ; i <= n ;i++ ) {
            cin>>vec[i];
            mp[vec[i]] = 1;
 }
 int cnt = 0;
 for(auto &x : mp) x.vv = ++cnt;
 
 for(int i = 1 ; i <= n ; i++ ) vec[i] = mp[vec[i]];
 
 vector<int>tot(n+1), fre(n+1), last(n+1), st(n+1), dp(n+1);
 
 for(int i = 1 ;i <= n ; i++ ) tot[vec[i]]++;
 
 int mx = 0;
 
 for(int i = 1 ; i <=n ; i++) {
 
 if(st[vec[i]] == 0) st[vec[i]] = i;
 
            dp[i] = max(dp[last[ vec[i] ] ], fre[ vec[i]-1 ]) + 1;
 if( fre[vec[i]-1] == tot[vec[i]-1] ) {
                dp[i] = max(dp[i], dp[ st[ vec[i] -1 ] ] + fre[vec[i]-1] );
 }
            last[vec[i]] = i;
            fre[vec[i]]++;
 
            mx = max(mx, dp[i]);
 }
 
        cout<<n-mx<<'\n';
 }
 return 0;
}
