#include <cstdio>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;
#define FOR(i,j,k) for(register int i=j; i<=k; ++i)
#define ROF(i,j,k) for(register int i=j; i>=k; --i)
inline int read (void) {
 register int x = 0, f = 1, ch = getchar();
 while(!isdigit(ch)) { if(ch == '-') f = -f; ch = getchar(); }
 while(isdigit(ch)) { x = x * 10 + ch - '0'; ch = getchar(); }
 return x * f;
}
const int maxn = 55;
int fa[maxn], d[maxn];
int find (int x) {
 return x == fa[x] ? x : fa[x] = find(fa[x]);
}
vector <int> v[maxn];
vector <pair <int, int> > ans;
int main (void) {
 int n = read(), m = read();
 bool flag = 0;
 if(m > n) {
    printf("NO\n");
 return 0;
 }
 if(n == 1 && m == 1) {
    printf("YES\n");
    printf("0\n");
 return 0;
 }
  FOR(i,1,n) fa[i] = i;
  FOR(i,1,m) {
 int x = read(), y = read();
 if(++ d[x] > 2) {
      printf("NO\n");
 return 0;
 }
 if(++ d[y] > 2) {
      printf("NO\n");
 return 0;
 }
 if(find(x) != find(y)) fa[find(x)] = find(y);
 else if(m == n && !flag) {
      flag = 1;
 } else {
      printf("NO\n");
 return 0;
 }
 }
  FOR(i,1,n) if(d[i] < 2) FOR(j,i+1,n) if(d[i] < 2 && d[j] < 2 && find(i) != find(j)) {
    ans.push_back (make_pair (i, j));
    fa[find(i)] = find(j);
 ++ d[i]; ++ d[j];
 }
  FOR(i,1,n) ROF(j,n,i) if(d[i] < 2 && d[j] < 2) { ans.push_back (make_pair (i, j)); goto finished; }
  finished:
  sort(ans.begin(), ans.end());
  printf("YES\n");
  printf("%d\n", ans.size());
 for(vector <pair <int, int> > :: iterator it = ans.begin(); it != ans.end(); ++ it) 
    printf("%d %d\n", it -> first, it -> second);
 return 0;
}
