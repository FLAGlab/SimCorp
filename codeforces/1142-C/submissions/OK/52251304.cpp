#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
struct Point {
  ll x,y;
 Point() {}
 Point(ll a,ll b):x(a),y(b) {}
 Point operator - (Point b) {return Point(x-b.x,y-b.y);}
 bool operator < (const Point & b) const {return (x!=b.x)?x<b.x:y<b.y;}
};
 
inline ll cross(Point x,Point y) {
 return x.x*y.y-x.y*y.x;
}
 
Point p[200005],st[200005];
 
int solve(int n) {
  sort(p+1,p+n+1);
 int top=0;
 for(int i=1;i<=n;i++) {
 while (top>1&&cross(p[i]-st[top],st[top]-st[top-1])<=0) top--;
  	st[++top]=p[i];
 }
 int ans=0;
 for(int i=1;i<top;i++)
 if (st[i].x<st[i+1].x) ans++;
 return ans;
}
 
int main() {
 int n;
  scanf("%d",&n);
 for(int i=1;i<=n;i++) {
  	ll x,y;
  	scanf("%lld%lld",&x,&y);
  	p[i]=Point(x,y-x*x);
 }
  printf("%d\n",solve(n));
 return 0;
}
