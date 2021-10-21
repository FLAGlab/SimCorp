#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
#define rep(i,l,r) for (int i=(l); i<=(r); i++)
using namespace std;
 
const int N=250010;
int n,x,y;
struct P{
 int x;double y;
 bool operator<(const P &b)const{return x<b.x||(x==b.x&&y>b.y);}
}p[N];
vector<P> v;
 
bool check(P a,P b,P c){
 double K=(b.y-a.y)/(b.x-a.x),B=a.y-K*a.x;
 return K*c.x+B-c.y>-1e-9;
}
 
int main(){
	scanf("%d",&n);
	rep(i,0,n-1) scanf("%d%d",&x,&y),p[i]=(P){x,y-1.*x*x};
	sort(p,p+n);
	rep(i,0,n-1){
 if (i && p[i].x==p[i-1].x)continue;
 while (v.size()>1 && check(v[v.size()-2],p[i],v.back())) v.pop_back();
		v.push_back(p[i]);
 }
	cout<<v.size()-1<<endl;
 return 0;
}
