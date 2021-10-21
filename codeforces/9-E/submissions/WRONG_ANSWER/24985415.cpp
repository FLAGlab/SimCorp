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
  puts("YES");
 vector<int> b;
 for (int i = 1; i <= n; ++i)
 if (a[i].size() == 1) b.push_back(i);
  printf("%d\n", b.size() / 2);
 for (int i : b) printf("%d ", i);
  puts("");
 return 0;
}
