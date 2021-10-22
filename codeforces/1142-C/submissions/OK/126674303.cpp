#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, top, st[N];
struct node {
 long long x, y;
}a[N], b[N];
bool cmp (node x, node y) {
 if (x.x != y.x) {
 return x.x < y.x;
 }
 return x.y > y.y;
}
inline bool check (int i, int j, int k) {
 return (a[k].y - a[i].y) * (a[k].x - a[j].x) <= (a[k].y - a[j].y) * (a[k].x - a[i].x);
}
signed main() {
	scanf ("%d", &n);
 for (int i = 1; i <= n; i++) {
		scanf ("%lld%lld", &b[i].x, &b[i].y);
 }
	sort (b + 1, b + n + 1, cmp);
 int cnt = 0;
	b[0].x = 1919810;
 for (int i = 1; i <= n; i++) {
 if (b[i].x != b[i - 1].x) {
			a[++cnt] = (node){b[i].x, b[i].y - b[i].x * b[i].x};
 }
 }
 for (int i = 1; i <= cnt; i++) {
 while (top >= 2 && check (st[top - 1], st[top], i)) {
			top--;
 }
		st[++top] = i;
 }
	printf ("%d\n", top - 1);
 return 0;
}
