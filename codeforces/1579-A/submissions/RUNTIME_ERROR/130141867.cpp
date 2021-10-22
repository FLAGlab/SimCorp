#include<bits/stdc++.h>
using namespace std;
 
void solve(vector<int> &X, vector<int> &B)
{
 int i, j, m = X.size(), n = B.size();
 for (i = 0; i < m; i++)
 {
 for (j = 0; j < n; j++)
 {
 if (X[j] >= 0 && B[i] >= 0 && abs(X[j] - B[i]) > 1)
 {
                X[j] = -1;
                B[i] = -1;
 break;
 }
 }
 }
}
 
bool check(vector<int> &X)
{
 int i, n = X.size();
 for (i = 0; i < n; i++)
 {
 if (X[i] != -1)
 return false;
 }
 return true;
}
 
signed main()
{
    string s;
 int t, i, n;
    cin >> t;
 while (t--)
 {
 vector<int> A, B, C;
        cin >> s;
        n = s.size();
 for (i = 0; i < n; i++)
 {
 if (s[i] == 'A')
 {
                A.push_back(i);
 }
 else if (s[i] == 'B')
 {
                B.push_back(i);
 }
 else
 {
                C.push_back(i);
 }
 }
        solve(A, B);
        solve(C, B);
 if (check(A) && check(B) && check(C))
            cout << "YES\n";
 else
            cout << "NO\n";
 }
 return 0;
}
