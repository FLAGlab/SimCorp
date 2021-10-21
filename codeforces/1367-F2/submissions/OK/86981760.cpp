#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
 int t, n, i, j, k;
    cin >> t;
 while (t--)
 {
        cin >> n;
 vector<pair<int, int>> v;
 set<int> s1, s2;
 for (i = 0; i < n; i++)
 {
            cin >> j;
            v.push_back({j, -i});
 }
        sort(v.begin(), v.end());
 int ans = 0;
 for (i = 0, j = 0; i < n; i++)
 {
 if (v[i].first != v[i - s2.size()].first)
 {
 for (int x : s2)
                    s1.insert(x);
                s2.clear();
 }
 while (s1.size() && *s1.begin() < v[i].second)
                s1.erase(v[j++].second);
            s2.insert(v[i].second);
            ans = max(ans, int(s1.size() + s2.size()));
 }
        cout << n - ans << endl;
 }
}
