#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
#define ll long long
 
using namespace std;
 
const int N=1e5+10;
int n,top;
 
#define vec poi
struct poi{
	ll x,y;
	poi(ll x=0,ll y=0):x(x),y(y){}
 friend vec operator - (vec A,vec B){return vec(A.x-B.x,A.y-B.y);}
 friend ll operator ^ (vec A,vec B){return A.x*B.y-A.y*B.x;}
 friend bool operator < (poi x,poi y){return x.x!=y.x?x.x<y.x:x.y<y.y;}
}a[N],stk[N];
 
int main(){
	scanf("%d",&n);
	rep (i,1,n){
		scanf("%lld%lld",&a[i].x,&a[i].y);
		a[i].y-=a[i].x*a[i].x;
 
 }
	sort(a+1,a+1+n);
	rep (i,1,n){
 while (top>=2&&((a[i]-stk[top-1])^(stk[top]-stk[top-1]))<=0) top--;
 while (top&&a[i].x==stk[top].x) top--;
		stk[++top]=a[i];
 }
	printf("%d\n",top-1);
 return 0;
}
