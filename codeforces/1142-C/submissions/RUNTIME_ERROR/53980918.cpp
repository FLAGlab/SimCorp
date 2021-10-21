#include <bits/stdc++.h>
#include<unistd.h>
#define inf (int)(1e9)
#define fi first
#define se second
#define M 20
using namespace std;
typedef pair<int, int> pii;
const int maxn = 2e5+100;
const int mod = 998244353;
typedef long long ll;
struct point{
    ll x,y;
    point(ll _x,ll _y) {
        x = _x,y = _y;
 }
    point(){}
    point operator + (const point&a)const {
 return point(x+a.x,y+a.y);
 }
    point operator - (const point&a)const {
 return point(x-a.x,y-a.y);
 }
 bool operator==(const point&a)const {
 return x==a.x&&y==a.y;
 }
};
ll det(const point &a,const point &b) {
 return a.x*b.y - a.y*b.x;
}
bool cmpless(const point &a,const point &b) {
 return a.x<b.x||a.x==b.x&&a.y<b.y;
}
vector<point> tubao(vector<point> a) {
 vector<point>res(a.size()*2+5);
    sort(a.begin(),a.end(),cmpless);
    a.erase(unique(a.begin(),a.end()),a.end());
 
 int m = 0;
 for(int i=0;i<a.size();++i) {
 while(m>1&&det(res[m-1]-res[m-2],a[i]-res[m-2])<=0) m--;
        res[m++] = a[i];
 }
 int k = m;
 for(int i=(int)a.size()-2;i>=0;--i) {
 while(m>k&&det(res[m-1]-res[m-2],a[i]-res[m-2])<=0) m--;
        res[m++] = a[i];
 }
    res.resize(m);
 if(a.size()>1) res.resize(m-1);
 return res;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
 int n;
    cin>>n;
 vector<point> p;
 for(int i=1;i<=n;++i) {
        ll x,y;
        cin>>x>>y;
        y = y-x*x;
        p.push_back(point(x,y));
 }
    p = tubao(p);
 int ans = 0;
 for(int i=0;i<p.size();++i) {
 int nx=(i+1)%p.size();
 if(p[nx].x<p[i].x) ans++;
 }
    sleep(1.5);
    cout<<ans<<'\n';
 return 1;
}
