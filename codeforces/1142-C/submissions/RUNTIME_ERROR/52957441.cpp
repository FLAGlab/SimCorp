#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define rep(ii,a,b) for(int ii=a;ii<=b;++ii)
#define per(ii,a,b) for(int ii=b;ii>=a;--ii)
#define forn(ii,x) for(int ii=head[x];ii;ii=e[ii].next)
#pragma GCC optimize("Ofast")
#define show(x) cout<<#x<<"="<<x<<endl
#define show2(x,y) cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl
#define show3(x,y,z) cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl
#define show4(w,x,y,z) cout<<#w<<"="<<w<<" "<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl
#define show5(v,w,x,y,z) cout<<#v<<" "<<v<<" "<<#w<<"="<<w<<" "<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl
#define showa(a,b) cout<<#a<<'['<<b<<"]="<<a[b]<<endl
using namespace std;
const int maxn=2e5+10,maxm=2e6+10;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const double PI=acos(-1.0);
//head
int casn,n,m,k;
typedef double db;
const db eps=1e-6;
const db pi=acos(-1);
int sign(db k){
 if (k>eps) return 1; else if (k<-eps) return -1; return 0;
}
int cmp(db k1,db k2){return sign(k1-k2);}
int inmid(db k1,db k2,db k3){return sign(k1-k3)*sign(k2-k3)<=0;}// k3 在 [k1,k2] 内
struct point{
    db x,y;
    point operator + (const point &k1) const{return (point){k1.x+x,k1.y+y};}
    point operator - (const point &k1) const{return (point){x-k1.x,y-k1.y};}
    point operator * (db k1) const{return (point){x*k1,y*k1};}
    point operator / (db k1) const{return (point){x/k1,y/k1};}
 int operator == (const point &k1) const{return cmp(x,k1.x)==0&&cmp(y,k1.y)==0;}
 // 逆时针旋转
    point turn(db k1){return (point){x*cos(k1)-y*sin(k1),x*sin(k1)+y*cos(k1)};}
    point turn90(){return (point){-y,x};}
 bool operator < (const point k1) const{
 int a=cmp(x,k1.x);
 if (a==-1) return 1; else if (a==1) return 0; else return cmp(y,k1.y)==-1;
 }
    db abs(){return sqrt(x*x+y*y);}
    db abs2(){return x*x+y*y;}
    db dis(point k1){return ((*this)-k1).abs();}
    point unit(){db w=abs(); return (point){x/w,y/w};}
 void scan(){double k1,k2; scanf("%lf%lf",&k1,&k2); x=k1; y=k2;}
 void print(){printf("%.11lf %.11lf\n",x,y);}
    db getw(){return atan2(y,x);}
    point getdel(){if (sign(x)==-1||(sign(x)==0&&sign(y)==-1)) return (*this)*(-1); else return (*this);}
 int getP() const{return sign(y)==1||(sign(y)==0&&sign(x)==-1);}
};
int inmid(point k1,point k2,point k3){return inmid(k1.x,k2.x,k3.x)&&inmid(k1.y,k2.y,k3.y);}
db cross(point k1,point k2){return k1.x*k2.y-k1.y*k2.x;}
db dot(point k1,point k2){return k1.x*k2.x+k1.y*k2.y;}
db rad(point k1,point k2){return atan2(cross(k1,k2),dot(k1,k2));}
vector<point> ConvexHull(vector<point>A,int flag=1){ // flag=0 不严格 flag=1 严格
 int n=A.size(); vector<point>ans(n*2);
    sort(A.begin(),A.end()); int now=-1;
 for (int i=0;i<A.size();i++){
 while (now>0&&sign(cross(ans[now]-ans[now-1],A[i]-ans[now-1]))<flag) now--;
        ans[++now]=A[i];
 } int pre=now;
 for (int i=n-2;i>=0;i--){
 while (now>pre&&sign(cross(ans[now]-ans[now-1],A[i]-ans[now-1]))<flag) now--;
        ans[++now]=A[i];
 } ans.resize(now); return ans;
}
void getUDP(vector<point>A,vector<point>&U,vector<point>&D){
    db l=1e100,r=-1e100;
 for (int i=0;i<A.size();i++) l=min(l,A[i].x),r=max(r,A[i].x);
 int wherel,wherer;
 for (int i=0;i<A.size();i++) if (cmp(A[i].x,l)==0) wherel=i;
 for (int i=A.size();i;i--) if (cmp(A[i-1].x,r)==0) wherer=i-1;
    U.clear(); D.clear(); int now=wherel;
 while (1){D.push_back(A[now]); if (now==wherer) break; now++; if (now>=A.size()) now=0;}
    now=wherel;
 while (1){U.push_back(A[now]); if (now==wherer) break; now--; if (now<0) now=A.size()-1;}
}
int main() {
	IO;
	cin>>n;
 vector<point> a(n);
 vector<point> u(n);
 vector<point> d(n);
 vector<point> c;
 for(auto &i:a){
		cin>>i.x>>i.y;
		i.y-=i.x*i.x;
 }
	c=ConvexHull(a,1);
    getUDP(c,u,d);
 int sz=(int)u.size();
 int x=sz;
    rep(i,0,sz-2){
 if(sign(u[i].x-u[i+1].x)==0)x--;
 }
    cout<<max(x-1,0);
 return 0;
}
 
