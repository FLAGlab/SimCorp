#include <bits/stdc++.h>
using namespace std;
 
const int N = 100005;
 
int n;
pair<long long, long long> a[N];
#define x first
#define y second
 
long long cross(int O, int A, int B) {
 return 1LL * (a[A].x - a[O].x) * (a[B].y - a[O].y) - 1LL * (a[B].x - a[O].x) * (a[A].y - a[O].y);
}
 
bool bad(int O, int A, int B) {
 return cross(O, A, B) >= 0; // ccw
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
 
	cin >> n;
 for (int i = 0; i < n; ++i) {
 long long xx, yy; cin >> xx >> yy;
		a[i].x = xx;
		a[i].y = yy - xx * xx;
 }
 
	sort(a, a + n);
 
 vector<int> p;
 for (int i = 0; i < n; ++i) {
 while (p.size() > 0 && a[p.back()].x == a[i].x) p.pop_back();
 while (p.size() > 1 && bad(p[(int)p.size()-2], p[(int)p.size()-1], i)) p.pop_back();
		p.push_back(i);
 }
 
	cout << p.size() - 1 << endl;
}
