#include <bits/stdc++.h>
using namespace std;
 
const int N = 55;
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
 vector<int> b;
 for (int i = 1; i <= n; ++i)
 for (int j = 0; j < 2 - a[i].size(); ++j) b.push_back(i);
 if (b.size() == 2 && b[0] == b[1]) {
    puts("NO");
 return 0;
 }
 if (b.size() > 2) {
 if (b[0] == b[1]) swap(b[1], b[2]);
 for (int i = 1; i < b.size() - 1; ++i)
 if (b[i] == b[i + 1]) swap(b[i - 1], b[i]);
 }
  puts("YES");
  printf("%d\n", (int)b.size() / 2);
 for (int i = 0; i < b.size(); ++i) {
    printf("%d%s", b[i], i % 2 ? "\n" : " ");
 }
 return 0;
}
