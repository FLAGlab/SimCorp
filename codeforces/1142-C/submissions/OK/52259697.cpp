#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define eps 1e-9
struct point{
 double x,y;
 friend inline bool operator<(const point &A,const point &B)
 {
 if(fabs(A.x-B.x)>eps) return A.x<B.x;
 return A.y<B.y;
 }
};
point a[N],p[N],st[N];
int n,m,top;
inline bool check(const point &X,const point &Y,const point &Q)
{
 double ax=X.y-X.x*X.x,ay=Y.y-Y.x*Y.x;
 double b=(ax-ay)/(X.x-Y.x),c=ax-b*X.x;
 return Q.y-Q.x*Q.x-b*Q.x-c>-eps;
}
 
signed main()
{
	scanf("%d",&n);
 for(int i=1;i<=n;i++) scanf("%lf%lf",&a[i].x,&a[i].y);
	sort(a+1,a+n+1);
 for(int i=1;i<=n;i++) if(n==i||fabs(a[i].x-a[i+1].x)>eps) p[++m]=a[i];
 for(int i=m;i>=1;i--)
 {
 for(;top>1&&check(st[top],st[top-1],p[i]);top--);
		st[++top]=p[i];
 }
	printf("%d\n",top-1);
 return 0;
}
