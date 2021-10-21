#include <iostream>
#include <vector>
#define NMAX 55
#define pii pair <int, int>
using namespace std;
 
int n, m;
vector <int> v[NMAX];
vector <pii> rsp;
 
int check()
{
 if (m >= n)
 return 0;
 for (int i = 1; i <= n; i++)
 if (v[i].size() > 2)
 return 0;
 return 1;
}
 
int main()
{
    cin >> n >> m;
 for (int i = 1; i <= m; i++)
 {
 int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
 }
 if (!check())
 {
        cout << "NO\n";
 return 0;
 }
    cout << "YES\n";
 for (int i = 1; i <= n; i++)
 {
 if (v[i].size() < 2)
 {
 for (int j = i + 1; j <= n; j++)
 {
 if (v[j].size() < 2 && v[i].size() < 2)
 {
                    v[i].push_back(j);
                    v[j].push_back(i);
                    rsp.push_back({i, j});
 }
 }
 }
 }
    cout << rsp.size() << "\n";
 vector <pii> :: iterator it;
 for (it = rsp.begin(); it != rsp.end(); it++)
 {
        pii nr = *it;
        cout << nr.first << " " << nr.second << "\n";
 }
 return 0;
}
