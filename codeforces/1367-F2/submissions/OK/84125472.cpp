#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 int tc;
    cin >> tc;
 while(tc--)
 {
 int n;
        cin >> n;
 int ans = 0, arr[n];
 vector<vector<int>>v;
 map<int, vector<int>>mp;
 for(int i = 0;i < n;++i)
 {
            cin >> arr[i];
            mp[arr[i]].push_back(i);
 }
 for(auto &it : mp)
            v.push_back(it.S);
 for(int i = 0;i < v.size();++i)
 {
 int sz = v[i].size();
 int j = i + 1;
 while(j < v.size() && v[j][0] > v[j - 1].back())
                sz += v[j++].size();
 if(i)
 for(auto &it : v[i - 1])
                    sz += it < v[i][0];
 if(j < v.size())
 for(auto &it : v[j])
                    sz += it > v[j - 1].back();
            ans = max(ans, sz);
            i = j - 1;
 }
 for(int i = 0;i < v.size() - 1;++i)
 for(int j = 0;j < v[i].size();++j)
                ans = max(ans, j + 1 + (int)(v[i + 1].size() - (upper_bound(v[i + 1].begin(), v[i + 1].end(), v[i][j]) - v[i + 1].begin())));
        cout << n - ans << '\n';
 }
 return 0;
}
