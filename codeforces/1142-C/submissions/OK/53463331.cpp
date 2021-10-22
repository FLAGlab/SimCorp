#include<bits/stdc++.h>
#define maxn 100005
#define eps 1e-10
using namespace std;
 
int n;
struct Point{
 double x,y;
 Point(double x=0,double y=0):x(x),y(y){}
 Point operator -(const Point &B)const{ return Point(x-B.x,y-B.y); }
 double operator *(const Point &B)const{return x*B.y-y*B.x;} 
 friend bool operator <(const Point &A,const Point &B){ return A.x==B.x?A.y<B.y:A.x<B.x; }
}P[maxn],Q[maxn];
int tp;
 
signed main(){
	scanf("%d",&n);
 for(int i=1;i<=n;i++)
		 scanf("%lf%lf",&P[i].x,&P[i].y),P[i].y-=P[i].x*P[i].x;
	sort(P+1,P+1+n);
 for(int i=1;i<=n;i++){
 for(;tp && (Q[tp-1]-Q[tp-2]) * (P[i]-Q[tp-1]) >= -eps;tp--);
		Q[tp++] = P[i];
 }
 int ans = tp-1;
 for(int i=1;i<tp;i++) 
 if(Q[i].x == Q[i-1].x) 
			ans --;
	printf("%d\n",ans);
}
