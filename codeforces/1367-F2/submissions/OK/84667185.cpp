#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 10;
int f[N][3];
int n;
int a[N], b[N], cnt;
int num[N];
int l[N], r[N];
int pos[N];
int _;
 
int main()
{
 for (scanf("%d", &_); _; _--)
 {
		scanf("%d", &n);
 for (int i = 1; i <= n; i ++)
 {
			scanf("%d", &a[i]), b[i] = a[i];
			pos[i] = r[i] = num[i] = f[i][0] = f[i][1] = f[i][2] = 0;
			l[i] = 1e9;
 }
		sort(b + 1, b + n + 1);
		cnt = unique(b + 1, b + n + 1) - (b + 1);
 for (int i = 1; i <= n; i ++)
 {
			a[i] = lower_bound(b + 1, b + cnt + 1, a[i]) - b;
			l[a[i]] = min(l[a[i]], i);
			r[a[i]] = max(r[a[i]], i); 
			num[a[i]] ++;
 }
 int ans = 0;
 for (int i = 1; i <= n; i ++)
 {
			f[i][0] = f[pos[a[i]]][0] + 1;
			f[i][1] = max(f[pos[a[i]]][1] + 1, max(f[pos[a[i] - 1]][2] + 1, f[pos[a[i] - 1]][0] + 1));
 if(i == r[a[i]])
				f[i][2] = f[l[a[i]]][1] + num[a[i]] - 1; 
			pos[a[i]] = i;
			ans = max(ans, max(f[i][0], max(f[i][1], f[i][2])));
 }
		printf("%d\n", n - ans);
 } 
}
