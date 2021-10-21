#include<bits/stdc++.h>
using namespace std;
 
const int N=100100;
typedef long long ll;
struct point{
	ll x,y;
	point(ll x=0,ll y=0):x(x),y(y){}
	point operator - (const point&a)const{return point(x-a.x,y-a.y);}
 bool operator < (const point&a)const{
 if(x!=a.x)return x<a.x;
 return y<a.y;
 }
	ll operator * (const point&a)const{return x*a.y-y*a.x;}
}a[N],b[N];
int n,ans;
 
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
 for(int i=1;i<=n;++i){
		cin>>a[i].x>>a[i].y;a[i].y-=a[i].x*a[i].x;
 }
	sort(a+1,a+n+1);
 int ans=0;
 for(int i=1;i<=n;++i){
 for(;ans&&b[ans].x==a[i].x;--ans);
 for(;ans>1&&(a[i]-b[ans-1])*(b[ans]-b[ans-1])<=0;--ans);
		b[++ans]=a[i];
 }
	cout<<ans-1<<'\n';
 return 0;
}
 
