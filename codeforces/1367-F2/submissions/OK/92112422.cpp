#include<bits/stdc++.h>
#define fi first
#define se second
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
 
using namespace std;
 
const int MAXN = 2e5 + 7;
 
int n, p[MAXN], dp1[MAXN], dp2[MAXN], dp3[MAXN], occ[MAXN], last[MAXN];
pair<int,int> a[MAXN];
 
int main()
{
//	freopen("test.INP","r",stdin);
	io;
 int test;
	cin >> test;
 while (test--)
 {
		cin >> n;
 for (int i = 1; i <= n; ++i) occ[i] = dp1[i] = dp2[i] = dp3[i] = last[i] = 0;
 
 for (int i = 1; i <= n; ++i) cin >> a[i].fi, a[i].se = i;
		sort(a + 1, a + 1 + n);
 
 int j = 1;
 for (int i = 1; i <= n; ++i)
 {
 if (i > 1 && a[i].fi != a[i - 1].fi) ++j;
			p[a[i].se] = j, ++occ[j];
 }
 
 int res = 0;
 for (int i = 1; i <= n; ++i)
 {
 --occ[p[i]];
 if (last[p[i] - 1])
 {
 if (!last[p[i]])
 {
					dp2[i] = max(dp2[i], dp1[last[p[i] - 1]] + 1);
 if (!occ[p[i] - 1])
 {
						dp2[i] = max(dp2[i], dp2[last[p[i] - 1]] + 1);
 }
 }
 if (!occ[p[i] - 1])
 {
					dp3[i] = max(dp3[i], dp2[last[p[i] - 1]] + 1);
 }
				dp3[i] = max(dp3[i], dp1[last[p[i] - 1]] + 1);
 }
 if (last[p[i]])
 {
				dp3[i] = max(dp3[i], dp3[last[p[i]]] + 1);
				dp2[i] = max(dp2[i], dp2[last[p[i]]] + 1);
				dp1[i] = dp1[last[p[i]]] + 1;
 }else dp1[i] = 1;
			last[p[i]] = i;
			dp2[i] = max(dp2[i], dp1[i]);
			dp3[i] = max(dp3[i], dp2[i]);
			res = max(res, dp3[i]);
 }
		cout << n - res << '\n';
 }
 return 0;
}
