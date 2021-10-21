#include<bits/stdc++.h>
using namespace std;
 
int main()
{
 int t;
    cin >> t;
 while(t--)
 {
 int n;
        cin >> n;
 vector<int>a(n + 5);
 vector<pair<int, int> >pr;
 for(int i = 1; i <= n; i++) {
                cin >> a[i];
                pr.push_back({a[i], i});
 }
        sort(pr.begin(), pr.end());
 int id = 1;
        a[pr[0].second] = id;
 for(int i = 1; i < pr.size(); i++)
 {
 if(pr[i].first != pr[i - 1].first) id++;
            a[pr[i].second] = id;
 }
 vector<int>dp(n + 5, 0);
 for(int i = 1; i <= n; i++)
 {
            dp[a[i]] = max(dp[a[i] - 1], dp[a[i]]) + 1;
 }
 int ans = 0;
 for(int i = 1; i <= n; i++) ans = max(ans, dp[a[i]]);
        cout << n - ans << endl;
 }
}
