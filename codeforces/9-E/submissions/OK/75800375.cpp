#include <cstdio>
#include <vector>
#include <utility>
 
using namespace std;
 
const int N = 50 + 5;
int n, m, moved[N];
vector < pair < int , int > > vec;
struct {
 int fa[N];
 
 void init(int n) {
 for (int i = 1; i <= n; ++i)	fa[i] = i;
 }
 
 int find(int x) {
 if (x ^ fa[x]) fa[x] = find(fa[x]);
 return fa[x];
 }
 
 void merge(int x, int y) {
		x = find(x), y = find(y);
 if (x ^ y) fa[x] = y;
 }
} ufs;
 
signed main() {
	scanf("%d %d", &n, &m);
	ufs.init(n);
 for (int i = 0, x, y; i < m; ++i) {
		scanf("%d %d", &x, &y);
		moved[x]++, moved[y]++;
 if (moved[x] > 2 || moved[y] > 2) return puts("NO") & 0;
		ufs.merge(x, y);
 }
 for (int i = 1; i <= n; ++i) {
 for (int j = i + 1; j <= n; ++j) {
 if (ufs.find(i) ^ ufs.find(j) && moved[i] < 2 && moved[j] < 2) {
				vec.push_back(make_pair(i, j));
				ufs.merge(i, j);
				moved[i]++, moved[j]++;
 }
 }
 }
 if ((int)vec.size() + m + 1 == n) {
 int here = 0, there = 0;
 for (int i = 1; i <= n; ++i) {
 while (moved[i] < 2) {
 ++moved[i];
 if (here == 0) here = i;
 else there = i;
 }
 }
		vec.push_back(make_pair(here, there));
 }
 for (int i = 1; i <= n; ++i) if (ufs.find(1) ^ ufs.find(i)) return puts("NO") & 0;
	printf("YES\n%d\n", (int)vec.size());
 for (auto it : vec) printf("%d %d\n", it.first, it.second);
 return 0;
}
