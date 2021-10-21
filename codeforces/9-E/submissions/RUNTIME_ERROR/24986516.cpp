#include <bits/stdc++.h>
using namespace std;
 
const int N = 55;
bool b[N];
vector<int> a[N];
int n, m;
 
int main() {
  scanf("%d%d", &n, &m);
 for (int i = 0; i < m; ++i) {
 int x, y;
    scanf("%d%d", &x, &y);
    a[x].push_back(y);
    a[y].push_back(x);
 if (a[x].size() > 2 || a[y].size() > 2) {
      puts("NO");
 return 0;
 }
 }
 
  deque<pair<int, int>> d;
 for (int i = 1; i <= n; ++i)
 if (!b[i]) {
      b[i] = true;
 if (a[i].empty()) {
        d.push_back({i, i});
 } else if (a[i].size() == 1) {
 int j = a[i][0];
        b[j] = true;
 while (a[j].size() == 2) {
          j = a[j][b[a[j][0]]];
          b[j] = true;
 }
        d.push_back({i, j});
 } else {
 int j = a[i][0], c = 1;
 while (!b[j]) {
          b[j] = true;
          j = a[j][b[a[j][0]]];
 ++c;
 }
 if (c < n) {
          puts("NO");
 return 0;
 }
 }
 }
  puts("YES");
  printf("%d\n", (int)d.size());
 while (d.size() > 1) {
    printf("%d %d\n", d[0].first, d[1].first);
 int x = d[0].second, y = d[1].second;
    d.push_back({min(x, y), max(x, y)});
    d.pop_front();
    d.pop_front();
    sort(d.begin(), d.end());
 }
 if (d.size()) printf("%d %d\n", d[0].first, d[0].second);
 return 0;
}
