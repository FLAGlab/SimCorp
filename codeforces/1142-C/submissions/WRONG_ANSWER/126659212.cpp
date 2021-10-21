#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e6 + 5;
const double eps = 1e-8;
int n;
long long ans;
double x[N], y[N];
int main() {
	scanf ("%d", &n);
 for (int i = 1; i <= n; i++) {
		scanf ("%lf%lf", &x[i], &y[i]);
 }
 for (int i = 1; i <= n; i++) {
 for (int j = i + 1; j <= n; j++) {
 double b = 1.0 * (y[i] - x[i] * x[i] - y[j] + x[j] * x[j]) / (x[i] - x[j]);
 double c = y[i] - x[i] * x[i] - b * x[i];
 bool flag = 1;
 for (int k = 1; k <= n; k++) {
 if (y[k] > x[k] * x[k] + b * x[k] + c + eps) {
					flag = 0;
 break;
 } 
 }
 if (flag) {
				ans++;
 }
 }
 }
	printf ("%lld\n", ans);
 return 0;
}
 
