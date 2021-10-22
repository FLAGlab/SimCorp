#include<bits/stdc++.h>
const int N=10005;
const double eps=1e-8;
bool usd[N][N];
int n;
long long ans;
struct node{
 int x,y;
}a[N];
double fabs(double x){return x<0?-x:x;}
bool equ(double x,double y){
 return fabs(x-y)<=eps;
}
signed main(){
	scanf("%d",&n);
 for(int i=1; i<=n; i++) scanf("%d%d",&a[i].x,&a[i].y);
 for(int i=1; i<n; i++){
 for(int j=i+1; j<=n; j++){
 if(a[i].x==a[j].x||usd[i][j]) continue;
 double b=(a[i].y-a[j].y-a[i].x*a[i].x+a[j].x*a[j].x)/(a[i].x-a[j].x),c=a[i].y-a[i].x*a[i].x-b*a[i].x;
 bool can=1;
 for(int k=1; k<=n; k++){
 double rhs=a[k].x*a[k].x+b*a[k].x+c;
 if(a[k].y>rhs+eps) can=0;
 if(equ(a[k].y,rhs)) usd[i][k]=usd[j][k]=usd[k][j]=1;
 }
			ans+=can;
 }
 }
	printf("%lld\n",ans);
 return 0;
}
 
