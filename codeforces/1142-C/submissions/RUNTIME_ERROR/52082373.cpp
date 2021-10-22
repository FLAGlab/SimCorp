#include<bits/stdc++.h>
/* ****TCIITB**** */
 
#define io          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
#define ll          long long
#define pb          push_back
#define	endl		'\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a) (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x) (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b) for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define time        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
using namespace std;
 
#define N  100005
std::vector<pii> points;
ll n;
std::vector<pii> hull;
ll cross(pii A, pii B, pii C){
 return (B.F-A.F)*(C.S-A.S)-(B.S-A.S)*(C.F-A.F);
}
void convex_hull(vector<pii> pts) {
	hull.clear();
	sort(pts.begin(), pts.end());
	rep(i,0,sz(pts)){
 while(sz(hull)>=2 && cross(hull[sz(hull)-2],hull.back(),pts[i])<=0) hull.pop_back();
		hull.pb(pts[i]);
 }
	ll s=sz(hull);
 for(ll i=pts.size()-2;i>=0;i--){
 while(sz(hull)>=s+1 && cross(hull[sz(hull)-2],hull.back(),pts[i])<=0) hull.pop_back();
		hull.pb(pts[i]);
 }
}
signed main()
{
 
	io
	cin>>n;
	rep(i,0,n)
 {
		ll x,y;
		cin>>x>>y;
		points.pb({x,y-x*x});
 }
	convex_hull(points);
	ll lx = 0, rx = 0; 
    rep(i,0,hull.size())
 if (hull[i].first > hull[lx].first) 
            lx = i; 
    rep(i,0,hull.size())
 if (hull[i].first < hull[rx].first) 
            rx=i;
 set<pii> res;
 while(lx!=rx){
 if(hull[lx].F==hull[(lx+1)%hull.size()].F)
 {
            	lx=(lx+1)%hull.size(); 
 continue;
 } 
        ll z=__gcd(hull[lx].S-hull[(lx+1)%hull.size()].S,hull[lx].F-hull[(lx+1)%hull.size()].F);
 
        res.insert({(hull[lx].S-hull[(lx+1)%hull.size()].S)/z,(hull[lx].F-hull[(lx+1)%hull.size()].F)/z});
        lx=(lx+1)%hull.size();
 }
    cout<<res.size();
 
 
 
 
 
 
}
