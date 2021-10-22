#include<bits/stdc++.h>
using namespace std;
 
struct point{
 long long x;
 long long y;
};
 
long long n, ans;
vector<point>v, hull;
point z;
 
bool cmp(point a, point b){
 if (a.x<b.x) return true;
 else if (a.x>b.x) return false;
 else{
 if (a.y<b.y) return true;
 else return false;
 }
}
 
point sub(point a, point b){
	point tmp;
	tmp.x=a.x-b.x;
	tmp.y=a.y-b.y;
 return tmp;
}
 
long long cross(point a, point b){
 return a.x*b.y-a.y*b.x;
}
 
void build(){
	hull.push_back(v[0]);
	hull.push_back(v[1]);
 long long now=2, ind=2, belok;
	point aa, bb, cc, dd, ee;
 while (now!=n){
		aa=hull[ind-2];
		bb=hull[ind-1];
		cc=v[now];
		dd=sub(bb,aa);
		ee=sub(cc,bb);
		belok=cross(dd,ee);
//		cout << aa.x << " " << aa.y << "\n" << bb.x << " " << bb.y << "\n" << cc.x << " " << cc.y << "\n" << belok << "\n";
 while (belok>=0){
			ind--;
			hull.pop_back();
 if (ind<=1) break;
			aa=hull[ind-2];
			bb=hull[ind-1];
			dd=sub(bb,aa);
			ee=sub(cc,bb);
			belok=cross(dd,ee);
//			cout << aa.x << " " << aa.y << "\n" << bb.x << " " << bb.y << "\n" << cc.x << " " << cc.y << "\n" << dd.x << " " << dd.y << "\n" << ee.x << " " << ee.y << "\n" << belok << "\n";
 }
		hull.push_back(cc);
		ind++;
		now++;
 }
}
 
signed main(){
	ans=0;
	cin >> n;
 for (int i=0;i<n;i++){
		cin >> z.x >> z.y;
		z.y-=(z.x*z.x);
		v.push_back(z);
 }
	sort(v.begin(),v.end(),cmp);
	build();
 long long sez=hull.size();
 for (int i=0;i<sez-1;i++){
 if (hull[i].x!=hull[i+1].x) ans++;
 }
	cout << ans << "\n";
}
