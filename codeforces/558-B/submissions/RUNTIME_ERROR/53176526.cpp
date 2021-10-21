#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
 int n; scanf("%d", &n);
 vector<int> a(n);
 vector<vector<int> > pos(n);
 for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		pos[a[i] - 1].push_back(i);
 }
 int mx = 0;
 for (int i = 0; i < 10*n; ++i) {
		mx = max(mx, (int) pos[i].size());
 }
 int mn = INT_MAX;
 int l, r;
 for (int i = 0; i < 10*n; ++i) {
 if ((int) pos[i].size() == mx) {
 if (pos[i][mx - 1] - pos[i][0] < mn) {
				mn = pos[i][mx - 1] - pos[i][0];
				l = pos[i][0]; r = pos[i][mx - 1];
 }
 }
 }
	printf("%d %d\n", l + 1, r + 1);
 return 0;
}
