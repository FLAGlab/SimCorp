#include <iostream>
 
using namespace std;
 
int p[60] = {0}, d[60] = {0};
int n, m;
 
int find(int x) {
 if (p[x] != x)
		p[x] = find(p[x]);
 return p[x];
}
 
int main() {
	cin >> n >> m;
 for (int i = 1; i <= n; ++i)
		p[i] = i;
 int counter = 0;
 for (int i = 0; i < m; ++i) {
 int x, y;
		cin >> x >> y;
 ++d[x], ++d[y];
 if (d[x] > 2 || d[y] > 2) {
			cout << "NO" << endl;
 return 0;
 }
 if (p[x] == p[y])
 ++counter;
 else
			p[find(x)] = find(y);
 }
 if (counter > 0) {
 if (counter == 1 && m == n) {
			cout << "YES" << endl << 0 << endl;
 return 0;
 }
		cout << "NO" << endl;
 return 0;
 }
	cout << "YES" << endl << n - m << endl;
 for (int i = 1; i < n; ++i)
 for (int j = i + 1; j <= n; ++j)
 if (d[i] < 2 && d[j] < 2 && find(i) != find(j)) {
				cout << i << ' ' << j << endl;
 ++d[i], ++d[j];
				p[find(i)] = find(j);
 }
 for (int i = 1; i <= n; ++i)
 for (int j = n; j >= i; --j)
 if (d[i] < 2 && d[j] < 2) {
				cout << i << ' ' << j << endl;
 ++d[i], ++d[j];
				p[find(i)] = find(j);
 }
 return 0;
}
