#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e6 + 5;
const double eps = 1e-8;
int n, top, s[N], ans;
struct node {
 double k, b;
}a[N];
bool cmp (node x, node y) {
 return x.k < y.k;
}
int main() {
	scanf ("%d", &n);
 for (int i = 1, x, y; i <= n; i++) {
		scanf ("%lf%lf", &x, &y);
		a[i].k = -x, a[i].b = y - x * x;
 }
	sort (a + 1, a + n + 1, cmp);
 for (int i = 1; i <= n; i++) {
 while (top >= 2 && a[s[top]].b <= a[s[i]].b) {
			top--;
 }
		s[++top] = i;
 }
	printf ("%d\n", top);
 return 0;
}
/*
6
4 1
3 4
2 9
7 4
-1 4
0 5
 
ans = 3
*/
 
