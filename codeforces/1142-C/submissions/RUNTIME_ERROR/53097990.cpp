#include<bits/stdc++.h>
 
typedef long long int ll;
 
using namespace std;
 
#define pi 3.141592653589793238
typedef pair<ll,ll> pll;
typedef map<ll,ll> mll;
typedef set<ll> sl;
typedef map<int,int> mii;
typedef set<int> si;
typedef pair<double,double> pdd;
typedef map<double,ll> mdl;
typedef set<double> sd;
#define x first
#define y second
#define mp make_pair
#define pb push_back
// #define fin cin
// #define fout cout
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const ll N = 1005;
 
#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)
 
template<typename S, typename T>
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.f<<", "<<p.s<<')';return out;}
 
template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
ll l=v.size();for(ll i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}
 
template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}
 
template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}
 
struct point{
	ll x, y;
};
 
bool cmp(const point &a, const point &b){
 return a.x < b.x or (a.x == b.x and a.y < b.y);
}
 
bool cw(point &a, point &b, point &c){
 return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) <= 0;
}
 
bool ccw(point &a, point &b, point &c){
 return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) >= 0;
}
 
void computeConvexHull(vector<point> &v){
 if(v.size() == 1) return;
 
 int sz = v.size();
 
	sort(v.begin(), v.end(), cmp);
 
	point a = v[0], b = v[sz-1];
 
 vector<point> up, down;
 
	up.push_back(a);
	down.push_back(a);
 
 for(int i = 1; i < sz; i++){
 if(i == sz-1  or cw(a, v[i], b)){
 int k = up.size();
 while(k >= 2 and !cw(up[k-2], up[k-1], v[i])){
				up.pop_back(); k--;
 }
			up.pb(v[i]);
 }
 
 if(i == sz-1 or ccw(a, v[i], b)){
 int k = down.size();
 while(k >= 2 and !ccw(down[k-2], down[k-1], v[i])){
				down.pop_back(); k--;
 }
			down.pb(v[i]);
 }
 }
 
	v.clear();
 for (int i = 0; i < up.size(); ++i)
        v.pb(up[i]);
 // for (int i = down.size() - 2; i > 0; --i)
 //     v.pb(down[i]);
}
 
vector <point> hull, points;
ll n;
 
void solve()
{
    ll n;
    cin >> n;
    hull.resize(n);
    points.resize(n);
 for(int i = 0; i<n; i++)
 {
        cin >> points[i].x >> points[i].y;
        hull[i].x = points[i].x;
        hull[i].y = points[i].y - points[i].x*points[i].x;
 }
    computeConvexHull(hull);
 
    sort(hull.begin(), hull.end(), cmp);
 
    ll ans = 0;
 
 for(int i = 0; i<hull.size()-2; i++)
 {
        point p1 = hull[i];
        point p2 = hull[i+1];
        point p3 = hull[i+2];
 
 if(p1.x == p2.x)
 {
            ans--;
 continue;
 }
 
 if( (p1.y - p2.y)*(p2.x - p3.x) == (p2.y - p3.y)*(p1.x - p2.x) )
 {
            ans--;
 }
 }
 
    ll siz = hull.size();
 
    point p1 = hull[siz-2];
    point p2 = hull[siz-1];
 
 if(p1.x == p2.x)
 {
        ans--;
 }
 
    cout << ans + hull.size() - 1 << endl;
}
 
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(50);
	solve();
}
