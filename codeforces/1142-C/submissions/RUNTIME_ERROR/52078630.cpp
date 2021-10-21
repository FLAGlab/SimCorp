// A divide and conquer program to find convex 
/* ****revpro**** */
 
#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define endl       '\n'
#define pii         pair<ll,ll>
#define vi          vector<ll>
#define all(a) (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x) (ll)x.size()
#define hell        1000000007
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=b-1;i>=a;i--) 
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define mii        map<ll,ll>
using namespace std;
 
#define N  100005
vector <pii> hull;
ll cross(pii A, pii B, pii C){
 return (B.x-A.x)*(C.y-A.y)-(B.y-A.y)*(C.x-A.x);
}
void convex_hull(vector<pii> pts) {
    hull.clear();
    sort(pts.begin(), pts.end());
    rep(i,0,sz(pts)){
 while(sz(hull)>=2 && cross(hull[sz(hull)-2],hull.back(),pts[i])<=0) hull.pop_back();
        hull.pb(pts[i]);
 }
 int s=sz(hull);
 for(int i=pts.size()-2;i>=0;i--){
 while(sz(hull)>=s+1 && cross(hull[sz(hull)-2],hull.back(),pts[i])<=0) hull.pop_back();
        hull.pb(pts[i]);
 }
}
int main() 
{ 
 vector<pair<ll, ll> > a; 
    ll n;
    cin>>n;
    rep(i,0,n){
        ll x,y;
        cin>>x>>y;
        a.pb({x,y-x*x});
 } 
    convex_hull(a); 
    ll n1=sz(a);
 set <long double> s;
    ll ia = 0, ib = 0; 
 for (ll i=1; i<n1; i++) 
 if (hull[i].first > hull[ia].first) 
            ia = i; 
 
 for (ll i=1; i<n1; i++) 
 if (hull[i].first < hull[ib].first) 
            ib=i; 
 while(ia!=ib){
 if(hull[ia].x==hull[(ia+1)%n1].x)
 {ia=(ia+1)%n1;continue;}
        s.insert((hull[(ia+1)%n1].y-hull[ia].y)/(1.0*hull[(ia+1)%n1].x-hull[ia].x));
        ia=(ia+1)%n1;
 }
    cout<<sz(s);
 return 0; 
} 
