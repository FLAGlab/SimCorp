#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
struct Point{
	ll x,y;
 Point(ll _x = 0,ll _y = 0):x(_x),y(_y){}
 Point operator -(const Point &b)const{
 return Point(x-b.x,y-b.y);
 }
	ll operator *(const Point &b)const{
 return x*b.y-y*b.x;
 }
 bool operator <(const Point &b) const{
 if(x != b.x) return x < b.x;
 else return y > b.y;
 }
}p[N],q[N],st[N];
 
int main(){
 int n;
	cin >> n;
 for(int i=1;i<=n;i++){
		cin >> p[i].x >> p[i].y;
		p[i].y -= p[i].x*p[i].x;
 }
	sort(p+1,p+1+n);
 int m = 1,top = 0;
	q[m] = p[1];
 for(int i=2;i<=n;i++){
 if(p[i].x != p[i-1].x) q[++m] = p[i];
 }
 for(int i=1;i<=m;i++){
 while(top > 1 && (st[top]-st[top-1]) * (q[i] - st[top-1]) >= 0) top--;
		st[++top] = q[i];
 }
	cout << top-1 << endl;
 return 0;
}
