#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e6 + 5;
const double eps = 1e-8;
int n, head, tail, q[N];
long long ans;
double x[N], y[N];
inline double slope (int i, int j) {
 return (y[i] - y[j]) / (x[i] - x[j]);
}
int main() {
	scanf ("%d", &n);
 for (int i = 1; i <= n; i++) {
		scanf ("%lf%lf", &x[i], &y[i]);
 }
 for (int i = 1; i <= n; i++) {
 while (head < tail - 1 && slope (q[tail], i) > slope (q[tail - 1], i)) {
			tail--;
 }
		q[++tail] = i;
 }
	printf ("%d\n", tail - head - 1);
 return 0;
}
 
