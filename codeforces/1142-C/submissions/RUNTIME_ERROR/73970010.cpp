#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long ll1;
const ll MAX=1e6+5;
ll MOD=1e9+7;
ll MOD1=1e9+7;
#define pb push_back
#define se second
#define fi first
#define sb __builtin_popcount
#define maxe max_element
#define mine min_element
#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define debug4(x,y,z,w) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\t"<<#w<<" :: "<<w<<endl;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fbo find_by_order
#define ook order_of_key
#define ub upper_bound
#define lb lower_bound
#define pq priority_queue
#define pll pair<ll,ll>
using namespace __gnu_pbds;
#define ordereds tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define error 0.000000000000000001
ll add(ll a,ll b){if((ll1)a+b>=MOD)return (ll1)a+b-MOD;return a+b;}
ll mul(ll a,ll b){return ((ll1)a*b)%MOD;}
ll sub(ll a,ll b){if(a>=b)return a-b;return a-b+MOD;}
ll add1(ll a,ll b){return ((ll1)a+b)%MOD1;}
ll mul1(ll a,ll b){return ((ll1)a*b)%MOD1;}
#define boost               ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define dt pair<pll,ll>
template <class F>
struct Point {
  F x, y;
 Point() : x(0), y(0) {}
 Point(const F& x, const F& y) : x(x), y(y) {}
 
 void swap(Point& other) { using std::swap; swap(x, other.x); swap(y, other.y); }
 template <class F1> explicit operator Point<F1> () const {
 return Point<F1>(static_cast<F1>(x), static_cast<F1>(y)); }
 template <class F1> Point& operator = (const Point<F1>& other) {
    x = other.x; y = other.y; return *this; }
 template <class F1> Point& operator += (const Point<F1>& other) {
    x += other.x; y += other.y; return *this; }
 template <class F1> Point& operator -= (const Point<F1>& other) {
    x -= other.x; y -= other.y; return *this; }
 template <class F1> Point& operator *= (const F1& factor) {
    x *= factor; y *= factor; return *this; }
 template <class F1> Point& operator /= (const F1& factor) {
    x /= factor; y /= factor; return *this; }
};
 
template <class F> int read(Point<F>& point) { return read(point.x, point.y) / 2; }
template <class F> int write(const Point<F>& point) { return write(point.x, point.y); }
 
template <class F> istream& operator >> (istream& is, Point<F>& point) {
 return is >> point.x >> point.y; }
template <class F> ostream& operator << (ostream& os, const Point<F>& point) {
 return os << point.x << ' ' << point.y; }
 
template <class F> inline Point<F> makePoint(const F& x, const F& y) { return Point<F>(x, y); }
template <class F> void swap(Point<F>& lhs, Point<F>& rhs) { lhs.swap(rhs); }
 
#define FUNC1(name, arg, expr) \
template <class F> inline auto name(const arg) -> decltype(expr) { return expr; }
#define FUNC2(name, arg1, arg2, expr) \
template <class F1, class F2> \
inline auto name(const arg1, const arg2) -> decltype(expr) { return expr; }
#define FUNC3(name, arg1, arg2, arg3, expr) \
template <class F1, class F2, class F3> \
inline auto name(const arg1, const arg2, const arg3) -> decltype(expr) { return expr; }
 
FUNC1(operator -, Point<F>& point, makePoint(-point.x, -point.y))
FUNC2(operator +, Point<F1>& lhs, Point<F2>& rhs, makePoint(lhs.x + rhs.x, lhs.y + rhs.y))
FUNC2(operator -, Point<F1>& lhs, Point<F2>& rhs, makePoint(lhs.x - rhs.x, lhs.y - rhs.y))
FUNC2(operator *, F1& factor, Point<F2>& rhs, makePoint(factor * rhs.x, factor * rhs.y))
FUNC2(operator *, Point<F1>& lhs, F2& factor, makePoint(lhs.x * factor, lhs.y * factor))
FUNC2(operator /, Point<F1>& lhs, F2& factor, makePoint(lhs.x / factor, lhs.y / factor))
 
FUNC2(operator *, Point<F1>& lhs, Point<F2>& rhs, lhs.x * rhs.x + lhs.y * rhs.y)
FUNC2(operator ^, Point<F1>& lhs, Point<F2>& rhs, lhs.x * rhs.y - lhs.y * rhs.x)
 
// < 0 if rhs <- lhs counter-clockwise, 0 if collinear, > 0 if clockwise.
FUNC2(ccw, Point<F1>& lhs, Point<F2>& rhs, rhs ^ lhs)
FUNC3(ccw, Point<F1>& lhs, Point<F2>& rhs, Point<F3>& origin, ccw(lhs - origin, rhs - origin))
 
FUNC2(operator ==, Point<F1>& lhs, Point<F2>& rhs, lhs.x == rhs.x && lhs.y == rhs.y)
FUNC2(operator !=, Point<F1>& lhs, Point<F2>& rhs, !(lhs == rhs))
 
FUNC2(operator <, Point<F1>& lhs, Point<F2>& rhs,
    lhs.y < rhs.y || (lhs.y == rhs.y && lhs.x < rhs.x))
FUNC2(operator >, Point<F1>& lhs, Point<F2>& rhs, rhs < lhs)
FUNC2(operator <=, Point<F1>& lhs, Point<F2>& rhs, !(lhs > rhs))
FUNC2(operator >=, Point<F1>& lhs, Point<F2>& rhs, !(lhs < rhs))
 
// Angles and rotations (counter-clockwise).
FUNC1(angle, Point<F>& point, atan2(point.y, point.x))
FUNC2(angle, Point<F1>& lhs, Point<F2>& rhs, atan2(lhs ^ rhs, lhs * rhs))
FUNC3(angle, Point<F1>& lhs, Point<F2>& rhs, Point<F3>& origin,
      angle(lhs - origin, rhs - origin))
FUNC3(rotate, Point<F1>& point, F2& angleSin, F3& angleCos,
      makePoint(angleCos * point.x - angleSin * point.y,
                angleSin * point.x + angleCos * point.y))
FUNC2(rotate, Point<F1>& point, F2& angle, rotate(point, sin(angle), cos(angle)))
FUNC3(rotate, Point<F1>& point, F2& angle, Point<F3>& origin,
      origin + rotate(point - origin, angle))
FUNC1(perp, Point<F>& point, makePoint(-point.y, point.x))
 
// Distances.
FUNC1(abs, Point<F>& point, point * point)
FUNC1(norm, Point<F>& point, sqrt(abs(point)))
FUNC2(dist, Point<F1>& lhs, Point<F2>& rhs, norm(lhs - rhs))
FUNC2(dist2, Point<F1>& lhs, Point<F2>& rhs, abs(lhs - rhs))
FUNC2(bisector, Point<F1>& lhs, Point<F2>& rhs, lhs * norm(rhs) + rhs * norm(lhs))
 
#undef FUNC1
#undef FUNC2
#undef FUNC3
template <class F>
struct Line {
 Point<F> a, ab;
 Line() : a(), ab() {}
 Line(const Point<F>& a, const Point<F>& b, bool twoPoints = true)
 : a(a), ab(twoPoints ? b - a : b) {}
 Line(const F& xa, const F& ya, const F& xb, const F& yb)
 : a(xa, ya), ab(xb - xa, yb - ya) {}
 
 void swap(Line& other) { using std::swap; swap(a, other.a); swap(ab, other.ab); }
 template <class F1> explicit operator Line<F1> () const {
 return Line<F1>(Point<F1>(a), Point<F1>(ab), false); }
 template <class F1> Line& operator = (const Line<F1>& other) {
    a = other.a; ab = other.ab; return *this; }
 
 Point<F> b() const { return a + ab; }
 operator bool () const { return ab != Point<F>(); }
};
 
template <class F> int read(Line<F>& line) {
 int res = read(line.a, line.ab) / 2;
 return line.ab -= line.a, res;
}
 
template <class F>
inline Line<F> makeLine(const Point<F>& a, const Point<F>& b, bool twoPoints = true) {
 return Line<F>(a, b, twoPoints);
}
 
template <class F> void swap(Line<F>& lhs, Line<F>& rhs) { lhs.swap(rhs); }
template <class F1, class F2>
bool onLine(const Point<F1>& point, const Line<F2>& line) {
 if (!line) return point == line.a;
 return ((point - line.a) ^ line.ab) == 0;
}
template <class F1, class F2>
bool onSegment(const Point<F1>& point, const Line<F2>& seg) {
 if (!seg) return point == seg.a;
 auto vecta = seg.a - point, vectb = seg.b() - point;
 return (vecta ^ vectb) == 0 && (vecta * vectb) <= 0;
}
template <class F1, class F2> using distF = decltype(sqrt(F1() + F2()));
 
template <class F1, class F2>
distF<F1, F2> distLine(const Point<F1>& point, const Line<F2>& line) {
 if (!line) return dist(point, line.a);
 return abs((point - line.a) ^ line.ab) / norm(line.ab);
}
template <class F1, class F2>
distF<F1, F2> distSegment(const Point<F1>& point, const Line<F2>& seg) {
 if (((point - seg.a) * seg.ab) <= 0) return dist(point, seg.a);
 if (((point - seg.b()) * seg.ab) >= 0) return dist(point, seg.b());
 return distLine(point, seg);
}
template <class F1, class F2, class F3>
void projection(const Point<F1>& point, const Line<F2>& line, Point<F3>& res) {
  res = line.a;
 if (line) res += line.ab * static_cast<F3>((point - line.a) * line.ab) / abs(line.ab);
}
 
template <class F1, class F2, class F3>
void reflection(const Point<F1>& point, const Line<F2>& line, Point<F3>& res) {
  projection(point, line, res);
  res = 2 * res - point;
}
template <class F1, class F2, class F3>
void closest(const Point<F1>& point, const Line<F2>& seg, Point<F3>& res) {
 if (((point - seg.a) * seg.ab) <= 0) res = seg.a;
 else if (((point - seg.b()) * seg.ab) >= 0) res = seg.b();
 else projection(point, seg, res);
}
template <int TYPE> struct EndpointChecker {};
template <> struct EndpointChecker<0> { // no endpoint (ray)
 template <class F> bool operator ()(const F& a, const F& b) const { return true; }};
template <> struct EndpointChecker<1> { // closed endpoint
 template <class F> bool operator ()(const F& a, const F& b) const { return a <= b; }};
template <> struct EndpointChecker<2> { // open endpoint
 template <class F> bool operator ()(const F& a, const F& b) const { return a < b; }};
 
template <int LA, int LB, int RA, int RB, class F1, class F2, class F3>
bool intersectLines(const Line<F1>& lhs, const Line<F2>& rhs, Point<F3>& res) {
  assert(lhs && rhs);
 auto s = lhs.ab ^ rhs.ab;
 if (s == 0) return false;
 auto ls = (rhs.a - lhs.a) ^ rhs.ab;
 auto rs = (rhs.a - lhs.a) ^ lhs.ab;
 if (s < 0) s = -s, ls = -ls, rs = -rs;
 bool intersect =
 EndpointChecker<LA>()(decltype(ls)(0), ls) && EndpointChecker<LB>()(ls, s) &&
 EndpointChecker<RA>()(decltype(rs)(0), rs) && EndpointChecker<RB>()(rs, s);
 if (intersect) res = lhs.a + lhs.ab * static_cast<F3>(ls) / s;
 return intersect;
}
 
template <class F1, class F2, class F3>
bool intersectClosedSegments(const Line<F1>& lhs, const Line<F2>& rhs, Point<F3>& res) {
 return intersectLines<1, 1, 1, 1>(lhs, rhs, res);
}
template <class F1, class F2, class F3>
bool intersectSegments(const Line<F1>& lhs, const Line<F2>& rhs, Line<F3>& res) {
 auto s = lhs.ab ^ rhs.ab;
 auto ls = (rhs.a - lhs.a) ^ rhs.ab;
 if (s == 0) {
 if (ls != 0) return false;
 auto lhsa = lhs.a, lhsb = lhs.b();
 auto rhsa = rhs.a, rhsb = rhs.b();
 if (lhsa > lhsb) swap(lhsa, lhsb);
 if (rhsa > rhsb) swap(rhsa, rhsb);
    res = Line<F3>(max(lhsa, rhsa), min(lhsb, rhsb));
 return res.ab >= Point<F3>();
 }
 auto rs = (rhs.a - lhs.a) ^ lhs.ab;
 if (s < 0) s = -s, ls = -ls, rs = -rs;
 bool intersect = 0 <= ls && ls <= s && 0 <= rs && rs <= s;
 if (intersect)
    res = Line<F3>(lhs.a + lhs.ab * static_cast<F3>(ls) / s, Point<F3>());
 return intersect;
}
template <class F>
struct AngleCompare {
 const Point<F> origin;
 const bool zero;
 
 AngleCompare(const Point<F>& origin = Point<F>())
 : origin(origin), zero(origin == Point<F>()) {}
 
 template <class F1, class F2>
 bool operator () (const Point<F1>& lhs, const Point<F2>& rhs) const {
 return zero ? ccw(lhs, rhs) < 0 : ccw(lhs, rhs, origin) < 0;
 }
};
 
template <class Iterator, class F>
void sortByAngle(Iterator first, Iterator last, const Point<F>& origin) {
  first = partition(first, last, [&origin](const decltype(*first)& point) {
 return point == origin; });
 auto pivot = partition(first, last, [&origin](const decltype(*first)& point) {
 return point > origin; });
 AngleCompare<F> acmp(origin);
  sort(first, pivot, acmp);
  sort(pivot, last, acmp);
}
bool cmp(Point<ll> a, Point<ll> b) {
 return a.x < b.x || (a.x == b.x && a.y >b.y);
}
bool cmp1(Point<ll>a ,Point<ll> b){
 return a.x<b.x || (a.x==b.x && a.y<b.y);
}
bool cw(Point<ll> a, Point<ll> b, Point<ll> c) {
 return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) <= 0;
}
void convex_hull(vector<Point<ll>>& a,vector<Point<ll>> &up) {
 if (a.size() == 1)
 return;
 
    sort(a.begin(), a.end(), &cmp1);
 Point<ll> p2 = a.back();
    sort(a.begin(),a.end(), &cmp);
 Point<ll> p1 = a[0];
    up.push_back(p1);
 for (int i = 1; i < (int)a.size(); i++) {
 if (cw(p1, a[i], p2)) {
 while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
 }
 if(a[i].x==p2.x && a[i].y==p2.y)break;
 }
 }
const int D=1e6+5;
int main()
{
    boost;
    cout<<fixed<<setprecision(12);
 #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output01.txt","w",stdout);
 #endif
 int n;
    cin>>n;
    ll a,b;
 vector<Point<ll>> points,edges;
 for(int i=0;i<n;i++){
      cin>>a>>b;
      points.pb(makePoint(a,(b-a*a)));
 //debug2(points[i].x,points[i].y);
 }
    ll ans=1;
    convex_hull(points,edges);
 //cout<<'a';
 //for(Point<ll> a:edges)debug2(a.x,a.y);
 Point<ll> start1=edges[0];
 Point<ll> start2=edges[1];
 int i=2;
 while(i<edges.size()){
      ll cnt=2;
 while(i<edges.size() && !ccw(edges[i],start2,start1)){
        cnt++,i++;
 }
 if(i==edges.size())break;
      start1=edges[i-1];
      start2=edges[i];
      i++;
      ans++;
 }
 if(edges.size()==n && ans==1)cout<<0;
 else cout<<ans;
}
