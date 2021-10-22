#include<bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
#define T long double
#define EPS 1e-9
const int N=1e6;
const int N2=-1e18;
struct PT{
	T x, y;
	PT() {}
	PT(T x, T y) : x(x), y(y) {}
	PT(const PT& p) : x(p.x), y(p.y) {}
 bool operator < (const PT& rhs) const{
 return make_pair(y, x) < make_pair(rhs.y, rhs.x);
 }
 bool operator == (const PT& rhs) const{
 return make_pair(y, x) == make_pair(rhs.y, rhs.x);
 }
	PT operator + (const PT& p) const{
 return PT(x+p.x, y+p.y);
 }
	PT operator - (const PT& p) const{
 return PT(x-p.x, y-p.y);
 }
	PT operator * (T c) const {
 return PT(x*c, y*c);
 }
	PT operator / (T c) const {
 return PT(x/c, y/c);
 }
};
 
T cross(PT p, PT q){
 return p.x*q.y-p.y*q.x;
}
 
T area2(PT a, PT b, PT c){
 return cross(a, b)+cross(b, c)+cross(c, a);
}
 
T dot(PT p, PT q){
 return p.x*q.x+p.y*q.y;
}
 
T dist2(PT p, PT q){
 return dot(p-q, p-q);
}
 
bool between(const PT& a, const PT& b, const PT& c){
 return (fabs(area2(a, b, c))<EPS && (a.x-b.x)*(c.x-b.x)<=0 && (a.y-b.y)*(c.y-b.y)<=0);
}
 
void Con(vector<PT>& pts){
	sort(pts.begin(), pts.end());
	pts.erase(unique(pts.begin(), pts.end()), pts.end());
 vector<PT> up, dn;
 for(int i=0; i<pts.size(); i++){
 while(up.size()>1 && area2(up[up.size()-2], up.back(), pts[i])>=0){
			up.pop_back();
 }
 while(dn.size()>1 && area2(dn[dn.size()-2], dn.back(), pts[i])<=0){
			dn.pop_back();
 }
		up.push_back(pts[i]);
		dn.push_back(pts[i]);
 }
	pts=dn;
 for(int i=up.size()-2; i>=1; i--){
		pts.push_back(up[i]);
 }
 if(pts.size()<=2){
 return;
 }
	dn.clear();
	dn.push_back(pts[0]);
	dn.push_back(pts[1]);
 for(int i=2; i<pts.size(); i++){
 if(between(dn[dn.size()-2], dn[dn.size()-1], pts[i])){
			dn.pop_back();
 }
		dn.push_back(pts[i]);
 }
 if(dn.size()>=3 && between(dn.back(), dn[0], dn[1])){
		dn[0]=dn.back();
		dn.pop_back();
 }
	pts=dn;
}
 
int LP(PT a, PT b, PT c, PT d){
 return fabs(cross(b-a, c-d))<EPS;
}
 
int LC(PT a, PT b, PT c, PT d){
 return LP(a, b, c, d) && fabs(cross(a-b, a-c)) < EPS && fabs(cross(c-d, c-a))<EPS;
}
 
 
int seg(PT a, PT b, PT c, PT d){
 if(LC(a, b, c, d)){
 if(dist2(a, c)<EPS || dist2(a, d)<EPS || dist2(b, c)<EPS || dist2(b, d)<EPS){
 return 1;
 }
 if(dot(c-a, c-b)>0 && dot(d-a, d-b)>0 && dot(c-b, d-b)>0){
 return 0;
 }
 return 1;
 }
 if(cross(d-a, b-a)*cross(c-a, b-a)>0){
 return 0;
 }
 if(cross(a-c, d-c)*cross(b-c, d-c)>0){
 return 0;
 }
 return 1;
}
 
PT lin(PT a, PT b, PT c, PT d){
	b=b-a;
	d=c-d;
	c=c-a;
 return a + b*cross(c, d)/cross(b, d);
}
 
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 int n;
	cin>>n;
 int val[2000005];
 for(int i=0; i<2000005; i++){
		val[i]=N2;
 }
 for(int i=0; i<n; i++){
 int x, y;
		cin>>x>>y;
		x=x+1000000;
		val[x]=max(val[x], y-x*x);
 }
 vector<PT>v;
 for(int i=0; i<2000005; i++){
 if(val[i]!=N2){
			v.pb(PT(i, val[i]));
 }
 }
 Con(v);
 int maxi=N2;
 int mini=-N2;
 int ind1=-1;
 int ind2=-1;
 for(int i=0; i<v.size(); i++){
 if(v[i].x>maxi){
			maxi=v[i].x;
			ind1=i;
 }
 if(v[i].x<mini){
			mini=v[i].x;
			ind2=i;
 }
 }
 if(v[(ind1+1)%v.size()].y>=v[ind1].y){
		cout<<((ind2-ind1+v.size()))%(v.size());
 }
 else{
		cout<<(ind1-ind2+v.size())%(v.size());
 }
 return 0;
}
