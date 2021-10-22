#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned ui;
typedef unsigned long long ul;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef pair<bool, bool> pbb;
typedef vector<int> vi;
#define pb push_back
#define fi first
#define se second
#define mid ((l + r) >> 1)
#define ls (i << 1)
#define rs (i << 1 | 1)
#define enum(i, j, k) for(int i = j; i <= (k); i ++)
#define open(i, j, k) for(int i = j; i < (k); i ++)
#define dec(i, j, k) for(int i = j; i >= (k); i --)
#define ae(x) for(node *p = h[x]; p; p = p->nxt)
#define fill(x, k) memset(x, k, sizeof x)
#define copy(x, y) memcpy(x, y, sizeof x)
#define fio(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);
template <class T> bool chkmin(T &x, T y)
{ return y < x ? (x = y , true) : false; }
template <class T> bool chkmax(T &x, T y)
{ return y > x ? (x = y , true) : false; }
void __init()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(16);
    srand(time(0) ^ ui(ul(new char)));
}
/* default code ends here */
#define maxn 100100
int n;
pii p[maxn];
struct r_t
{
	ll zi, mu;
 void adjust()
 {
		ll g = __gcd(zi, mu);
		zi /= g;
		mu /= g;
 }
 r_t() : zi(0), mu(1) {}
 r_t(ll x) : zi(x), mu(1) {}
 r_t(ll x, ll y) : zi(x), mu(y) { adjust(); assert(zi <= INT_MAX && mu <= INT_MAX); }
 bool operator == (r_t x) { return zi == x.zi && mu == x.mu; }
 bool operator <= (r_t x) { return zi * x.mu <= mu * x.zi; }
 bool operator > (r_t x) { return zi * x.mu > mu * x.zi; }
 bool operator >= (r_t x) { return zi * x.mu >= mu * x.zi; }
 r_t operator + (r_t x) { return r_t(zi * x.mu + mu * x.zi, mu * x.mu); }
 r_t operator - (r_t x) { return r_t(zi * x.mu - mu * x.zi, mu * x.mu); }
 r_t operator * (r_t x) { return r_t(zi * x.zi, mu * x.mu); }
 r_t operator / (r_t x) { return r_t(zi * x.mu, mu * x.zi); }
 void deb()
 {
		cerr << zi << ' ' << mu << endl;
 }
};
typedef pair<r_t, r_t> prr;
prr a[maxn];
prr conv(pii x)
{
 return prr(r_t(x.fi), r_t(x.se));
}
struct u_t
{
 r_t b, c;
 u_t() {}
 u_t(prr x, prr y)
 {
		b = (x.fi * x.fi - y.fi * y.fi - x.se + y.se) / (y.fi - x.fi);
		c = x.se - x.fi * x.fi - b * x.fi;
 }
 r_t calc(r_t x)
 {
 return x * x + b * x + c;
 }
 bool in(prr x)
 {
 return x.se >= calc(x.fi);
 }
 void deb()
 {
		b.deb();
		c.deb();
		cerr << endl;
 }
};
signed main()
{
	__init();
	cin >> n;
 enum(i, 1, n)
		cin >> p[i].fi >> p[i].se;
	sort(p + 1, p + n + 1);
 int m = 0;
	p[n + 1].fi = INT_MAX;
 enum(i, 1, n)
 if(p[i].fi != p[i + 1].fi)
			swap(p[i], p[++ m]);
	n = m;
 if(n == 1)
 return cout << 0 << endl, 0;
 enum(i, 1, n)
		a[i] = conv(p[i]);
 int ans = 0;
 u_t cur = u_t(a[1], a[2]);
//	cur.deb();
//	cerr << cur.in(a[3]) << endl;
	pii pos = pii(1, 2);
 enum(i, 3, n)
 {
 if(cur.in(a[i]))
 {
			pos.se = i;
			cur = u_t(a[pos.fi], a[pos.se]);
 }
 else if(i == n || cur.calc(r_t(a[i].fi)) > r_t(1000000))
 {
			ans ++;
			pos = pii(pos.se, pos.se + 1);
			i = pos.se + 2;
 }
 }
 if(pos.se <= n)
		ans ++;
//	if(ans == 97)
//		cout << n << endl;
	cout << ans << endl;
 return 0;
}
