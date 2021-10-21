#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int MAX_N = 2e5 + 2;
int a[MAX_N];
int idx[MAX_N];
void solve()
{
 int n;
 int res = 0;
 set<int> s;
 map<int,int> m;
 int ind = 1;
    cin>>n;
 vector<int> dp(n+1,0);
 vector<int> cnt(n+1,0);
 vector<int> all(n+1,0);
 vector<int> first(n+1,0);
 vector<int> last(n+1,0);
 vector<int> until_now(n+1,0);
 for(int i=1; i<=n; i++)
 {
        cin>>a[i];
        s.insert(a[i]);
 }
 for(auto i : s)m[i] = ind++;
 for(int i=1; i<=n; i++)a[i] = m[a[i]];
 for(int i=1; i<=n; i++)cnt[a[i]]++;
 for(int i=n; i>=1; i--)first[a[i]] = i;
 for(int i=1; i<=n; i++)
 {
        dp[i] = max(dp[last[a[i]]],until_now[a[i]-1])+1;
 if(until_now[a[i]-1] == cnt[a[i]-1]) dp[i] = max(dp[i],all[a[i]-1]+1);
        res = max(res,dp[i]);
        last[a[i]] = i;
        until_now[a[i]]++;
 if(until_now[a[i]] == cnt[a[i]])all[a[i]] = dp[first[a[i]]]+cnt[a[i]]-1;
 }
    cout<<n-res<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 int t;
    cin>>t;
 while(t--)solve();
}
