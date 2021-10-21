#include <cstdio>
#include <cmath>
#include <map>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <unistd.h>
#include <vector>
#include <set>
#include <queue>
#include <string>
 
using namespace std;
 
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define X first
#define Y second
 
#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<
#define double long double
 
const double EPS = 1e-6;
typedef long long ll;
typedef pair<ll, ll> P;
 
const int MAX = 1<<17;
const int MAXABS = 2e6 + 5;
 
struct frac {
  ll a, b;
  frac (ll x, ll y) {
 if (y < 0) { x = -x; y = -y; }
    ll tmp = abs(__gcd(x, y));
    x /= tmp; y /= tmp;
    a = x; b = y;
 }
};
 
double getd(frac x) {
 return (double) x.a / x.b;
}
 
struct parab {
  frac b, c;
};
 
set <pair<frac, frac> > S;
 
bool operator < (const frac &a, const frac &b) {
 if (a.a != b.a) return a.a < b.a;
 return a.b < b.b;
}
 
P p[MAX];
int n;
//map <int, int> Mx;
 
ll sq(ll x) { return x*x; }
 
 
ll ccw(P a, P b, P c) {
 return (ll) a.X * (b.Y - c.Y) + (ll) b.X * (c.Y - a.Y) + (ll) c.X * (a.Y - b.Y);
}
 
vector <P> LH, RH;
 
void make_hulls() {
  P toc[MAX];
  REP(i, n) toc[i] = P(p[i].X, p[i].Y - sq(p[i].X));
 
  sort(toc, toc + n);
 
  REP(i, n) {
 while (LH.size() >= 2 && ccw(LH[LH.size()-2], LH.back(), toc[i]) >= 0) LH.pop_back();
    LH.push_back(toc[i]);
 }
 
  REP(i, n) {
 while (RH.size() >= 2 && ccw(RH[RH.size()-2], RH.back(), toc[i]) <= 0) RH.pop_back();
    RH.push_back(toc[i]);
 }
}
 
double eval(P toc, double b, double c) {
 return toc.Y - c - b * toc.X;
}
 
double get_max(vector <P> &H, double b, double c) {
 int lo = 0, hi = (int) H.size()-1;
 for (; lo<hi; ) {
 int mid = (lo + hi) / 2;
 if (eval(H[mid], b, c) > eval(H[mid+1], b, c))
      hi = mid;
 else
      lo = mid + 1;
 }
 
 return eval(H[lo], b, c);
}
 
int main() {
  scanf("%d", &n);
  REP(i, n) {
    scanf("%lld%lld", &p[i].X, &p[i].Y);
 // if (Mx.find(p[i].X) == Mx.end())
 //   Mx[p[i].X] = p[i].Y;
 // else
 //   Mx[p[i].X] = max(Mx[p[i].X], p[i].Y);
 }
 
  sort(p, p+n);
 vector <P> V;
  REP(i, n) {
 if (i == n-1 || p[i+1].X != p[i].X) V.push_back(p[i]);
 }
 
  n = (int) V.size();
  REP(i, n) p[i] = V[i];
 
  make_hulls();
 
 int gran = sqrt(MAXABS);
  REP(i, n) {
 double bst = 1e18;
 int indr = -1;
 
 for (int j=i+1; j<n; j++) {
 if (p[j].X - MAXABS / ((double) (p[j].X - p[i].X)) > bst) break;
 
      assert(j - i < gran + 5);
 double tmp = p[j].X + ((double) p[j].Y - p[i].Y) / (p[i].X - p[j].X);
 if (tmp < bst) {
	bst = tmp;
	indr = j;
 } 
 }
 
 int ind=indr;
 if (ind != -1) {
      S.insert(make_pair(frac{p[i].Y - p[ind].Y - sq(p[i].X) + sq(p[ind].X), p[i].X - p[ind].X},
			 frac{(ll) p[i].Y * p[ind].X - (ll) p[i].X * p[ind].Y + (ll) p[i].X * sq(p[ind].X) - (ll) sq(p[i].X) * p[ind].X,
			     p[ind].X - p[i].X}));
 } 
 }
 
 //  TRACE(S.size());
 
 int sol = 0;
 for (auto it : S) {
 //    TRACE(it.X.a _ it.X.b _ it.Y.a _ it.Y.b);
 double mx = max(get_max(LH, getd(it.X), getd(it.Y)), get_max(RH, getd(it.X), getd(it.Y)));
 
 //    TRACE(mx);
 if (mx <= EPS) sol++;
 } 
 
  printf("%d\n", sol);
 
 return 0;
}
