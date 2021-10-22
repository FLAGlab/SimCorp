#include<bits/stdc++.h>
 
// #define DEBUG 1
 
#define int long long
#define for0(i,n) for (int i=0; i<n; i++)
#define iter(c) for(auto it=c.begin(); it!=c.end(); it++)
#define iter2(c) for(auto it2=c.begin(); it2!=c.end(); it2++)
#define pb push_back
#define ms(a,z) memset(a,z,sizeof(a));
#define mp make_pair
#define X first
#define Y second
#define sqr(x) 1LL*(x)*(x)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define all(a) a.begin(),a.end()
#define sz(x) (int)(x).size()
#define pmod(x,m) (((x)%(m)+m)%m)
#ifdef int
#define read(x) scanf("%I64d",&x);
#else
#define read(x) scanf("%d",&x);
#endif
 
#ifdef DEBUG
#define nl cout<<"\n";
#define pr(x) cout<<(x)<<" ";
#define prl(x) cout<<#x " = "<<x<<endl;
#define prp(x) cout<<"("<<(x).first<<" "<<(x).second<<") ";
#define printv(v) {for(int _=0; _<sz(v); _++) cout<<v[_]<<" "; cout<<"\n";}
#define printa(a,s) {for (int _=0; _<s; _++) cout<<a[_]<<" "; cout<<"\n";}
#define print2D(a,m,n) {for (int _=0; _<m; _++) {for (int __=0; __<n; __++) cout<<a[_][__]<<" "; cout<<"\n";} cout<<"\n";}
#define priter(v) iter(v) {pr(*it)} nl
#define debug cout<<"ok at line "<<__LINE__<<endl;
#else
#define nl
#define pr(x)
#define prl(x)
#define prp(x)
#define printv(v)
#define printa(a,s)
#define print2D(a,m,n)
#define priter(v)
#define debug
#endif
#define MAXN 100000
 
using namespace std;
 
typedef long long ll;
 
const int INF = 2147483647;
const long long INFL = 9223372036854775807LL;
const double EPSILON = 0.00000001;
const long long MOD = 1000000007;
 
typedef pair<ll,ll> point; 
 
int cross_sign(point A, point B, point C) {
 // return (B.X - A.X) * (C.Y - A.Y) - (B.Y - A.Y) * (C.X - A.X);
 
 // Find parameters of parabola through B & C 
 double b = (B.Y - C.Y - sqr(B.X) + sqr(C.X)) / (double)(B.X - C.X); 
 double c = B.Y - sqr(B.X) - b*B.X; 
    assert(fabs(C.Y - sqr(C.X) - b*C.X - c) < EPSILON); 
 
 // Consider distance of A above the parabola 
 double dist = A.Y - (sqr(A.X) + b*A.X + c); 
 // prl(dist) 
 if (fabs(dist) < EPSILON) 
 return 0; 
 else if (C.X > B.X) {
 if (dist > 0)
 return 1; 
 else 
 return -1;
 }
 else { 
 if (dist > 0)
 return -1;
 else 
 return 1; 
 }
}
 
bool check_collinear(vector<point>& points) {
 for (int i=2; i<sz(points); i++) {
 if (cross_sign(points[i-2], points[i-1], points[i]) != 0)
 return false; 
 }
 return true; 
}
 
void convex_hull(vector<point>& pts, vector<point>& hull) {
	hull.clear(); 
    sort(pts.begin(), pts.end());
 for (int i=0; i<pts.size(); i++) {
 while (hull.size() >= 2 && cross_sign(hull[hull.size()-2], hull.back(), pts[i]) <= 0) {
            hull.pop_back();
 }
		hull.push_back(pts[i]);
 }
 int s = hull.size();
 for (int i=pts.size()-2; i>=0; i--) {
 while (hull.size() >= s+1 && cross_sign(hull[hull.size()-2], hull.back(), pts[i]) <= 0) {
            hull.pop_back();
 }
		hull.push_back(pts[i]);
 }
}
 
int32_t main()
{
 #ifdef DEBUG
 //freopen("C.txt","r",stdin);
 //freopen("","w",stdout);
 #endif
 
 int n;
    cin >> n; 
 vector<point> points; 
 unordered_map<int,int> max_y; 
 
    for0(i,n) {
 int x,y;
        read(x); read(y);
 if (max_y.find(x) != max_y.end() and max_y[x] >= y)
 continue; 
        max_y[x] = y; 
        points.push_back({x,y});
 }
 
 if (sz(points) == 1) {
        cout<<0<<endl;
 return 0;
 }
 else if (sz(points) == 2) {
        cout<<1<<endl;
 return 0;
 }
 if (check_collinear(points)) {
        cout<<1<<endl;
 return 0; 
 }
 
 vector<point> hull; 
    convex_hull(points, hull); 
 // for0(i,sz(hull)) {prp(hull[i])} nl 
 int m = sz(hull)-1; 
 // for (int i=0; i<m; i++) {
 // pr(i) pr(cross_sign(hull[i], hull[(i+1)%m], hull[(i+2)%m])) nl 
 // }
 
 int ans = 0;
 for (int i=0; i<m; i++) {
 if (hull[i].X > hull[i+1].X)
            ans++;
 }
    cout<<ans<<endl; 
 return 0;
}
