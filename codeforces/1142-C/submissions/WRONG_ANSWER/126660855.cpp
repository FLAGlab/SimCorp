#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const double eps = 1e-8;
int n, head, tail, q[N];
long long ans;
struct node {
 double x, y;
}a[N];
bool cmp (node x, node y) {
 return x.x < y.x;
}
inline double slope (int i, int j) {
 return (a[i].y - a[j].y) / (a[i].x - a[j].x);
}
signed main() {
	scanf ("%d", &n);
 for (int i = 1; i <= n; i++) {
		scanf ("%lf%lf", &a[i].x, &a[i].y);
 }
	sort (a + 1, a + n + 1, cmp);
 for (int i = 1; i <= n; i++) {
 while (head < tail - 1 && slope (q[tail], i) > slope (q[tail - 1], i)) {
			tail--;
 }
		q[++tail] = i;
 }
	printf ("%d\n", tail - head - 1);
 return 0;
}
 
