#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using vi = vector<int>;
using db = double;
using pii = pair<int,int>;
#define pb push_back
#define fir first
#define sec second
 
const int mxn = 500006;
const int MXL = 0x3f3f3f3f;
const ll mod = 1E9L+7;
 
struct Char {
 char x, y;
 bool operator==(Char b) const {
 return tie(x, y) == tie(b.y, b.x);
 }
};
 
using Val = ll;
 
struct seg { int l, r, d; };
Val f[mxn], g[mxn];
ll pfac(Char *s, int n) {
 vector<seg> a, t; f[0] = 1;
 for (int i = 1; i <= n; ++i) {
 int p = -MXL; t = {};
 auto add = [&](int l, int r, int d) {
			p = r;
 if (t.empty() || t.back().d != d)
				t.pb({l, r, d});
 else
				t.back().r = r;
 };
 auto add1 = [&](int x) { add(x, x, x - p); };
 for (auto j : a) if (j.l > 1 && s[j.l - 1] == s[i]) {
 --j.l; --j.r; add1(j.l);
 if (j.l < j.r) add(j.l + j.d, j.r, j.d);
 }
 if (i > 1 && s[i - 1] == s[i]) add1(i - 1);
 if (s[i] == s[i]) add1(i);
		a.swap(t);
		f[i] = 0;
 for (auto j : a) {
 auto m = f[j.r - 1];
 if (j.l < j.r) m = (m + g[j.l - j.d]) % mod;
 if (j.d < j.l) g[j.l - j.d] = m;
			f[i] = (f[i] + m) % mod;
 }
 }
 return f[n];
}
 
int n;
Char s[mxn];
char a[mxn];
 
int main() {
	scanf("%s", a + 1);
 
	n = strlen(a + 1);
 for (int i = 1; i <= n / 2; ++i)
		s[i] = {a[i], a[n + 1 - i]};
 
	ll ans = pfac(s, n / 2);
	cout << (ans % mod + mod) % mod << endl;
 return 0;
}
