#include <bits/stdc++.h>
using namespace std;
const int N = 3004;
int n, test;
int a[N];
pair < int, int> b[N];
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> test;
 while(test--)
 {
        cin >> n;
 for (int i = 1; i <= n; i++)
 {
            cin >> a[i];
            b[i].first = a[i];
            b[i].second = i;
 }
 
        sort(b + 1, b + n + 1);
 
 int res = 1;
 int dem = 1;
 
 for (int i = 2; i <= n; i++)
 {
 if (b[i].second < b[i - 1].second)
                dem = 1;
 else
 {
                dem++;
                res = max(res, dem);
 }
 }
 
        cout << n - res << '\n';
 }
}
