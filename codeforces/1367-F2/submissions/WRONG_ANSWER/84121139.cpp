#include <iostream>
#include <algorithm>
using namespace std;
const int N = 3005;
int arr[N] = {};
int tmp[N] = {};
int dp[N] = {};
int n;
int bs(int x) {
 int l = 1, r = n, mid;
 while(l <= r) {
		mid = (l + r) >> 1;
 if (tmp[mid] <= x)
			l = mid + 1;
 else r = mid - 1;
 }
 return r;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 int T;
	cin >> T;
 while (T--) {
		cin >> n;
 for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			tmp[i] = arr[i];
			dp[i] = 0;
 }
		sort(tmp + 1, tmp + 1 + n);
 for (int i = 1; i <= n; i++)
			arr[i] = bs(arr[i]);
 int x, ma = 0;
 for (int i = 1; i <= n; i++) {
			x = arr[i];
			dp[x] = max(dp[x - 1] + 1, dp[x]);
			ma = max(ma, dp[x]);
 }
		cout << n - ma << '\n';
 }
 return 0;
}
