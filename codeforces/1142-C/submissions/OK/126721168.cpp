#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int tail,ans;
struct node{
 int x,y;
}a[1000001],q[1000001];
int cmp(node a,node b){
 if(a.x==b.x) return a.y>b.y;
 return a.x<b.x;
}
inline int slope(node a,node x,node y){
 return (x.x-a.x)*(y.y-a.y)-(x.y-a.y)*(y.x-a.x);
}
int n;
signed main(){
	cin>>n;
 for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		a[i].y-=a[i].x*a[i].x;
 }
	sort(a+1,a+n+1,cmp);
	a[0].x=-2e9;
 for(int i=1;i<=n;i++){
 if(a[i].x==a[i-1].x) continue ;
 while(tail>1&&slope(a[i],q[tail],q[tail-1])<=0) tail--;
		q[++tail]=a[i];
 }
	cout<<tail-1;
 return 0;
} 
