#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, top, m;
struct point {
	ll x, y;
} st[1000005], a[1000005], b[1000005];
double cal(point A, point B, point C) {
 return (B.y - A.y) * (C.x - B.x) <= (C.y - B.y) * (B.x - A.x);
}
bool cmp(point A, point B) {
 return (A.x == B.x) ? (A.y > B.y) : (A.x < B.x);
}
signed main() {
	scanf("%lld", &n);
 for (int i = 1; i <= n; i++) {
		scanf("%lld %lld", &b[i].x, &b[i].y);
		b[i].y -= b[i].x * b[i].x;
 }
	sort(b + 1, b + n + 1, cmp);
 for (int i = 1; i <= n; i++)
 if (b[i].x != b[i - 1].x) 
			a[++m] = b[i];
	st[++top] = a[1];
 for (int i = 2; i <= m; i++)
 {
 while (top > 1 && cal(st[top - 1], st[top], a[i]))
            top--;
        st[++top] = a[i];
 }
	printf("%lld\n", top - 1);
 return 0;
}
